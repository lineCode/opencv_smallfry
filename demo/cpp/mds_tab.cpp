#include "opencv2/opencv.hpp"
using namespace cv;

uchar cyclic_[] = {137,201,0,152,171,44,142,169,46,160,150,77,133,170,44,148,145,77,137,138,74,141,156,114,128,175,39,138,142,74,128,141,75,135,150,111,
	118,142,73,125,144,111,115,139,111,125,142,140,128,177,36,137,146,70,128,145,73,135,144,105,119,146,71,126,136,105,118,130,105,125,136,136,110,
	149,67,119,129,101,114,124,102,121,130,135,106,119,100,113,124,136,103,120,138,119,83,136,132,176,33,143,153,66,133,152,69,141,142,98,121,153,67,
	133,134,99,126,128,100,131,134,130,118,152,66,129,126,97,122,122,99,127,126,131,113,117,95,119,121,132,110,117,134,122,91,139,115,153,66,130,122,
	90,122,119,92,128,123,129,113,119,92,119,116,129,112,109,129,122,96,143,104,124,94,111,109,127,106,102,128,116,97,149,97,95,126,106,97,155,98,95,
	162,106,68,164,139,175,33,148,158,60,136,160,63,149,143,92,130,155,64,142,135,94,137,129,94,140,136,125,126,153,65,136,128,91,129,123,92,134,128,126,120,121,90,128,122,127,119,115,127,131,97,139,126,152,67,137,125,87,128,124,89,136,122,123,120,127,92,128,115,123,123,107,123,128,102,143,
	113,130,97,125,107,121,116,100,120,123,104,149,105,102,123,115,102,157,107,100,162,116,74,167,129,161,73,144,129,86,135,133,91,147,117,121,124,
	134,97,138,110,120,132,100,118,136,105,147,118,138,101,132,105,118,123,105,120,128,106,155,112,106,123,120,105,161,111,104,165,121,81,174,115,146,
	106,134,104,115,122,107,120,131,109,161,110,112,126,120,108,164,110,103,162,120,87,182,103,118,131,110,106,161,106,98,156,115,88,189,99,91,156,
	107,87,195,99,85,199,108,67,212,148,176,33,154,162,53,145,160,57,157,143,86,139,157,60,149,136,87,142,128,86,149,140,123,135,153,62,142,128,83,
	133,126,85,143,132,123,125,127,85,136,126,124,126,112,118,142,100,142,136,151,65,141,130,81,133,132,85,144,125,119,125,132,90,135,117,119,129,108,
	116,136,106,146,117,136,96,130,104,112,120,109,115,129,110,153,109,110,119,117,111,159,108,110,163,127,76,171,146,155,71,148,138,85,139,139,90,
	154,122,117,131,139,96,145,112,115,134,111,115,142,112,150,124,142,100,134,115,115,126,114,117,133,113,156,117,114,123,124,113,161,115,111,162,
	129,85,177,123,149,106,136,117,117,127,118,121,133,115,160,118,120,126,124,112,158,116,106,154,126,91,183,111,124,130,115,108,153,113,102,151,120,
	92,189,106,96,151,113,92,194,104,88,191,115,69,213,158,159,72,156,146,84,147,146,90,165,123,113,137,146,95,152,122,112,143,118,113,150,118,153,
	131,149,99,143,121,113,134,120,116,141,119,158,123,122,121,132,117,157,125,114,155,138,89,183,131,154,106,143,127,116,133,125,119,141,117,154,124,
	127,122,132,112,148,125,107,147,133,94,188,118,131,127,128,108,146,121,104,145,127,97,191,113,99,144,118,95,185,110,92,183,121,70,216,136,161,110,
	150,134,117,138,133,120,150,115,147,127,134,124,140,110,143,134,105,142,139,99,191,121,136,125,134,105,138,126,103,138,132,98,184,119,98,138,124,
	96,178,116,94,177,125,70,218,119,144,128,140,100,134,129,98,134,136,96,178,118,94,133,126,94,172,117,89,168,124,73,216,110,89,130,123,84,165,110,
	83,161,120,75,210,102,76,159,111,75,206,101,74,205,119,47,255};

