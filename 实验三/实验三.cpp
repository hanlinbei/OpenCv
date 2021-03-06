// 实验三.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/photo/photo.hpp>

using namespace cv;
using namespace std;

Mat g_srcImage, g_dstImage;//原始图和效果图
int g_nElementShape = MORPH_RECT;//元素结构的形状

//变量接收的TrackBar位置参数
int g_nMaxIterationNum = 10;
int g_nOpenCloseNum = 0;
int g_nErodeDilateNum = 0;

static void on_OpenClose(int, void*);//回调函数
static void on_ErodeDilate(int, void*);//回调函数
static void on_TropBlackHat(int, void*);//回调函数


int main()
{   
			#pragma region 开闭腐蚀运算

	////载入原图
	//g_srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验3 基于OpenCV的图像形态学处理\\3.jpg", -1);
	//if (!g_srcImage.data)
	//{
	//	printf("读取scrImage错误！\n");
	//	return false;
	//}

	////显示原图
	//namedWindow("原始图");
	//imshow("原始图", g_srcImage);

	//namedWindow("开运算/闭运算", 1);
	//namedWindow("腐蚀/膨胀", 1);

	////参数赋值
	//g_nOpenCloseNum = 9;
	//g_nErodeDilateNum = 9;

	//createTrackbar("迭代值", "开运算/闭运算", &g_nOpenCloseNum, g_nMaxIterationNum * 2 + 1, on_OpenClose);
	//createTrackbar("迭代值", "腐蚀/膨胀", &g_nErodeDilateNum, g_nMaxIterationNum * 2 + 1, on_ErodeDilate);

	//on_OpenClose(g_nOpenCloseNum, 0);
	//on_ErodeDilate(g_nErodeDilateNum, 0);
#pragma endregion

			#pragma region 思考题1
	//	//载入原图
	//g_srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验3 基于OpenCV的图像形态学处理\\3.jpg", -1);
	//if (!g_srcImage.data)
	//{
	//	printf("读取scrImage错误！\n");
	//	return false;
	//}

	////显示原图
	//namedWindow("原始图");
	//imshow("原始图", g_srcImage);
	////canny边缘检测
	//Mat edges;
	//Canny(g_srcImage, edges, 30, 70);
	////显示边界图
	//namedWindow("灰度图边界");
	//imshow("灰度图边界", edges);

	
#pragma endregion

#pragma region 击中击不中
		//载入原图
	Mat input_image = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验3 基于OpenCV的图像形态学处理\\A.png",0);
	Mat kernel = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验3 基于OpenCV的图像形态学处理\\B.png",0);
	if (!input_image.data)
	{
		printf("读取scrImage错误！\n");
		return false;
	}

	/*显示原图*/
	namedWindow("原始图");
	imshow("原始图", input_image);
	Mat output_image,hit_result1, hit_result2;

	erode(input_image, hit_result1, kernel);
	imshow("hit_result1", hit_result1);

	erode(~input_image, hit_result2, ~kernel);
	imshow("hit_result2", hit_result2);
	//利用库函数进行击中
	//morphologyEx(input_image, output_image, MORPH_HITMISS, kernel);
	output_image= hit_result1 & hit_result2;

	imshow("Hit or Miss", output_image);


#pragma endregion


	while (1)
	{

		int c;
		//获取按键
		c = waitKey(0);
		//按下键盘按键q或者ESC，程序退出
		if ((char)c == 'q' || (char)c == 27)
			break;

	}
	return 0;

}

static void on_OpenClose(int, void*)
{
	//偏移量的定义
	int offset = g_nOpenCloseNum - g_nMaxIterationNum;//偏移量
	int Absolute_offset = offset > 0 ? offset : -offset;//偏移量的绝对值
	//自定义核
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	//进行操作
	if (offset < 0)
	{
		morphologyEx(g_srcImage, g_dstImage, CV_MOP_OPEN, element);
	}
	else
	{
		morphologyEx(g_srcImage, g_dstImage, CV_MOP_CLOSE, element);
	}
	//显示图像
	imshow("开运算/闭运算",g_dstImage);

}

static void on_ErodeDilate(int, void*)
{
	//偏移量的定义
	int offset = g_nErodeDilateNum - g_nMaxIterationNum;//偏移量
	int Absolute_offset = offset > 0 ? offset : -offset;//偏移量的绝对值
	//自定义核
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	//进行操作
	if (offset < 0)
	{
		erode(g_srcImage, g_dstImage, element);
	}
	else
	{
		erode(g_srcImage, g_dstImage, element);
	}
	//显示图像
	imshow("腐蚀/膨胀", g_dstImage);

}