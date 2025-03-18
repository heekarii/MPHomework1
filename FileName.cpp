#include<opencv2/opencv.hpp>

int main() {
	IplImage* src = cvLoadImage("c:\\temp\\sejong_small.jpg");

	IplImage* rev = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* half = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* sqa = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* grc = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* blc = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* bch = cvCreateImage(cvGetSize(src), 8, 3);

	// 1번 이미지
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			cvSet2D(rev, rev->height - y - 1, rev->width - x - 1, ref);
		}
	}

	// 2번 이미지
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			if (x < src->width / 2) {
				cvSet2D(half, y, src->width / 2 + x, ref);
			}
			else {
				cvSet2D(half, y, x - src->width / 2, ref);
			}
		}
	}

	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);

			// greyscale
			CvScalar grey;
			int bri = (ref.val[0] + ref.val[1] + ref.val[2]) / 3;
			for (int k = 0; k < 3; k++)
				grey.val[k] = bri;

			

		}
	}

	cvShowImage("src", src);
	cvShowImage("reverse", sqa);
	cvWaitKey();

	return 0;
}