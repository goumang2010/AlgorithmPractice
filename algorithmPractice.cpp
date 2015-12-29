// algorithmPractice.cpp : 定义 DLL 应用程序的导出函数。
//

#include "Mypractice.h"
#include "stdafx.h"
#include <vector>

using namespace std;
namespace AlgorithmPractice
{
	

	
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

}
