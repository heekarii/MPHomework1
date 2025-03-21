#include<opencv2/opencv.hpp>

void prob1(IplImage* src);
void prob2(IplImage* src);
void prob3(IplImage* src);
void prob4(IplImage* src);
void prob5(IplImage* src);
void prob6(IplImage* src);

int main() {
	IplImage* src = cvLoadImage("c:\\temp\\sejong_small.jpg");
	/*prob1(src);
	prob2(src);
	prob3(src);
	prob4(src);
	prob5(src);
	*/
	prob6(src);
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
	cvShowImage("prob-2", tar);
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
	cvShowImage("prob-1", tar);
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
			// normalized coordinate
			float dx = 2 * (float)x / src->width - 1; 
			float dy = 2 * (float)y / src->height - 1;
			dx = abs(dx);
			dy = abs(dy);
			// 중심부터 거리 1 이상이면 흑백
			if (dx + dy > 1) cvSet2D(tar, y, x, grey);
			else cvSet2D(tar, y, x, ref);
		}
	}
	cvShowImage("prob-3", tar);
}

void prob4(IplImage* src) {
	IplImage* tar = cvCreateImage(cvGetSize(src), 8, 3);
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			// greyscale
			CvScalar grey;
			int bri	= (ref.val[0] + ref.val[1] + ref.val[2]) / 3;
			for (int k = 0; k < 3; k++)
				grey.val[k] = bri;
			// normalized coordinate
			float dx = 2 * (float)x / src->width - 1;
			float dy = 2 * (float)y / src->height - 1;
			dx = abs(dx);
			dy = abs(dy);
			// 중심부터 거리 1 이상이면 흑백
			if (sqrt(dx * dx + dy * dy) > 1) cvSet2D(tar, y, x, grey);
			else cvSet2D(tar, y, x, ref);
		}
	}
	cvShowImage("prob-4", tar);
}

void prob5(IplImage* src) {
	IplImage* tar = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			float dx = 2 * (float)x / (src->width - 1);
			float dy = 2 * (float)y / (src->height - 1);

			
			float dist = sqrt(dx * dx + dy * dy);

			if ((int)(dist * 10) % 2 == 0) {
				cvSet2D(tar, y, x, ref);
			}
			else {
				cvSet2D(tar, y, x, cvScalar(0, 0, 0));
			}
		}
	}
	cvShowImage("prob-5", tar);
}

void prob6(IplImage* src) {
	IplImage* tar = cvCreateImage(cvGetSize(src), 8, 3);
	
	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar ref = cvGet2D(src, y, x);
			float dx = (float)x / (src->width - 1);
			float dy = (float)y / (src->height - 1);

			if ((int)(dx * 10) % 2 == 0 && (int)(dy * 10) % 2 != 0 || (int)(dx * 10) % 2 != 0 && (int)(dy * 10) % 2 == 0) {
				cvSet2D(tar, y, x, ref);
			}
			else {
				cvSet2D(tar, y, x, cvScalar(0, 0, 0));
			}
			
		}
	}

	cvShowImage("prob-6", tar);
}
