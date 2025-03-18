#include<opencv2/opencv.hpp>

void prob1(IplImage* src);
void prob2(IplImage* src);
void prob3(IplImage* src);

int main() {
	IplImage* src = cvLoadImage("c:\\temp\\sejong_small.jpg");
	prob1(src);
	prob2(src);
	prob3(src);
	cvShowImage("src", src);
	cvWaitKey();

	return 0;
}

void prob1(IplImage* src) {
	IplImage* tar = cvCreateImage(cvGetSize(src), 8, 3);
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			cvSet2D(tar, tar->height - y - 1, tar->width - x - 1, ref);
		}
	}
	//cvShowImage("prob-1", tar);
}

void prob2(IplImage* src) {
	IplImage* tar = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			if (x < src->width / 2) {
				cvSet2D(tar, y, src->width / 2 + x, ref);
			}
			else {
				cvSet2D(tar, y, x - src->width / 2, ref);
			}
		}
	}
	//cvShowImage("prob-1", tar);
}

void prob3(IplImage* src) {
	IplImage* tar = cvCreateImage(cvGetSize(src), 8, 3);
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			// greyscale
			CvScalar grey;
			int bri = (ref.val[0] + ref.val[1] + ref.val[2]) / 3;
			for (int k = 0; k < 3; k++)
				grey.val[k] = bri;
			cvSet2D(tar, y, x, grey);
		}
	}

	float lean = (float)(src->width / 2) / (src->height / 2);
	int cp = 0;
	bool isCrossed = false;
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			
			if (isCrossed) continue;
			
		}
	}

	cvShowImage("prob-3", tar);
}
