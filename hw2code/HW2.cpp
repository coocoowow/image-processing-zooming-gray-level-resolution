#define _CRT_SECURE_NO_DEPRECATE //去除fopen報警告
#include <stdio.h> 
#include <cv.h> 
#include <highgui.h> 
#include <iostream>
#include <fstream>
#include <string>
using namespace cv;
using namespace std;
void HW2_1_a();
void HW2_1_b();
void HW2_1_c();
void HW2_2_a();
void HW2_2_b();
//





void main()
{
	int number1=0;
	cout<<"輸入題號:例如1_a小題為11 2_a小題為21";
	cin>> number1;
	if( number1 ==11)
HW2_1_a();
		if( number1 ==12)
HW2_1_b();
			if( number1 ==13)
HW2_1_c();
				if( number1 ==21)
HW2_2_a();
					if( number1 ==22)
HW2_2_b();

				


		





	}
