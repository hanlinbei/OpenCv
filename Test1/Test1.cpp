// Test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

const int g_nMaxValueSlider = 100;
const int g_nBrightnessMaxValueSlider = 200;
const int g_nContrastMaxValueSlider = 300;
int g_fGammaValueSlider = 20;
int g_fBrightnessValueSlider = 80;
int g_fContrastValueSlider = 80;



Mat srcImage ,dstImage;


void on_Trackbar(int, void*);
void on_BrightnessAndContrast(int, void*);


int main()
{


	     #pragma region GRB三通道分离并显示
	/*载入图像*/
	//srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\1.jpg");
	//if (!srcImage.data)
	//{
	//	printf("读取srcImage错误!\n");
	//	return false;
	//}
	//namedWindow("原图");
	//imshow("原图", srcImage);
	//Mat rgbChannels[3];
	//split(srcImage, rgbChannels);
	//Mat BlueChannelDisplay;
	//Mat GreenChannelDisplay;
	//Mat RedChannelDisplay;

	//BlueChannelDisplay = rgbChannels[0];
	//GreenChannelDisplay = rgbChannels[1];
	//RedChannelDisplay = rgbChannels[2];

	//namedWindow("B_channel");
	//imshow("B_channel", BlueChannelDisplay);

	//namedWindow("G_channel");
	//imshow("G_channel", GreenChannelDisplay);

	//namedWindow("R_channel");
	//imshow("R_channel", RedChannelDisplay);

#pragma endregion

          #pragma region 直方图均衡化

		/*载入图像*/
	//srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\1.jpg");
	//if (!srcImage.data)
	//{
	//	printf("读取srcImage错误!\n");
	//	return false;
	//}
	//namedWindow("原图");
	//imshow("原图", srcImage);
	//vector<Mat> channels;

	//Mat imageBlueChannel;
	//Mat imageGreenChannel;
	//Mat imageRedChannel;
	//Mat equalizeHistImage;

	//split(srcImage, channels);
	//imageBlueChannel = channels.at(0);
	//imageGreenChannel = channels.at(1);
	//imageRedChannel = channels.at(2);

	//equalizeHist(imageBlueChannel, imageBlueChannel);
	//equalizeHist(imageGreenChannel, imageGreenChannel);
	//equalizeHist(imageRedChannel, imageRedChannel);

	//merge(channels, equalizeHistImage);

	//namedWindow("直方图均衡化");
	//imshow("直方图均衡化", equalizeHistImage);



#pragma endregion

          #pragma region 锐化滤波器
		/*载入图像*/
	//srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\1.jpg");
	//if (!srcImage.data)
	//{
	//	printf("读取srcImage错误!\n");
	//	return false;
	//}
	//namedWindow("原图");
	//imshow("原图", srcImage);
	//Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//高通滤波核
	//Mat filter2DImage;
	//filter2D(srcImage, filter2DImage, srcImage.depth(), kernel);

	//namedWindow("锐化滤波器");
	//imshow("锐化滤波器", filter2DImage);




#pragma endregion
         
         #pragma region 伽马矫正
		/*载入图像*/
	//srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\1.jpg");
	//if (!srcImage.data)
	//{
	//	printf("读取srcImage错误!\n");
	//	return false;
	//}
	//namedWindow("原图");
	//imshow("原图", srcImage);
	//namedWindow("伽马矫正", 1);

	//char TrackbarName[50];
	//sprintf_s(TrackbarName, "fGamma%d", g_nMaxValueSlider);
	//createTrackbar(TrackbarName, "伽马矫正", &g_fGammaValueSlider, g_nMaxValueSlider, on_Trackbar);
	//on_Trackbar(g_nMaxValueSlider, 0);



#pragma endregion


		#pragma region 思考题1
	/*载入图像*/
	//srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\1.jpg");
	//if (!srcImage.data)
	//{
	//	printf("读取srcImage错误!\n");
	//	return false;
	//}
	//namedWindow("原图");
	//imshow("原图", srcImage);
	//dstImage = Mat::zeros(srcImage.size(), srcImage.type());
	//namedWindow("亮度对比度调整", 1);
	//char TrackbarName[50];
	//sprintf_s(TrackbarName, "Brightness%d", g_nBrightnessMaxValueSlider);
	//createTrackbar(TrackbarName, "亮度对比度调整", &g_fBrightnessValueSlider, g_nBrightnessMaxValueSlider, on_BrightnessAndContrast);
	//sprintf_s(TrackbarName, "Contrast%d", g_nContrastMaxValueSlider);
	//createTrackbar(TrackbarName, "亮度对比度调整", &g_fContrastValueSlider, g_nContrastMaxValueSlider, on_BrightnessAndContrast);
	//on_BrightnessAndContrast(g_fContrastValueSlider, 0);
	//on_BrightnessAndContrast(g_fBrightnessValueSlider, 0);

	



#pragma endregion


		#pragma region 思考题2
	/*载入图像*/
	//srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\2.bmp");
	//if (!srcImage.data)
	//{
	//	printf("读取srcImage错误!\n");
	//	return false;
	//}
	//namedWindow("原图");
	//imshow("原图", srcImage);
	//cvtColor(srcImage, dstImage, CV_RGB2HSV);
	//Mat hsvChannels[3];
	//split(dstImage, hsvChannels);
	//Mat HChannelDisplay;
	//Mat SChannelDisplay;
	//Mat VChannelDisplay;

	//HChannelDisplay = hsvChannels[0];
	//SChannelDisplay = hsvChannels[1];
	//VChannelDisplay = hsvChannels[2];

	//namedWindow("H_channel");
	//imshow("H_channel", HChannelDisplay);

	//namedWindow("S_channel");
	//imshow("S_channel", SChannelDisplay);

	//namedWindow("V_channel");
	//imshow("V_channel", VChannelDisplay);



#pragma endregion
        
        #pragma region 思考题3
	/*载入图像*/
	srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验1 基于OpenCV的图像增强\\3.jpg");
	if (!srcImage.data)
	{
		printf("读取srcImage错误!\n");
		return false;
	}
	namedWindow("原图");
	imshow("原图", srcImage);
	Mat srcImage_pseudocolor;
	cvtColor(srcImage, srcImage_pseudocolor, COLOR_BGR2HSV);

	//Mat srcImage_pseudocolor=Mat::zeros(srcImage.size(), CV_8UC3);
	//int tmp = 0;
	//for (int y = 0; y < srcImage.rows; y++)
	//{
	//	for (int x = 0; x < srcImage.cols; x++)
	//	{
	//		tmp = srcImage.at<unsigned char>(y, x);
	//		srcImage_pseudocolor.at<Vec3b>(y, x)[0] = (155 - tmp);
	//		srcImage_pseudocolor.at<Vec3b>(y, x)[1] = (27 - tmp);
	//		srcImage_pseudocolor.at<Vec3b>(y, x)[2] = (0- tmp);

	//	}

	//}
	namedWindow("srcImage_pseudocolor");
	imshow("srcImage_pseudocolor", srcImage_pseudocolor);






#pragma endregion




	waitKey(0);
}

void on_Trackbar(int, void*)
{
	float fGamma = (float)g_fGammaValueSlider / 50;
	Mat GammaImage;

	unsigned char lut[256];
	for (int i = 0; i < 256; i++)
	{
		lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0), fGamma)*255.0f);
	}

	GammaImage = srcImage.clone();

	MatIterator_<Vec3b>it,end; 
		
	for ( it = GammaImage.begin<Vec3b>(),end=GammaImage.end<Vec3b>(); it!=end;it++)
	{
		(*it)[0] = lut[((*it)[0])];
		(*it)[1] = lut[((*it)[1])];
		(*it)[2] = lut[((*it)[2])];

	}
	imshow("伽马矫正", GammaImage);

}

///*亮度与对比度回调函数*/
void on_BrightnessAndContrast(int, void*)
{

	for (int y = 0; y < srcImage.rows;  y++ )
	{
		for (int x = 0; x < srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
			
				dstImage.at<Vec3b>(y, x)[c] = saturate_cast<char>(g_fContrastValueSlider*0.01*srcImage.at<Vec3b>(y, x)[c] + g_fBrightnessValueSlider);
				
			}
		
		}

	}

	imshow("亮度对比度调整", dstImage);
}




