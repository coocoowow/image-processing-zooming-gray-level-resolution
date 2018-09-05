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


void HW2_2_a(void)
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
		value=dst.at<uchar>(y,x);
		value_shift= value;
		value_shift=value_shift;
		new_image_lena8.at<uchar>(y,x)=value_shift;
		errorlena8=value-value_shift;
		sumlena8=sumlena8+errorlena8*errorlena8;
		////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon;
		valuebaboon_shift=valuebaboon_shift;
		new_image_baboon8.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon8=valuebaboon-valuebaboon_shift;
		sumbaboon8=sumbaboon8+errorbaboon8*errorbaboon8;
	}

}
mselena8=sumlena8/(256*256);
msebaboon8=sumbaboon8/(256*256);
printf("\n8bit lena MSE= %.3f", mselena8);
printf("\n8bit baboon MSE= %.3f", msebaboon8);

///////////////////////////////////////////////////////////

double errorlena7=0,sumlena7=0,mselena7=0;
double errorbaboon7=0,sumbaboon7=0,msebaboon7=0;

for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>1;
		value_shift=value_shift<<1;
		new_image_lena7.at<uchar>(y,x)=value_shift;
		errorlena7=value-value_shift;
		sumlena7=sumlena7+errorlena7*errorlena7;
				////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>1;
		valuebaboon_shift=valuebaboon_shift<<1;
		new_image_baboon7.at<uchar>(y,x)=valuebaboon_shift;
			errorbaboon7=valuebaboon-valuebaboon_shift;
		sumbaboon7=sumbaboon7+errorbaboon7*errorbaboon7;
	}

}
mselena7=sumlena7/(256*256);
msebaboon7=sumbaboon7/(256*256);
printf("\n7bit lena MSE= %.3f", mselena7);
printf("\n7bit baboon MSE= %.3f", msebaboon7);
//////////////////////////////////////////////////////////////
double errorlena6=0,sumlena6=0,mselena6=0;
double errorbaboon6=0,sumbaboon6=0,msebaboon6=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>2;
		value_shift=value_shift<<2;
		new_image_lena6.at<uchar>(y,x)=value_shift;
		errorlena6=value-value_shift;
		sumlena6=sumlena6+errorlena6*errorlena6;
				////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>2;
		valuebaboon_shift=valuebaboon_shift<<2;
		new_image_baboon6.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon6=valuebaboon-valuebaboon_shift;
		sumbaboon6=sumbaboon6+errorbaboon6*errorbaboon6;
	}

}
mselena6=sumlena6/(256*256);
msebaboon6=sumbaboon6/(256*256);
printf("\n6bit lena MSE= %.3f", mselena6);
printf("\n6bit baboon MSE= %.3f", msebaboon6);
///////////////////////////////////////////////////////////
double errorlena5=0,sumlena5=0,mselena5=0;
double errorbaboon5=0,sumbaboon5=0,msebaboon5=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>3;
		value_shift=value_shift<<3;
		new_image_lena5.at<uchar>(y,x)=value_shift;
		errorlena5=value-value_shift;
		sumlena5=sumlena5+errorlena5*errorlena5;
						////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>3;
		valuebaboon_shift=valuebaboon_shift<<3;
		new_image_baboon5.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon5=valuebaboon-valuebaboon_shift;
		sumbaboon5=sumbaboon5+errorbaboon5*errorbaboon5;

	}

}

mselena5=sumlena5/(256*256);
msebaboon5=sumbaboon5/(256*256);
printf("\n5bit lena MSE= %.3f", mselena5);
printf("\n5bit baboon MSE= %.3f", msebaboon5);


///////////////////////////////////////////////////////////
double errorlena4=0,sumlena4=0,mselena4=0;
double errorbaboon4=0,sumbaboon4=0,msebaboon4=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>4;
		value_shift=value_shift<<4;
		new_image_lena4.at<uchar>(y,x)=value_shift;
		errorlena4=value-value_shift;
		sumlena4=sumlena4+errorlena4*errorlena4;
						////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>4;
		valuebaboon_shift=valuebaboon_shift<<4;
		new_image_baboon4.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon4=valuebaboon-valuebaboon_shift;
		sumbaboon4=sumbaboon4+errorbaboon4*errorbaboon4;
	}

}
mselena4=sumlena4/(256*256);
msebaboon4=sumbaboon4/(256*256);
printf("\n4bit lena MSE= %.3f", mselena4);
printf("\n4bit baboon MSE= %.3f", msebaboon4);

