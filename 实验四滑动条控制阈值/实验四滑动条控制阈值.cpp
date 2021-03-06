// 实验四滑动条控制阈值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

Mat g_srcImage, dstImage;

const int  Max_type = 4;
const int  Max_value = 255;
const int  max_BINARY_value = 255;
int threshold_type = 1;
int threshold_value = 120;

//全局函数声明
static void ShowHelpText();
void Threshold_Demo(int, void*);

int main()
{
	//显示帮助文字
	ShowHelpText();
	//载入图像
	 g_srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\threshold\\2.tif",0);
   if (!g_srcImage.data)
   {
   	printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在！\n");
   	return false;
   }
   namedWindow("程序窗口", WINDOW_AUTOSIZE); // Create a window to display results
   //创建模式的滑动条
   createTrackbar("模式", "程序窗口", &threshold_type, Max_type, Threshold_Demo);
   //创建阈值的滑动条
   createTrackbar("阈值", "程序窗口", &threshold_value, Max_value, Threshold_Demo);
   Threshold_Demo(0, 0); // Call the function to initialize
   while (1)
   {
	   //等待获取键值
	   int c = waitKey(0);
	   //若按键为ESC时，退出
	   if ((char)c == 27)
		   break;

   }
    
}


//回调函数
void Threshold_Demo(int, void*)
{
	threshold(g_srcImage, dstImage, threshold_value, max_BINARY_value, threshold_type);
	imshow("程序窗口", dstImage);
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
		"\t\t滑动条模式0-二进制阈值\n"
		"\t\t滑动条模式1-反二进制阈值\n"
		"\t\t滑动条模式2-截断阈值\n"
		"\t\t滑动条模式3-反阈值化为0\n"
		"\t\t滑动条模式3-阈值化为0\n"
		"\t\t键盘按键esc-退出程序\n\n\n");
}