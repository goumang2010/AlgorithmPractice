#include "Mypractice.h"
#include "stdafx.h"
#include <vector>
using namespace std;
namespace AlgorithmPractice
{
	//二分查找法
	//返回要查找的值的索引，若没有，则返回-1
	//要求的前提是有序表
	//通过不断的取中值判断待查找值所占范围，每次都能缩小一半的查找范围
	int BinarySearch(vector<int> & a, int & searchint, int start, int end)
	{
		int left = start;
		int right = end;
		while (left <= right)
		{
			int midi = (left+right) / 2;
			int mid = a[midi];
			if (mid == searchint)
			{
				return midi;
			}
			else
			{
				if (mid > searchint)
				{
					//若使用递归，别忘了要直接返回递归分支的返回值
					//return	BinarySearch(a, searchint, start, midi - 1);
					//可直接把递归塌缩成while循环
					right = midi - 1;
				}
				else
				{
					//return	BinarySearch(a, searchint, midi + 1, end);
					left = midi + 1;
				}
			}
		}
		return -1;
	}
}