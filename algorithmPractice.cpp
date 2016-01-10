// algorithmPractice.cpp : 定义 DLL 应用程序的导出函数。
//

#include "Mypractice.h"
#include "stdafx.h"
#include <vector>

using namespace std;
namespace AlgorithmPractice
{
	

	//联机算法找出求和最大的子向量
	 int  onlineAlgo(const vector<int> & a)
	 {
		 int maxSum = 0, thisSum = 0;
		 for (int i = 0; i < a.size(); i++)
		 {
			 thisSum += a[i];
			 if (thisSum > maxSum)
			 {
				 maxSum = thisSum;
			 }
			 //If the value is both smaller than MaxSum and below 0,then abandon the value and restart the record.
			 //At this time the MaxSum has been recorded.
			 else if (thisSum < 0)
			 {
				 thisSum = 0;
			 }

		 }

		 return maxSum;
	 }
	 //判断一个字符串是否所有的字符都不同

	 bool CheckIfAlldiff_1(string str)
	 {
		 int strcount = str.size();
		 for (int i = 0; i < strcount; i++)
		 {
			 char ch = str[i];
			 for (int j = i + 1; j < strcount; j++)
			 {
				 if (ch == str[j])
				 {
					 return false;
				 }
			 }
		 }
		 return true;
	 }
	 bool CheckIfAlldiff_2(string str)
	 {
		 //判断字符串大小
		 int strcount = str.size();
		 if (strcount > 256) return false;
		 bool map[256];
		 memset(map, false, 256);
		 for (int i = 0; i < strcount; i++)
		 {
			 int index = str[i] - 0;
			 if (map[index])
			 {
				 return false;
			 }
			 else

			 {
				 map[index] = true;
			 }
		 }
		 return true;


	 }
}