/////////////////////////////////////////////
double errorlena3=0,sumlena3=0,mselena3=0;
double errorbaboon3=0,sumbaboon3=0,msebaboon3=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>5;
		value_shift=value_shift<<5;
		new_image_lena3.at<uchar>(y,x)=value_shift;
		errorlena3=value-value_shift;
		sumlena3=sumlena3+errorlena3*errorlena3;
						////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>5;
		valuebaboon_shift=valuebaboon_shift<<5;
		new_image_baboon3.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon3=valuebaboon-valuebaboon_shift;
		sumbaboon3=sumbaboon3+errorbaboon3*errorbaboon3;
	}

}
mselena3=sumlena3/(256*256);
msebaboon3=sumbaboon3/(256*256);
printf("\n3bit lena MSE= %.3f", mselena3);
printf("\n3bit baboon MSE= %.3f", msebaboon3);
////////////////////////////////////////////////////////
double errorlena2=0,sumlena2=0,mselena2=0;
double errorbaboon2=0,sumbaboon2=0,msebaboon2=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>6;
		value_shift=value_shift<<6;
		new_image_lena2.at<uchar>(y,x)=value_shift;
			errorlena2=value-value_shift;
		sumlena2=sumlena2+errorlena2*errorlena2;
						////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>6;
		valuebaboon_shift=valuebaboon_shift<<6;
		new_image_baboon2.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon2=valuebaboon-valuebaboon_shift;
		sumbaboon2=sumbaboon2+errorbaboon2*errorbaboon2;
	}

}
mselena2=sumlena2/(256*256);
msebaboon2=sumbaboon2/(256*256);
printf("\n2bit lena MSE= %.3f", mselena2);
printf("\n2bit baboon MSE= %.3f", msebaboon2);

///////////////////////////////////////////////////////////
double errorlena1=0,sumlena1=0,mselena1=0;
double errorbaboon1=0,sumbaboon1=0,msebaboon1=0;
for(int y=0;y<rowss-1;y++)
{
	for(int x=0;x<colss-1;x++)
	{
		value=dst.at<uchar>(y,x);
		value_shift= value>>7;
		value_shift=value_shift<<7;
		new_image_lena1.at<uchar>(y,x)=value_shift;
			errorlena1=value-value_shift;
		sumlena1=sumlena1+errorlena1*errorlena1;
						////////////////////////////////////////////
		valuebaboon=baboondst.at<uchar>(y,x);
		valuebaboon_shift= valuebaboon>>7;
		valuebaboon_shift=valuebaboon_shift<<7;
		new_image_baboon1.at<uchar>(y,x)=valuebaboon_shift;
		errorbaboon1=valuebaboon-valuebaboon_shift;
		sumbaboon1=sumbaboon1+errorbaboon1*errorbaboon1;
	}

}
mselena1=sumlena1/(256*256);
msebaboon1=sumbaboon1/(256*256);
printf("\n1bit lena MSE= %.3f", mselena1);
printf("\n1bit baboon MSE= %.3f", msebaboon1);



imshow("HW2_2_a8",new_image_lena8);
imshow("HW2_2_a7",new_image_lena7);
imshow("HW2_2_a6",new_image_lena6);
imshow("HW2_2_a5",new_image_lena5);
imshow("HW2_2_a4",new_image_lena4);
imshow("HW2_2_a3",new_image_lena3);
imshow("HW2_2_a2",new_image_lena2);
imshow("HW2_2_a1",new_image_lena1);
imshow("HW2_2_a8baboon",new_image_baboon8);
imshow("HW2_2_a7baboon",new_image_baboon7);
imshow("HW2_2_a6baboon",new_image_baboon6);
imshow("HW2_2_a5baboon",new_image_baboon5);
imshow("HW2_2_a4baboon",new_image_baboon4);
imshow("HW2_2_a3baboon",new_image_baboon3);
imshow("HW2_2_a2baboon",new_image_baboon2);
imshow("HW2_2_a1baboon",new_image_baboon1);


cvWaitKey(0);

	fclose(lena);
	
	delete lenai;
}