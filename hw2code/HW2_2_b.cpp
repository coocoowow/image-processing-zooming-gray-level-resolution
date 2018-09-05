#define _CRT_SECURE_NO_DEPRECATE //去除fopen報警告
#include <stdio.h> 
#include <cv.h> 
#include <highgui.h> 
#include <iostream>
#include <fstream>
#include <string>
using namespace cv;
using namespace std;
# define size 256*256
# define newsize 576*576


void HW2_2_b(void)
{unsigned char *lenai,*baboon;
char FileNameOri[]="lena256.raw";
char FileNamebaboon[]="baboon_256.raw";
lenai = new unsigned char[size]; 
baboon =new unsigned char[size];
CvMat *lenamat = cvCreateMat(256,256, CV_8UC1);
CvMat *baboonmat = cvCreateMat(256,256, CV_8UC1);
FILE *lena;
	lena = fopen(FileNameOri,"rb");
FILE *baboon256;
	baboon256 = fopen(FileNamebaboon,"rb");

		fread(lenai,1,size,lena);
		cvSetData(lenamat,lenai,lenamat->step);


		fread(baboon,1,size,baboon256);
		cvSetData(baboonmat,baboon,baboonmat->step);


cv::Mat dst;
dst = Mat(lenamat->rows,lenamat ->cols,lenamat->type,lenamat->data.fl);//轉換格式
cv::Mat baboondst;
baboondst = Mat(baboonmat->rows,baboonmat ->cols,baboonmat->type,baboonmat->data.fl);//轉換格式
int colss=256;
int rowss=256;
Mat new_image_lena8;
new_image_lena8.create(rowss,colss,CV_8U);
Mat new_image_lena7;
new_image_lena7.create(rowss,colss,CV_8U);
Mat new_image_lena6;
new_image_lena6.create(rowss,colss,CV_8U);
Mat new_image_lena5;
new_image_lena5.create(rowss,colss,CV_8U);
Mat new_image_lena4;
new_image_lena4.create(rowss,colss,CV_8U);
Mat new_image_lena3;
new_image_lena3.create(rowss,colss,CV_8U);
Mat new_image_lena2;
new_image_lena2.create(rowss,colss,CV_8U);
Mat new_image_lena1;
new_image_lena1.create(rowss,colss,CV_8U);
Mat new_image_baboon8;
new_image_baboon8.create(rowss,colss,CV_8U);
Mat new_image_baboon7;
new_image_baboon7.create(rowss,colss,CV_8U);
Mat new_image_baboon6;
new_image_baboon6.create(rowss,colss,CV_8U);
Mat new_image_baboon5;
new_image_baboon5.create(rowss,colss,CV_8U);
Mat new_image_baboon4;
new_image_baboon4.create(rowss,colss,CV_8U);
Mat new_image_baboon3;
new_image_baboon3.create(rowss,colss,CV_8U);
Mat new_image_baboon2;
new_image_baboon2.create(rowss,colss,CV_8U);
Mat new_image_baboon1;
new_image_baboon1.create(rowss,colss,CV_8U);
int value=0;
int value_shift=0;
int valuebaboon=0;
int valuebaboon_shift=0;
double errorlena8=0,sumlena8=0,mselena8=0;
double errorbaboon8=0,sumbaboon8=0,msebaboon8=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		new_image_lena1.at<uchar>(y,x)=(dst.at<uchar>(y,x)&1)/1*255;
		new_image_lena2.at<uchar>(y,x)=(dst.at<uchar>(y,x)&2)/2*255;
		new_image_lena3.at<uchar>(y,x)=(dst.at<uchar>(y,x)&4)/4*255;
		new_image_lena4.at<uchar>(y,x)=(dst.at<uchar>(y,x)&8)/8*255;
		new_image_lena5.at<uchar>(y,x)=(dst.at<uchar>(y,x)&16)/16*255;
		new_image_lena6.at<uchar>(y,x)=(dst.at<uchar>(y,x)&32)/32*255;
		new_image_lena7.at<uchar>(y,x)=(dst.at<uchar>(y,x)&64)/64*255;
		new_image_lena8.at<uchar>(y,x)=(dst.at<uchar>(y,x)&128)/128*255;
		////////////////////////////////////////////

		new_image_baboon1.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&1)/1*255;
		new_image_baboon2.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&2)/2*255;
		new_image_baboon3.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&4)/4*255;
		new_image_baboon4.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&8)/8*255;
		new_image_baboon5.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&16)/16*255;
		new_image_baboon6.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&32)/32*255;
		new_image_baboon7.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&64)/64*255;
		new_image_baboon8.at<uchar>(y,x)=(baboondst.at<uchar>(y,x)&128)/128*255;
	}

}


imshow("HW2_2_b8",new_image_lena8);
imshow("HW2_2_b7",new_image_lena7);
imshow("HW2_2_b6",new_image_lena6);
imshow("HW2_2_b5",new_image_lena5);
imshow("HW2_2_b4",new_image_lena4);
imshow("HW2_2_b3",new_image_lena3);
imshow("HW2_2_b2",new_image_lena2);
imshow("HW2_2_b1",new_image_lena1);
imshow("HW2_2_b8baboon",new_image_baboon8);
imshow("HW2_2_b7baboon",new_image_baboon7);
imshow("HW2_2_b6baboon",new_image_baboon6);
imshow("HW2_2_b5baboon",new_image_baboon5);
imshow("HW2_2_b4baboon",new_image_baboon4);
imshow("HW2_2_b3baboon",new_image_baboon3);
imshow("HW2_2_b2baboon",new_image_baboon2);
imshow("HW2_2_b1baboon",new_image_baboon1);


cvWaitKey(0);

	fclose(lena);
	
	delete lenai;
}