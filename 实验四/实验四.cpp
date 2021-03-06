// 实验四.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;


int main()
{
	#pragma region 大津法 自适应
	//输出一些帮助信息
   //printf("\n\t按键操作说明：\n"
   //	"\t\t键盘按键[ESC]-退出程序\n");
   ////读入源图片，标识0读入灰度图
   //Mat g_srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\threshold\\2.tif",0);
   //if (!g_srcImage.data)
   //{
   //	printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在！\n");
   //	return false;
   //}
   //imshow("原始图", g_srcImage);
   ////大津法阈值分割显示
   //Mat OtsuImage;
   //threshold(g_srcImage, OtsuImage, 0, 255, THRESH_OTSU);//0不起作用可为任意值
   //imshow("OtsuImage", OtsuImage);
   ////自适应阈值分割并显示
   //Mat adaptImage;
   //adaptiveThreshold(g_srcImage, adaptImage, 255, 0, THRESH_BINARY_INV, 7, 8);
   //imshow("adaptImage", adaptImage);

#pragma endregion
 
            #pragma region canny检测
//	//载入原始图
//	Mat srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\canny\\1.jpg",0);//工程目录下要有一张1.jpg的图
//	Mat srcImage1 = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\canny\\1.jpg");
//	if (!srcImage.data)
//{
//	printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在！\n");
//	return false;
//}
//	//显示原图
//	imshow("原始图Canny边缘检测", srcImage1);
//	Canny(srcImage, srcImage, 150, 100, 3);
//	imshow("效果图Canny边缘检测", srcImage);
//	 //高阶的canny算法
//	Mat dstImage, edge, grayImage;
//	//创建与Src同类型和大小的矩阵（dst）
//	dstImage.create(srcImage1.size(), srcImage1.type());
//	//将原图像转化为灰度图像
//	cvtColor(srcImage1, grayImage, CV_BGR2GRAY);
//	//先使用3X3内核来降噪
//	blur(grayImage, edge, Size(3, 3));
//	//运行Canny算子
//	Canny(edge, edge, 3, 9, 3);
//	//将dstImage内的所有元素置零
//	dstImage = Scalar::all(0);
//	//使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图SrcImage拷贝到dstImage上
//	srcImage1.copyTo(dstImage, edge);
//	//显示效果图
//	imshow("效果图Canny边缘检测2", dstImage);
//
//



#pragma endregion

            #pragma region Sobel 算子
	////创建 grad_x和grad_y矩阵
	//Mat grad_x, grad_y;
	//Mat abs_grad_x, abs_grad_y, dst;
	////载入原始图
	//Mat src = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\sobel\\1.tif");
	//if (!src.data)
	//{
	//	printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在！\n");
	//	return false;
	//}
	////显示原始图
	//imshow("原始图sobel边缘检测", src);
	////求X方向梯度
	//Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	//convertScaleAbs(grad_x, abs_grad_x);
	//imshow("效果图X方向Sobel",abs_grad_x);
	////求Y方向梯度
	//Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	//convertScaleAbs(grad_y, abs_grad_y);
	//imshow("效果图Y方向Sobel", abs_grad_y);
	////合并梯度（近似）
	//addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	//imshow("效果图整体方向Sobel", dst);

#pragma endregion

            #pragma region Laplacian检测
	//变量定义
	Mat src, src_gray, dst, abs_dst;
	//载入原始图
	 src = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-实验3-4--20181019（朱威班）\\数字图像处理实验手册及素材-实验3-4--20181019\\实验4 基于OpenCV的图像分割实验\\Laplacian\\1.jpg");
	if (!src.data)
	{
		printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在！\n");
		return false;
	}
	//显示原始图
	imshow("原始图图像Laplace", src);
	//使用高斯滤波消除噪声
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	//转换为灰度图
	cvtColor(src, src_gray, CV_RGB2GRAY);
	//使用Laplace函数
	Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	//计算绝对值，并将结果转换为8位
	convertScaleAbs(dst, abs_dst);
	//显示效果图
	imshow("效果图图像Laplace变换", abs_dst);




#pragma endregion




	   //轮寻等待用户按键，如果ESC键按下则退出程序
	while (1)
	{
		int key;
		key = waitKey(0);
		if ((char)key == 27)
		{
			break;
		}
	
	}
}
