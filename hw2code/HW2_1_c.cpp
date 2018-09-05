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
# define size576 1474.56*1474.56


void HW2_1_c(void)
{unsigned char *lenai;
char FileNameOri[]="lena256.raw";
char FileName2NNI[]="2_1_b_NNI.raw";
char FileNamebil[]="2_1_b_bil.raw";
char FileNamebic[]="2_1_b_bic.raw";
lenai = new unsigned char[size]; 
CvMat *lenamat = cvCreateMat(256,256, CV_8UC1);
clock_t start, stop;

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
double sf=2.25;
double sf576=5.76;
double sf256=1/2.56;
double rowsa=rowss*sf;
double rowsa576=rowss*sf576;
double rowsa256=rowss*sf256;
double colsa=colss*sf;
double colsa576=colss*sf576;
double colsa256=colss*sf256;

Mat new_image_NNI;
new_image_NNI.create(rowsa,colsa,CV_8U);
Mat new_image_NNI576;
new_image_NNI576.create(rowsa576,colsa576,CV_8U);
Mat new_image_NNI576256;
new_image_NNI576256.create(rowsa,colsa,CV_8U);
Mat new_image_NNI256;
new_image_NNI256.create(rowsa256,colsa256,CV_8U);
Mat new_image_NNI256576;
new_image_NNI256576.create(rowsa,colsa,CV_8U);
Mat new_image_bil;
new_image_bil.create(rowsa,colsa,CV_8U);
Mat new_image_bil576;
new_image_bil576.create(rowsa576,colsa576,CV_8U);
Mat new_image_bil576256;
new_image_bil576256.create(rowsa,colsa,CV_8U);
Mat new_image_bil256;
new_image_bil256.create(rowsa256,colsa256,CV_8U);
Mat new_image_bil256576;
new_image_bil256576.create(rowsa,colsa,CV_8U);
Mat new_image_bic;
new_image_bic.create(rowsa,colsa,CV_8U);
Mat new_image_bic576;
new_image_bic576.create(rowsa576,colsa576,CV_8U);
Mat new_image_bic576256;
new_image_bic576256.create(rowsa,colsa,CV_8U);
Mat new_image_bic256;
new_image_bic256.create(rowsa256,colsa256,CV_8U);
Mat new_image_bic256576;
new_image_bic256576.create(rowsa,colsa,CV_8U);


////////////////////////////////////////////////////////////2.25nni
start=clock();
double newx=0;
double newy=0;
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
stop=clock();
printf("\n使用NNI放大2.25倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間

/////////////////////////////////////////////////////////////up5.76down2.56  nni//
start=clock();
double newx576=0;
double newy576=0;
for(int y=0;y<rowsa576-1;y++)
{
	for(int x=0;x<colsa576-1;x++)
	{
		newx576=(x/sf576)+0.5;
	newy576=(y/sf576)+0.5;
	
	if(newx576>=colss-1)
		newx576--;
	if(newy576>=rowss-1)
		newy576--;
	new_image_NNI576.at<uchar>(y,x)=dst.at<uchar>(newy576,newx576);
	}

}
double newx256=0;
double newy256=0;

for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{
		newx256=(x/sf256)+0.5;
	newy256=(y/sf256)+0.5;
	
	if(newx256>=colss-1)
		newx256--;
	if(newy256>=rowss-1)
		newy256--;
	new_image_NNI576256.at<uchar>(y,x)=new_image_NNI576.at<uchar>(newy256,newx256);
	}

}

stop=clock();
printf("\n使用NNI先放大5.76倍再縮小2.56倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間

///////////////////////////////////////////////////////////////////////////////down2.56 up5.76   nni///
start=clock();
double newx_256=0;
double newy_256=0;

for(int y=0;y<rowsa256-1;y++)
{
	for(int x=0;x<colsa256-1;x++)
	{
		newx_256=(x/sf256)+0.5;
	newy_256=(y/sf256)+0.5;
	
	if(newx_256>=colss-1)
		newx_256--;
	if(newy_256>=rowss-1)
		newy_256--;
	new_image_NNI256.at<uchar>(y,x)=dst.at<uchar>(newy_256,newx_256);
	}

}

double newx_576=0;
double newy_576=0;
for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{
	newx_576=(x/sf576)+0.5;
	newy_576=(y/sf576)+0.5;
	
	if(newx_576>=colsa256-1)
		newx_576--;
	if(newy_576>=rowsa256-1)
		newy_576--;
	new_image_NNI256576.at<uchar>(y,x)=new_image_NNI256.at<uchar>(newy_576,newx_576);
	}

}
stop=clock();
printf("\n使用NNI先縮小2.56倍再放大5.76倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間

//////////////////////////////////////////////////////////////////////////////////////2.25bil
start=clock();
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
stop=clock();
printf("\n使用bilinear放大2.25倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間
///////////////////////////////////////////////////////////////////////up5.76down2.56bil
start=clock();
double pa576,pb576,pc576,pd576,output576;
	double newxa576=0,newya576=0;
	double newxb576=0,newyb576=0;
	double newxc576=0,newyc576=0;
	double newxd576=0,newyd576=0;
	double alpha576=0,beta576=0;



for(int y=0;y<rowsa576-1;y++)
{
	for(int x=0;x<colsa576-1;x++)
	{
		newxa576=x/sf576;
		newya576=y/sf576;
		newxb576=newxa576+1;
		newyb576=newya576;
		newxc576=newxa576;
		newyc576=newya576+1;
		newxd576=newxa576+1;
		newyd576=newya576+1;
		
		if(newxb576>=colss-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxb576--;
		if(newxd576>=colss-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxd576--;
		if(newyc576>=rowss-1)
			newyc576--;
		if(newyd576>=rowss-1)
			newyd576--;
		alpha576=x/sf576-newxa576;
		beta576=y/sf576-newya576;
		pa576=dst.at<uchar>(newya576,newxa576);
		pb576=dst.at<uchar>(newyb576,newxb576);
		pc576=dst.at<uchar>(newyc576,newxc576);
		pd576=dst.at<uchar>(newyd576,newxd576);
		output576 = (1-alpha576)*(1-beta576)*pa576+alpha576*(1-beta576)*pb576+(1-alpha576)*beta576*pc576+alpha576*beta576*pd576;
		new_image_bil576.at<uchar>(y,x) = output576;
	}
}

double pa256,pb256,pc256,pd256,output256;
	double newxa256=0,newya256=0;
	double newxb256=0,newyb256=0;
	double newxc256=0,newyc256=0;
	double newxd256=0,newyd256=0;
	double alpha256=0,beta256=0;



for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{
		newxa256=x/sf256;
		newya256=y/sf256;
		newxb256=newxa256+1;
		newyb256=newya256;
		newxc256=newxa256;
		newyc256=newya256+1;
		newxd256=newxa256+1;
		newyd256=newya256+1;
		
		if(newxb256>=colsa256-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxb256--;
		if(newxd256>=colsa256-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxd256--;
		if(newyc256>=rowsa256-1)
			newyc256--;
		if(newyd256>=rowsa256-1)
			newyd256--;
		alpha256=x/sf256-newxa256;
		beta256=y/sf256-newya256;
		pa256=new_image_bil576.at<uchar>(newya256,newxa256);
		pb256=new_image_bil576.at<uchar>(newyb256,newxb256);
		pc256=new_image_bil576.at<uchar>(newyc256,newxc256);
		pd256=new_image_bil576.at<uchar>(newyd256,newxd256);
		output256 = (1-alpha256)*(1-beta256)*pa256+alpha256*(1-beta256)*pb256+(1-alpha256)*beta256*pc256+alpha256*beta256*pd256;
		new_image_bil576256.at<uchar>(y,x) = output256;
	}
}
stop=clock();
printf("\n使用bilinear先放大5.76倍再縮小2.56倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間
/////////////////////////////////////////////////////////down2.56up5.76bil
start=clock();
double pa_256,pb_256,pc_256,pd_256,output_256;
	double newxa_256=0,newya_256=0;
	double newxb_256=0,newyb_256=0;
	double newxc_256=0,newyc_256=0;
	double newxd_256=0,newyd_256=0;
	double alpha_256=0,beta_256=0;



for(int y=0;y<rowsa256-1;y++)
{
	for(int x=0;x<colsa256-1;x++)
	{
		newxa_256=x/sf256;
		newya_256=y/sf256;
		newxb_256=newxa_256+1;
		newyb_256=newya_256;
		newxc_256=newxa_256;
		newyc_256=newya_256+1;
		newxd_256=newxa_256+1;
		newyd_256=newya_256+1;
		
		if(newxb_256>=colss-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxb_256--;
		if(newxd_256>=colss-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxd_256--;
		if(newyc_256>=rowss-1)
			newyc_256--;
		if(newyd_256>=rowss-1)
			newyd_256--;
		alpha_256=x/sf256-newxa_256;
		beta_256=y/sf256-newya_256;
		pa_256=dst.at<uchar>(newya_256,newxa_256);
		pb_256=dst.at<uchar>(newyb_256,newxb_256);
		pc_256=dst.at<uchar>(newyc_256,newxc_256);
		pd_256=dst.at<uchar>(newyd_256,newxd_256);
		output_256 = (1-alpha_256)*(1-beta_256)*pa_256+alpha_256*(1-beta_256)*pb_256+(1-alpha_256)*beta_256*pc_256+alpha_256*beta_256*pd_256;
		new_image_bil256.at<uchar>(y,x) = output_256;
	}
}

double pa_576,pb_576,pc_576,pd_576,output_576;
	double newxa_576=0,newya_576=0;
	double newxb_576=0,newyb_576=0;
	double newxc_576=0,newyc_576=0;
	double newxd_576=0,newyd_576=0;
	double alpha_576=0,beta_576=0;



for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{
		newxa_576=x/sf576;
		newya_576=y/sf576;
		newxb_576=newxa_576+1;
		newyb_576=newya_576;
		newxc_576=newxa_576;
		newyc_576=newya_576+1;
		newxd_576=newxa_576+1;
		newyd_576=newya_576+1;
		
		if(newxb_576>=colsa256-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxb_576--;
		if(newxd_576>=colsa256-1)//影像邊邊會因為原本影像的座標而超出範圍
			newxd_576--;
		if(newyc_576>=rowsa256-1)
			newyc_576--;
		if(newyd_576>=rowsa256-1)
			newyd_576--;
		alpha_576=x/sf576-newxa_576;
		beta_576=y/sf576-newya_576;
		pa_576=new_image_bil256.at<uchar>(newya_576,newxa_576);
		pb_576=new_image_bil256.at<uchar>(newyb_576,newxb_576);
		pc_576=new_image_bil256.at<uchar>(newyc_576,newxc_576);
		pd_576=new_image_bil256.at<uchar>(newyd_576,newxd_576);
		output_576 = (1-alpha_576)*(1-beta_576)*pa_576+alpha_576*(1-beta_576)*pb_576+(1-alpha_576)*beta_576*pc_576+alpha_576*beta_576*pd_576;
		new_image_bil256576.at<uchar>(y,x) = output_576;
	}
}

stop=clock();
printf("\n使用bilinear先縮小2.56倍再放大5.76倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間
////////////////////////////////////////////////////////////////////////////bic2.25
start=clock();
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
stop=clock();
printf("\n使用bicubic放大2.25倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間
//////////////////////////////////////////////////////////////////////////up5.76down2.56
start=clock();
double bicx576=0;
double bicy576=0;
double bicx1576=0;
double bicx2576=0;
double bicx_1576=0;
double bicy1576=0;
double bicy2576=0;
double bicy_1576=0;

for(int y=0;y<rowsa576-1;y++)
{
	for(int x=0;x<colsa576-1;x++)
	{double x_ture576=0;
	double y_ture576=0;
	x_ture576=x/sf576;
	y_ture576=y/sf576;

		bicx576=(x/sf576)+0.5;
		bicy576=(y/sf576)+0.5;
		bicx1576=bicx576+1;
		bicx2576=bicx576+2;
		bicx_1576=bicx576-1;
		bicy1576=bicy576+1;
		bicy2576=bicy576+2;
		bicy_1576=bicy576-1;
		if(bicx576>colss-1)
			bicx576=255;
		if(bicx1576>colss-1)
			bicx1576=255;
		if(bicx2576>colss-1)
			bicx2576=255;
		if(bicx_1576<0)
			bicx_1576=0;
		if(bicy576>rowss-1)
			bicy576=255;
		if(bicy1576>rowss-1)
			bicy1576=255;
		if(bicy2576>rowss-1)
			bicy2576=255;
		if(bicy_1576<0)
			bicy_1576=0;
		double a576=0;
		double b576=0;
		double t1576=0 , t2576=0 ,t3576=0, t4576=0,value576=0;
		a576=bicx576-x_ture576;
		b576=bicy576-y_ture576;

		t1576=-a576*pow((1.0-a576),2)*dst.at<uchar>(bicy_1576,bicx_1576) +(1.0-2.0*pow(a576,2)+pow(a576,3))*dst.at<uchar>(bicy576,bicx_1576) +a576*(1.0+a576-pow(a576,2))*dst.at<uchar>(bicy1576,bicx_1576) -pow(a576,2)*(1.0-a576)*dst.at<uchar>(bicy2576,bicx_1576);
		t2576=-a576*pow((1.0-a576),2)*dst.at<uchar>(bicy_1576,bicx576) +(1.0-2.0*pow(a576,2)+pow(a576,3))*dst.at<uchar>(bicy576,bicx576) +a576*(1.0+a576-pow(a576,2))*dst.at<uchar>(bicy1576,bicx576) -pow(a576,2)*(1.0-a576)*dst.at<uchar>(bicy2576,bicx576);
		t3576=-a576*pow((1.0-a576),2)*dst.at<uchar>(bicy_1576,bicx1576) +(1.0-2.0*pow(a576,2)+pow(a576,3))*dst.at<uchar>(bicy576,bicx1576) +a576*(1.0+a576-pow(a576,2))*dst.at<uchar>(bicy1576,bicx1576) -pow(a576,2)*(1.0-a576)*dst.at<uchar>(bicy2576,bicx1576);
		t4576=-a576*pow((1.0-a576),2)*dst.at<uchar>(bicy_1576,bicx2576) +(1.0-2.0*pow(a576,2)+pow(a576,3))*dst.at<uchar>(bicy576,bicx2576) +a576*(1.0+a576-pow(a576,2))*dst.at<uchar>(bicy1576,bicx2576) -pow(a576,2)*(1.0-a576)*dst.at<uchar>(bicy2576,bicx2576);
		
		value576=-b576*pow((1.0-b576),2)*t1576 +(1.0-(2.0*pow(b576,2))+pow(b576,3))*t2576 +b576*(1.0+b576-pow(b576,2))*t3576 +pow(b576,2)*(b576-1.0)*t4576;
		if(value576>255)
			value576=255;
		if(value576<0)
			value576=0;
		new_image_bic576.at<uchar>(y,x) = value576;
		}
}

double bicx256=0;
double bicy256=0;
double bicx1256=0;
double bicx2256=0;
double bicx_1256=0;
double bicy1256=0;
double bicy2256=0;
double bicy_1256=0;

for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{double x_ture256=0;
	double y_ture256=0;
	x_ture256=x/sf256;
	y_ture256=y/sf256;

		bicx256=(x/sf256)+0.5;
		bicy256=(y/sf256)+0.5;
		bicx1256=bicx256+1;
		bicx2256=bicx256+2;
		bicx_1256=bicx256-1;
		bicy1256=bicy256+1;
		bicy2256=bicy256+2;
		bicy_1256=bicy256-1;
		if(bicx256>colsa576-1)
			bicx256=255;
		if(bicx1256>colsa576-1)
			bicx1256=255;
		if(bicx2256>colsa576-1)
			bicx2256=255;
		if(bicx_1256<0)
			bicx_1256=0;
		if(bicy256>rowsa576-1)
			bicy256=255;
		if(bicy1256>rowsa576-1)
			bicy1256=255;
		if(bicy2256>rowsa576-1)
			bicy2256=255;
		if(bicy_1256<0)
			bicy_1256=0;
		double a256=0;
		double b256=0;
		double t1256=0 , t2256=0 ,t3256=0, t4256=0,value256=0;
		a256=bicx256-x_ture256;
		b256=bicy256-y_ture256;

		t1256=-a256*pow((1.0-a256),2)*new_image_bic576.at<uchar>(bicy_1256,bicx_1256) +(1.0-2.0*pow(a256,2)+pow(a256,3))*new_image_bic576.at<uchar>(bicy256,bicx_1256) +a256*(1.0+a256-pow(a256,2))*new_image_bic576.at<uchar>(bicy1256,bicx_1256) -pow(a256,2)*(1.0-a256)*new_image_bic576.at<uchar>(bicy2256,bicx_1256);
		t2256=-a256*pow((1.0-a256),2)*new_image_bic576.at<uchar>(bicy_1256,bicx256) +(1.0-2.0*pow(a256,2)+pow(a256,3))*new_image_bic576.at<uchar>(bicy256,bicx256) +a256*(1.0+a256-pow(a256,2))*new_image_bic576.at<uchar>(bicy1256,bicx256) -pow(a256,2)*(1.0-a256)*new_image_bic576.at<uchar>(bicy2256,bicx256);
		t3256=-a256*pow((1.0-a256),2)*new_image_bic576.at<uchar>(bicy_1256,bicx1256) +(1.0-2.0*pow(a256,2)+pow(a256,3))*new_image_bic576.at<uchar>(bicy256,bicx1256) +a256*(1.0+a256-pow(a256,2))*new_image_bic576.at<uchar>(bicy1256,bicx1256) -pow(a256,2)*(1.0-a256)*new_image_bic576.at<uchar>(bicy2256,bicx1256);
		t4256=-a256*pow((1.0-a256),2)*new_image_bic576.at<uchar>(bicy_1256,bicx2256) +(1.0-2.0*pow(a256,2)+pow(a256,3))*new_image_bic576.at<uchar>(bicy256,bicx2256) +a256*(1.0+a256-pow(a256,2))*new_image_bic576.at<uchar>(bicy1256,bicx2256) -pow(a256,2)*(1.0-a256)*new_image_bic576.at<uchar>(bicy2256,bicx2256);
		
		value256=-b256*pow((1.0-b256),2)*t1256 +(1.0-(2.0*pow(b256,2))+pow(b256,3))*t2256 +b256*(1.0+b256-pow(b256,2))*t3256 +pow(b256,2)*(b256-1.0)*t4256;
		if(value256>255)
			value256=255;
		if(value256<0)
			value256=0;
		new_image_bic576256.at<uchar>(y,x) = value256;
		}
}

stop=clock();
printf("\n使用bicubic先放大5.76倍再縮小2.56倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間
////////////////////////////////////////////////////////////////////////////////////////////////////////down2.56up5.76bic
start=clock();
double bicx256576=0;
double bicy256576=0;
double bicx1256576=0;
double bicx2256576=0;
double bicx_1256576=0;
double bicy1256576=0;
double bicy2256576=0;
double bicy_1256576=0;

for(int y=0;y<rowsa256-1;y++)
{
	for(int x=0;x<colsa256-1;x++)
	{double x_ture256576=0;
	double y_ture256576=0;
	x_ture256576=x/sf256;
	y_ture256576=y/sf256;

		bicx256576=(x/sf256)+0.5;
		bicy256576=(y/sf256)+0.5;
		bicx1256576=bicx256576+1;
		bicx2256576=bicx256576+2;
		bicx_1256576=bicx256576-1;
		bicy1256576=bicy256576+1;
		bicy2256576=bicy256576+2;
		bicy_1256576=bicy256576-1;
		if(bicx256576>colss-1)
			bicx256576=255;
		if(bicx1256576>colss-1)
			bicx1256576=255;
		if(bicx2256576>colss-1)
			bicx2256576=255;
		if(bicx_1256576<0)
			bicx_1256576=0;
		if(bicy256576>rowss-1)
			bicy256576=255;
		if(bicy1256576>rowss-1)
			bicy1256576=255;
		if(bicy2256576>rowss-1)
			bicy2256576=255;
		if(bicy_1256576<0)
			bicy_1256576=0;
		double a256576=0;
		double b256576=0;
		double t1256576=0 , t2256576=0 ,t3256576=0, t4256576=0,value256576=0;
		a256576=bicx256576-x_ture256576;
		b256576=bicy256576-y_ture256576;

		t1256576=-a256576*pow((1.0-a256576),2)*dst.at<uchar>(bicy_1256576,bicx_1256576) +(1.0-2.0*pow(a256576,2)+pow(a256576,3))*dst.at<uchar>(bicy256576,bicx_1256576) +a256576*(1.0+a256576-pow(a256576,2))*dst.at<uchar>(bicy1256576,bicx_1256576) -pow(a256576,2)*(1.0-a256576)*dst.at<uchar>(bicy2256576,bicx_1256576);
		t2256576=-a256576*pow((1.0-a256576),2)*dst.at<uchar>(bicy_1256576,bicx256576) +(1.0-2.0*pow(a256576,2)+pow(a256576,3))*dst.at<uchar>(bicy256576,bicx256576) +a256576*(1.0+a256576-pow(a256576,2))*dst.at<uchar>(bicy1256576,bicx256576) -pow(a256576,2)*(1.0-a256576)*dst.at<uchar>(bicy2256576,bicx256576);
		t3256576=-a256576*pow((1.0-a256576),2)*dst.at<uchar>(bicy_1256576,bicx1256576) +(1.0-2.0*pow(a256576,2)+pow(a256576,3))*dst.at<uchar>(bicy256576,bicx1256576) +a256576*(1.0+a256576-pow(a256576,2))*dst.at<uchar>(bicy1256576,bicx1256576) -pow(a256576,2)*(1.0-a256576)*dst.at<uchar>(bicy2256576,bicx1256576);
		t4256576=-a256576*pow((1.0-a256576),2)*dst.at<uchar>(bicy_1256576,bicx2256576) +(1.0-2.0*pow(a256576,2)+pow(a256576,3))*dst.at<uchar>(bicy256576,bicx2256576) +a256576*(1.0+a256576-pow(a256576,2))*dst.at<uchar>(bicy1256576,bicx2256576) -pow(a256576,2)*(1.0-a256576)*dst.at<uchar>(bicy2256576,bicx2256576);
		
		value256576=-b256576*pow((1.0-b256576),2)*t1256576 +(1.0-(2.0*pow(b256576,2))+pow(b256576,3))*t2256576 +b256576*(1.0+b256576-pow(b256576,2))*t3256576 +pow(b256576,2)*(b256576-1.0)*t4256576;
		if(value256576>255)
			value256576=255;
		if(value256576<0)
			value256576=0;
		new_image_bic256.at<uchar>(y,x) = value256576;
		}
}

double bicx576256=0;
double bicy576256=0;
double bicx1576256=0;
double bicx2576256=0;
double bicx_1576256=0;
double bicy1576256=0;
double bicy2576256=0;
double bicy_1576256=0;

for(int y=0;y<rowsa-1;y++)
{
	for(int x=0;x<colsa-1;x++)
	{double x_ture576256=0;
	double y_ture576256=0;
	x_ture576256=x/sf576;
	y_ture576256=y/sf576;

		bicx576256=(x/sf576)+0.5;
		bicy576256=(y/sf576)+0.5;
		
		if(bicx576256>=colsa256-1)
			bicx576256=colsa256-1;
		bicx1576256=bicx576256+1;
		bicx2576256=bicx576256+2;
		bicx_1576256=bicx576256-1;
		
		if(bicx1576256>colsa256-1)
			bicx1576256=colsa256-1;
		if(bicx2576256>=colsa256-1)
			bicx2576256=colsa256-1;
		if(bicx_1576256<0)
			bicx_1576256=0;
		if(bicy576256>=rowsa256-1)
			bicy576256=rowsa256-1;
		bicy1576256=bicy576256+1;
		bicy2576256=bicy576256+2;
		bicy_1576256=bicy576256-1;
		if(bicy1576256>=rowsa256-1)
			bicy1576256=rowsa256-1;
		if(bicy2576256>=rowsa256-1)
			bicy2576256=rowsa256-1;
		if(bicy_1576256<0)
			bicy_1576256=0;
		double a576256=0;
		double b576256=0;
		double t1576256=0 , t2576256=0 ,t3576256=0, t4576256=0,value576256=0;
		a576256=x_ture576256-bicx576256;
		b576256=y_ture576256-bicy576256;

		t1576256=-a576256*pow((1.0-a576256),2)*new_image_bic256.at<uchar>(bicy_1576256,bicx_1576256) +(1.0-2.0*pow(a576256,2)+pow(a576256,3))*new_image_bic256.at<uchar>(bicy576256,bicx_1576256) +a576256*(1.0+a576256-pow(a576256,2))*new_image_bic256.at<uchar>(bicy1576256,bicx_1576256) -pow(a576256,2)*(1.0-a576256)*new_image_bic256.at<uchar>(bicy2576256,bicx_1576256);
		t2576256=-a576256*pow((1.0-a576256),2)*new_image_bic256.at<uchar>(bicy_1576256,bicx576256) +(1.0-2.0*pow(a576256,2)+pow(a576256,3))*new_image_bic256.at<uchar>(bicy576256,bicx576256) +a576256*(1.0+a576256-pow(a576256,2))*new_image_bic256.at<uchar>(bicy1576256,bicx576256) -pow(a576256,2)*(1.0-a576256)*new_image_bic256.at<uchar>(bicy2576256,bicx576256);
		t3576256=-a576256*pow((1.0-a576256),2)*new_image_bic256.at<uchar>(bicy_1576256,bicx1576256) +(1.0-2.0*pow(a576256,2)+pow(a576256,3))*new_image_bic256.at<uchar>(bicy576256,bicx1576256) +a576256*(1.0+a576256-pow(a576256,2))*new_image_bic256.at<uchar>(bicy1576256,bicx1576256) -pow(a576256,2)*(1.0-a576256)*new_image_bic256.at<uchar>(bicy2576256,bicx1576256);
		t4576256=-a576256*pow((1.0-a576256),2)*new_image_bic256.at<uchar>(bicy_1576256,bicx2576256) +(1.0-2.0*pow(a576256,2)+pow(a576256,3))*new_image_bic256.at<uchar>(bicy576256,bicx2576256) +a576256*(1.0+a576256-pow(a576256,2))*new_image_bic256.at<uchar>(bicy1576256,bicx2576256) -pow(a576256,2)*(1.0-a576256)*new_image_bic256.at<uchar>(bicy2576256,bicx2576256);
		
		value576256=-b576256*pow((1.0-b576256),2)*t1576256 +(1.0-(2.0*pow(b576256,2))+pow(b576256,3))*t2576256 +b576256*(1.0+b576256-pow(b576256,2))*t3576256 +pow(b576256,2)*(b576256-1.0)*t4576256;
		if(value576256>255)
			value576256=255;
		if(value576256<0)
			value576256=0;
		new_image_bic256576.at<uchar>(y,x) = value576256;
		}
}

stop=clock();
printf("\n使用bicubic先縮小2.56倍再放大5.76倍的運算時間為%.3f秒\n", double(stop-start)/CLOCKS_PER_SEC); //顯示運算時間












/////////////////////////////////////////////////////////////////////////
	imshow("HW2_1_c_NNI225",new_image_NNI);
	imshow("HW2_1_c_NNI576",new_image_NNI576256);
	imshow("HW2_1_c_NNI256",new_image_NNI256576);
	imshow("HW2_1_c_bil225",new_image_bil);
	imshow("HW2_1_c_bil576",new_image_bil576256);
	imshow("HW2_1_c_bil256",new_image_bil256576);
	imshow("HW2_1_c_bic225",new_image_bic);
	imshow("HW2_1_c_bic576",new_image_bic576256);
	imshow("HW2_1_c_bic256",new_image_bic256576);
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