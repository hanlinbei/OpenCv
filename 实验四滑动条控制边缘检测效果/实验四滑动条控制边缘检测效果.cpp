// 实验四滑动条控制边缘检测效果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

Mat srcImage;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
//全局函数声明
static void ShowHelpText();
void Canny_Demo(); //Canny边缘检测
void Sobel_Demo();//Sobel边缘检测
void Laplance_Demo();//Laplance边缘检测
static void CannyThreshold(int, void*);//Canny检测回调函数
static void SobelThreshold(int, void*);//Sobel检测回调函数
static void LaplanceThreshold(int, void*);//Laplance检测回调函数

int main()
{
	//显示帮助文字
	ShowHelpText();
	//载入图像
	 srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\sobel\\1.tif",0);
	if (!srcImage.data)
	{
	printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在！\n");
	return false;
	}
	//显示原图
	imshow("原始图", srcImage);
	while (1)
	{
		//等待获取键值
		int c = waitKey(0);
		//按键1 - Canny边缘检测
		if ((char)c == '1')
		{
			Canny_Demo();
		
		}
		//按键2 - Sobel边缘检测
		if ((char)c == '2')
		{
			Sobel_Demo();
		}
		//按键3 - Laplance边缘检测
		if ((char)c == '3')
		{
			Laplance_Demo();
		}
		//若按键为ESC时，退出
		if ((char)c == 27)
			break;

	}
}


void Canny_Demo()
{
	namedWindow("Canny边缘检测", WINDOW_AUTOSIZE);
	createTrackbar("参数值:", "Canny边缘检测", &lowThreshold, max_lowThreshold, CannyThreshold);
	CannyThreshold(0, 0);

}

//回调函数
static void CannyThreshold(int, void*)
{
	blur(srcImage, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
	dst = Scalar::all(0);
	srcImage.copyTo(dst, detected_edges);
	imshow("Canny边缘检测", dst);
}

void Sobel_Demo()
{
	namedWindow("Sobel边缘检测", WINDOW_AUTOSIZE);
	createTrackbar("参数值:", "Sobel边缘检测", &lowThreshold, 100, SobelThreshold);
	SobelThreshold(0, 0);
}

//回调函数
static void SobelThreshold(int, void*)
{
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	//求X方向梯度
	Sobel(srcImage, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	//求Y方向梯度
	Sobel(srcImage, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	//合并梯度（近似）
	addWeighted(abs_grad_x, lowThreshold*0.1, abs_grad_y, lowThreshold*0.1, 0, dst);
	imshow("Sobel边缘检测", dst);
}

void Laplance_Demo()
{
	namedWindow("Laplance边缘检测", WINDOW_AUTOSIZE);
	createTrackbar("参数值:", "Laplance边缘检测", &lowThreshold, 10, LaplanceThreshold);
	LaplanceThreshold(0, 0);

}

//回调函数
static void LaplanceThreshold(int, void*)
{
	Mat abs_dst;
	//使用高斯滤波消除噪声
	GaussianBlur(srcImage, srcImage, Size(3, 3), 0, 0, BORDER_DEFAULT);
	//使用Laplace函数
	Laplacian(srcImage, dst, CV_16S, 3 , lowThreshold, 0, BORDER_DEFAULT);
	//计算绝对值，并将结果转换为8位
	convertScaleAbs(dst, abs_dst);
	//显示效果图
	imshow("Laplance边缘检测", abs_dst);
}


//输出一些帮助信息
static void ShowHelpText()
{
	//输出OPenCV版本
	printf("\n\n\t\t\t 当前使用的OPenCV版本为：" CV_VERSION);
	printf("\n\n---------------------------\n");

	//输出一些帮助信息
	printf(
		"\n\n\t按键操作说明：\n\n"
		"\t\t按键1-Canny边缘检测\n"
		"\t\t按键2-Sobel边缘检测\n"
		"\t\t按键3-Laplance边缘检测\n"
		"\t\t键盘按键esc-退出程序\n\n\n");
}
