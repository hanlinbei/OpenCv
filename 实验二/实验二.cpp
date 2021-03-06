// 实验二.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/photo/photo.hpp>
//#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

#define WINDOW_NAME0 "原始图"
#define WINDOW_NAME1 "中值滤波"
#define WINDOW_NAME2 "修补后的效果图"

Mat srcImage, medianBlurImage, inpaintMask;
Point previousPoint(-1, -1);

static void On_Mouse(int event, int x, int y, int flags, void*);
uchar adaptiveProcess(const Mat &im, int row, int col, int kernelSize, int maxSize);
 

int main()
{
		#pragma region 实验2
		 //    srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验2 基于OpenCV的图像恢复\\1.jpg",-1);
			//if (!srcImage.data)
			//{
			//	printf("读取scrImage错误！\n");
			//	return false;
			//}

			////显示原始图
			//imshow(WINDOW_NAME0, srcImage);
			//srcImage = srcImage.clone();
			//medianBlurImage = srcImage.clone();
			//inpaintMask = Mat::zeros(medianBlurImage.size(), CV_8U);
			////中值滤波
			//medianBlur(srcImage , medianBlurImage, 7);
			////显示中值滤波图像
			//imshow(WINDOW_NAME1, medianBlurImage);
			////设置鼠标回调函数
			//setMouseCallback(WINDOW_NAME1, On_Mouse, 0);
			//while (1)
			//{
			//	//获取按键键值
			//	char c = (char)waitKey();

			//	//键值为ESC，程序退出
			//	if (c == 27)
			//	{
			//		break;
			//	}
			//	//键值为1进行图像修补操作
			//	if (c == '1')
			//	{
			//		Mat inpaintedImage;
			//		inpaint(medianBlurImage, inpaintMask, inpaintedImage, 3, CV_INPAINT_TELEA);
			//		imshow(WINDOW_NAME2, inpaintedImage);

			//	}


			//}

			//return 0;
		#pragma endregion

#pragma region 思考题1
			 srcImage = imread("E:\\研究生\\课程\\数字图像处理\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019（朱威班）\\数字图像处理实验手册及素材-基础实验-实验1-2--20181019\\实验2 基于OpenCV的图像恢复\\3(椒盐噪声5%).jpg", -1);
			if (!srcImage.data)
			{
				printf("读取scrImage错误！\n");
				return false;
			}

			//显示原始图
			imshow(WINDOW_NAME0, srcImage);
			srcImage = srcImage.clone();
		    //bilateralFilter(srcImage, medianBlurImage ,9, 75, 75);
			medianBlurImage = srcImage.clone();

			inpaintMask = Mat::zeros(medianBlurImage.size(), CV_8U);
		
			

			int minSize =1; // 滤波器窗口的起始尺寸
			int maxSize = 7; // 滤波器窗口的最大尺寸
			// 扩展图像的边界
			copyMakeBorder(srcImage, medianBlurImage, maxSize / 2, maxSize / 2, maxSize / 2, maxSize / 2, BorderTypes::BORDER_REFLECT);
			// 图像循环
			for (int j = maxSize / 2; j < medianBlurImage.rows - maxSize / 2; j++)
			{		
				for (int i = maxSize / 2; i < medianBlurImage.cols * medianBlurImage.channels() - maxSize / 2; i++)
				{
					medianBlurImage.at<uchar>(j, i) = adaptiveProcess(medianBlurImage, j, i, minSize, maxSize);
				}
			}
			//显示中值滤波图像
			imshow(WINDOW_NAME1, medianBlurImage);

#pragma endregion


	cvWaitKey(0);
}

uchar adaptiveProcess(const Mat &im, int row, int col, int kernelSize, int maxSize)
{
	vector<uchar> pixels;
	for (int a = -kernelSize / 2; a <= kernelSize / 2; a++)
		for (int b = -kernelSize / 2; b <= kernelSize / 2; b++)
		{
			pixels.push_back(im.at<uchar>(row + a, col + b));
		}
	sort(pixels.begin(), pixels.end());
	auto min = pixels[0];
	auto max = pixels[kernelSize * kernelSize - 1];
	auto med = pixels[kernelSize * kernelSize / 2];
	auto zxy = im.at<uchar>(row, col);
	if (med > min && med < max)
	{
		// to B
		if (zxy > min && zxy < max)
			return zxy;
		else
			return med;
	}
	else
	{
		kernelSize += 2;
		if (kernelSize <= maxSize)
			return adaptiveProcess(im, row, col, kernelSize, maxSize); // 增大窗口尺寸，继续A过程。
		else
			return med;
	}
}


static void On_Mouse(int event, int x, int y, int flags, void*)
{
	//鼠标左键弹起消息
	if (event == CV_EVENT_LBUTTONUP || !(flags&CV_EVENT_FLAG_LBUTTON))
		previousPoint = Point(-1, -1);
	//鼠标左键按下消息
	else if (event == CV_EVENT_LBUTTONDOWN)
		previousPoint = Point(x, y);
	//鼠标按下并移动，进行绘制
	else if(event == CV_EVENT_MOUSEMOVE && (flags&CV_EVENT_FLAG_LBUTTON))
	{
		Point pt(x, y);
		if (previousPoint.x < 0)
			previousPoint = pt;
		//绘制白色线条
		line(inpaintMask, previousPoint, pt, Scalar::all(255), 5, 8, 0);
		line(medianBlurImage, previousPoint, pt, Scalar::all(255), 5, 8, 0);
		previousPoint = pt;
		imshow(WINDOW_NAME1,medianBlurImage);
	
	
	}
	
}