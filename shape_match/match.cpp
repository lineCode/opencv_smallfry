#include <opencv2/opencv.hpp>
#include "matching.h"

using namespace cv;
using namespace std;

typedef double Distance(const vector<Point> &, const vector<Point> &);

int main(int argc, char **argv) {
	String match = argc>1 ? argv[1] : "sampson";
	String scene = argc>2 ? argv[2] : "scene1.png";
	int sizeThresh = argc>3 ? atoi(argv[3]) : 200;

	Distance *distance;
	Ptr<matching::Matcher> matcher;
	if (match == "hausdorff") { matcher = hausdorff::createMatcher();distance = &hausdorff::distance; }
	if (match == "sampson")   { matcher = sampson::createMatcher();  distance = &sampson::distance; }
	if (match == "fourier")   { matcher = fourier::createMatcher();  distance = &fourier::distance; }
	if (match == "onedollar") { matcher = onedollar::createMatcher();distance = &onedollar::distance; }

	Mat m1,m2,mc;
	Mat m = imread(scene, IMREAD_GRAYSCALE);
	cvtColor(m/8, mc, COLOR_GRAY2BGR); // for drawing
	bitwise_not(m, m1);
	blur(m1,m1,Size(6,6));
	threshold(m1, m2, 5, 255, THRESH_BINARY);

	vector<vector<Point> > raw_contours, contours;
	findContours(m2, raw_contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	// filter for size
	for (int i=0; i<raw_contours.size(); i++)
	{
	    if (raw_contours[i].size() >= 200 )
	    {
	        contours.push_back(raw_contours[i]);
	        drawContours(mc, raw_contours, i, Scalar(128,128,128), 2);
	    }
	}
	cerr << contours.size() << " filtered contours." << endl;

	size_t N = contours.size();
	Mat_<double> confusion(N,N,0.0);
	for (size_t i=0; i<N; i++) {
		for (size_t j=0; j<N; j++) {
			confusion(i, j) = distance(contours[i], contours[j]);
		}
    }
    cerr << match << endl;
    cerr << confusion << endl;
    /*
	int  ca=3, cb=2;
	double d = distance(contours[ca], contours[cb]);
    cout <<"Self Distance for contour " << ca << " and " << ca << " is " << distance(contours[ca], contours[ca]) << endl;
    cout <<"Self Distance for contour " << cb << " and " << cb << " is " << distance(contours[cb], contours[cb]) << endl;
    drawContours(mc, contours, ca, Scalar(0,0,255), 2);
    drawContours(mc, contours, cb, Scalar(0,255,0), 2);
    cout <<"Distance between contour " << ca << " and " << cb << " is " << d << " " << endl;
    */
	/*
	//vector<Point> rec = fourier::reconstruct(contours[cb],alpha,-phi,s); // a from b
	vector<Point> rec = fourier::reconstruct(contours[ca], alpha, phi, s); // b from a
    int last = contours.size();
    contours.push_back(rec);
    drawContours(mc, contours, last, Scalar(255,0,0), 2, LINE_AA, noArray(), INT_MAX, Point(120,120));
    */

	imshow("mc ",mc);
	waitKey();

    return 0;
}