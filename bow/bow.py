import cv2
import numpy as np

#
# based on :
#  http://gilscvblog.wordpress.com/2013/08/23/bag-of-words-models-for-visual-categorization/
#
# for this sample, we'll use the left/right checkerboard shots from samples/cpp.
#  admittedly, there's not much sense in training an svm on left vs right checkerboards,
#  but it shows the general flow nicely.
#
# since this is using SIFT, you will need the https://github.com/Itseez/opencv_contrib repo
#
# please modify !
datapath="c:/p/opencv/samples/data"
def path(cls,i): # "./left03.jpg"
	return "%s/%s%02d.jpg"  % (datapath,cls,i+1)


detect = cv2.xfeatures2d.SIFT_create()
extract = cv2.xfeatures2d.SIFT_create()

flann_params = dict(algorithm = 1, trees = 5)      # flann enums are missing, FLANN_INDEX_KDTREE=1
matcher = cv2.FlannBasedMatcher(flann_params, {})  # need to pass empty dict (#1329)


## 1.a setup BOW
bow_train   = cv2.BOWKMeansTrainer(8) # toy world, you want more.
bow_extract = cv2.BOWImgDescriptorExtractor( extract, matcher )

## try those, please!
#help(bow_train)
#help(bow_extract)

## 1.b add positives and negatives to the bowtrainer, use SIFT DescriptorExtractor
def feature_sift(fn):
	im = cv2.imread(fn,0)
	return extract.compute(im, detect.detect(im))[1]

for i in range(8):
	bow_train.add(feature_sift(path("left", i)))
	bow_train.add(feature_sift(path("right",i)))


## 1.c kmeans cluster descriptors to vocabulary
voc = bow_train.cluster()
bow_extract.setVocabulary( voc )
print("bow vocab", np.shape(voc))

## 2.a gather svm training data, use BOWImgDescriptorExtractor
def feature_bow(fn):
	im = cv2.imread(fn,0)
	return bow_extract.compute(im, detect.detect(im))

traindata, trainlabels = [],[]
for i in range(6): # save first 2 for testing
	traindata.extend(feature_bow(path("left", i+2))); trainlabels.append(-1)
	traindata.extend(feature_bow(path("right",i+2))); trainlabels.append(1)

print("svm items", len(traindata), len(traindata[0]))

## 2.b create & train the svm
svm = cv2.ml.SVM_create()
svm.train(np.array(traindata), cv2.ml.ROW_SAMPLE, np.array(trainlabels))

## 2.c predict the remaining 2*2 images, use BOWImgDescriptorExtractor again
def predict(fn):
	f = feature_bow(fn);
	p = svm.predict(f)
	print(fn, "\t", p[1][0][0])

for i in range(2): #  testing
	predict( path("left",i) )
	predict( path("right",i) )


"""
bow vocab (8, 128)
svm items 12 8
e:/code/opencv/samples/cpp/left01.jpg   -1.0
e:/code/opencv/samples/cpp/right01.jpg  1.0
e:/code/opencv/samples/cpp/left02.jpg   -1.0
e:/code/opencv/samples/cpp/right02.jpg  1.0
"""
