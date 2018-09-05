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
# define newsize 200*200

void HW2_1_b(void)
{unsigned char *lenai;
char FileNameOri[]="lena256.raw";
char FileName2NNI[]="2_1_b_NNI.raw";
char FileNamebil[]="2_1_b_bil.raw";
char FileNamebic[]="2_1_b_bic.raw";
lenai = new unsigned char[size]; 
CvMat *lenamat = cvCreateMat(256,256, CV_8UC1);

FILE *lena;
	lena = fopen(FileNameOri,"rb");
FILE *lenaNNI;
	lenaNNI = fopen(FileName2NNI,"wb");
FILE *lenabil;
	lenabil = fopen(FileNamebil,"wb");
FILE *lenabic;
	lenabic = fopen(FileNamebic,"wb");

	if(lena==NULL)
	{
		puts("Loading File Error!");
	}
	else
	{
		fread(lenai,1,size,lena);
		cvSetData(lenamat,lenai,lenamat->step);

cv::Mat dst;
dst = Mat(lenamat->rows,lenamat ->cols,lenamat->type,lenamat->data.fl);//轉換格式

int colss=256;
int rowss=256;
double sf=1/1.28;
double rowsa=rowss*sf;
double colsa=colss*sf;
double newx=0;
double newy=0;
Mat new_image_NNI;
new_image_NNI.create(rowsa,colsa,CV_8U);
Mat new_image_bil;
new_image_bil.create(rowsa,colsa,CV_8U);
Mat new_image_bic;
new_image_bic.create(rowsa,colsa,CV_8U);


for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{newx=(x/sf)+0.5;
	newy=(y/sf)+0.5;
	
	if(newx>=colss-1)
		newx--;
	if(newy>=rowss-1)
		newy--;
	new_image_NNI.at<uchar>(y,x)=dst.at<uchar>(newy,newx);
	}

}
//////////////////////////////////////////////////////////////////////////////////////
double pa,pb,pc,pd,output;
	double newxa=0,newya=0;
	double newxb=0,newyb=0;
	double newxc=0,newyc=0;
	double newxd=0,newyd=0;
	double alpha=0,beta=0;



for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{
		newxa=x/sf;
		newya=y/sf;
		newxb=newxa+1;
		newyb=newya;
		newxc=newxa;
		newyc=newya+1;
		newxd=newxa+1;
		newyd=newya+1;
		
		if(newxb>=colss-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxb--;
		if(newxd>=colss-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxd--;
		if(newyc>=rowss-1)
			newyc--;
		if(newyd>=rowss-1)
			newyd--;
		alpha=x/sf-newxa;
		beta=y/sf-newya;
		pa=dst.at<uchar>(newya,newxa);
		pb=dst.at<uchar>(newyb,newxb);
		pc=dst.at<uchar>(newyc,newxc);
		pd=dst.at<uchar>(newyd,newxd);
		output = (1-alpha)*(1-beta)*pa+alpha*(1-beta)*pb+(1-alpha)*beta*pc+alpha*beta*pd;
		new_image_bil.at<uchar>(y,x) = output;
	}
}
////////////////////////////////////////////////////////////////////////////

double bicx=0;
double bicy=0;
double bicx1=0;
double bicx2=0;
double bicx_1=0;
double bicy1=0;
double bicy2=0;
double bicy_1=0;

for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{double x_ture=0;
	double y_ture=0;
	x_ture=x/sf;
	y_ture=y/sf;

		bicx=(x/sf)+0.5;
		bicy=(y/sf)+0.5;
		bicx1=bicx+1;
		bicx2=bicx+2;
		bicx_1=bicx-1;
		bicy1=bicy+1;
		bicy2=bicy+2;
		bicy_1=bicy-1;
		if(bicx>colss-1)
			bicx=255;
		if(bicx1>colss-1)
			bicx1=255;
		if(bicx2>colss-1)
			bicx2=255;
		if(bicx_1<0)
			bicx_1=0;
		if(bicy>rowss-1)
			bicy=255;
		if(bicy1>rowss-1)
			bicy1=255;
		if(bicy2>rowss-1)
			bicy2=255;
		if(bicy_1<0)
			bicy_1=0;
		double a=0;
		double b=0;
		double t1=0 , t2=0 ,t3=0, t4=0,value=0;
		a=bicx-x_ture;
		b=bicy-y_ture;

		t1=-a*pow((1.0-a),2)*dst.at<uchar>(bicy_1,bicx_1) +(1.0-2.0*pow(a,2)+pow(a,3))*dst.at<uchar>(bicy,bicx_1) +a*(1.0+a-pow(a,2))*dst.at<uchar>(bicy1,bicx_1) -pow(a,2)*(1.0-a)*dst.at<uchar>(bicy2,bicx_1);
		t2=-a*pow((1.0-a),2)*dst.at<uchar>(bicy_1,bicx) +(1.0-2.0*pow(a,2)+pow(a,3))*dst.at<uchar>(bicy,bicx) +a*(1.0+a-pow(a,2))*dst.at<uchar>(bicy1,bicx) -pow(a,2)*(1.0-a)*dst.at<uchar>(bicy2,bicx);
		t3=-a*pow((1.0-a),2)*dst.at<uchar>(bicy_1,bicx1) +(1.0-2.0*pow(a,2)+pow(a,3))*dst.at<uchar>(bicy,bicx1) +a*(1.0+a-pow(a,2))*dst.at<uchar>(bicy1,bicx1) -pow(a,2)*(1.0-a)*dst.at<uchar>(bicy2,bicx1);
		t4=-a*pow((1.0-a),2)*dst.at<uchar>(bicy_1,bicx2) +(1.0-2.0*pow(a,2)+pow(a,3))*dst.at<uchar>(bicy,bicx2) +a*(1.0+a-pow(a,2))*dst.at<uchar>(bicy1,bicx2) -pow(a,2)*(1.0-a)*dst.at<uchar>(bicy2,bicx2);
		
		value=-b*pow((1.0-b),2)*t1 +(1.0-(2.0*pow(b,2))+pow(b,3))*t2 +b*(1.0+b-pow(b,2))*t3 +pow(b,2)*(b-1.0)*t4;
		if(value>255)
			value=255;
		if(value<0)
			value=0;
		new_image_bic.at<uchar>(y,x) = value;
		}



}

	imshow("HW2_1_b_NNI",new_image_NNI);
	imshow("HW2_1_b_bil",new_image_bil);
	imshow("HW2_1_b_bic",new_image_bic);
	cvWaitKey(0);	
uchar *data= new_image_NNI.data;//轉換格式
uchar *bil= new_image_bil.data;//轉換格式
uchar *bic= new_image_bic.data;//轉換格式
	fwrite(data,1,newsize,lenaNNI);
	fwrite(bil,1,newsize,lenabil);
fwrite(bic,1,newsize,lenabic);
fclose(lenaNNI);
	fclose(lenabil);
		fclose(lenabil);
	fclose(lena);
	
	delete lenai;
}
}