uchar regular_[] = {123,175,0,160,169,62,149,168,56,160,162,117,139,167,47,152,159,110,138,162,106,163,137,155,132,166,39,145,159,101,133,159,96,156,135,
	149,123,159,89,150,133,142,133,141,140,166,105,183,127,167,31,146,157,90,134,156,85,149,139,141,125,156,78,142,137,135,131,139,130,159,107,178,
	118,157,71,135,140,128,125,138,121,153,105,170,116,139,115,147,101,161,140,95,152,157,89,213,124,170,24,149,157,81,138,156,76,151,141,132,128,156,
	69,144,138,126,134,139,121,156,114,172,122,156,61,139,139,117,129,137,112,148,113,165,120,138,106,142,109,157,136,104,148,152,91,206,118,157,54,
	143,134,106,130,135,102,142,121,160,120,135,96,136,116,151,129,111,143,147,92,199,113,134,88,126,120,146,121,113,136,142,91,191,110,113,131,135,
	87,181,126,82,173,150,75,234,123,172,16,152,161,74,141,159,69,155,146,125,132,159,62,147,142,119,137,145,114,158,119,164,126,159,54,142,142,110,
	132,142,105,150,118,158,122,143,99,144,115,150,138,110,141,153,99,200,122,159,46,144,140,99,132,139,95,144,124,151,124,140,88,138,120,144,131,117,
	137,147,99,193,117,139,81,132,121,137,124,119,129,141,99,185,114,119,124,135,95,176,127,90,168,147,79,228,117,162,39,148,139,91,136,139,86,149,124,142,126,139,80,141,120,135,133,118,128,143,108,189,120,139,72,136,119,126,126,120,121,137,106,180,117,120,115,131,102,172,124,98,163,144,
	82,221,116,137,63,139,114,115,127,116,111,130,114,175,117,117,105,125,109,166,119,104,157,139,84,213,111,114,97,117,111,160,112,105,150,133,84,
	205,104,103,144,126,80,195,118,75,187,149,68,248,123,174,8,155,166,68,145,164,62,158,154,121,135,164,55,150,151,114,138,154,110,162,126,158,129,
	163,47,144,150,105,133,150,100,154,125,152,123,151,94,148,121,144,144,115,135,159,102,192,124,163,39,145,148,95,134,147,90,148,130,145,125,147,83,
	141,127,138,133,127,133,152,103,185,118,147,75,136,128,131,126,127,125,146,102,177,116,128,119,140,98,169,133,93,160,149,86,221,121,166,31,148,
	148,86,137,147,81,151,130,136,128,148,74,143,128,130,135,127,124,149,111,180,122,147,66,139,128,121,129,128,116,142,109,172,120,128,110,136,106,
	164,129,101,156,145,88,214,117,147,58,141,123,110,130,125,106,136,116,167,120,125,100,131,111,158,124,107,150,141,90,206,114,123,92,123,113,152,
	118,109,143,135,89,199,109,107,137,129,86,189,121,81,182,147,71,241,120,168,23,153,151,78,141,150,73,158,134,129,131,150,66,149,132,123,140,129,
	116,151,118,174,125,150,58,144,131,113,131,132,108,144,115,166,120,133,102,138,110,157,132,104,148,146,96,209,120,150,50,144,129,102,132,129,98,
	138,122,160,123,130,92,133,116,151,126,112,143,141,97,201,117,128,84,125,118,145,120,114,136,136,96,193,111,113,130,129,93,184,121,88,176,145,75,
	235,114,152,43,148,128,94,136,128,89,137,129,155,126,129,83,134,119,144,128,110,133,137,106,197,119,128,75,124,119,136,121,113,126,132,105,189,
	112,113,120,125,101,179,118,95,171,142,78,228,115,125,67,135,104,119,122,108,115,125,112,184,111,110,110,119,107,173,112,101,164,137,80,220,105,
	108,103,111,109,166,106,102,156,130,79,211,98,99,150,123,73,200,114,68,191,152,63,255};



Mat lbp(const Mat &I) {
    Mat_<uchar> feature(I.size(),0);
    Mat_<uchar> img(I);
    const int m=1;
    for (int r=m; r<img.rows-m; r++) {
        for (int c=m; c<img.cols-m; c++) {
            uchar v = 0;
            uchar cen = img(r,c);
            v |= (img(r-1,c  ) > cen) << 0;
            v |= (img(r-1,c+1) > cen) << 1;
            v |= (img(r  ,c+1) > cen) << 2;
            v |= (img(r+1,c+1) > cen) << 3;
            v |= (img(r+1,c  ) > cen) << 4;
            v |= (img(r+1,c-1) > cen) << 5;
            v |= (img(r  ,c-1) > cen) << 6;
            v |= (img(r-1,c-1) > cen) << 7;
            feature(r,c) = v;
        }
    }
    return feature;
}

Mat lut(const Mat &img, const Mat &table) {
	const uchar *input  = img.ptr<uchar>();
	const Vec3b *lookup = table.ptr<Vec3b>();
	Mat res(img.size(),CV_8UC3);
	Vec3b *output = res.ptr<Vec3b>();
	for (size_t i=0; i<img.total(); i++)
		output[i] = lookup[input[i]];
	return res;
}

int main() {
	Mat lookup(256,1,CV_8UC3,regular_);
	cvtColor(lookup,lookup,COLOR_BGR2LAB);
	Mat face = imread("../face.png", 0);
	Mat fea = lbp(face);
	Mat col = lut(fea, lookup);
	imshow("face",face);
	imshow("fea",fea);
	imshow("col",col);
	waitKey();
	return 0;
}