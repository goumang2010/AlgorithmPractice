#include "Mypractice.h"
#include "stdafx.h"
#include <vector>
using namespace std;
namespace AlgorithmPractice
{
	int getPivot(vector<int> & a, int ia, int ib);
	void swapEle(vector<int> & a, int ia, int ib);
	//插入排序，使无序数组变为从小到大排序的数组
	//使用递归，设想将某一元素插入到已排序的队列中，形成新的已排序队列，如此往复
	//将待插入的元素与数组中的队列由大到小一一比较，出现比其小的元素，则插入到后面，比起大的元素的索引一一后移
	void InsertSort(vector<int> & a)
	{
		int count = a.size();
		if (count <= 1)
		{
			return;
		}
		for (int i = 1; i < count; i++)
		{
			//递归逻辑
			//待插入的元素
			int tmp = a[i];
			int k = i - 1;
			for (; k >= 0 && a[k] > tmp; k--)
			{
				a[k + 1] = a[k];
			}
			//当前k为-1或者k已小于tmp
			a[k + 1] = tmp;
		}
	}

	//快速排序
	//定义一项操作，使得以pivot为界，将数组分为两组，后一组元素比前一组的每个元素都要大
	//继续对每组进行重复这样的操作，直到分无可分（每组只剩下一个元素），即完成了整个排序
	//将pivot选为两边元素和中间元素的中值
	//使用递归
	void QuickSort(vector<int> & a, int start, int end)
	{
		int diff = end - start;
		//当有0个或1个元素时，直接返回
		if (diff <= 0)
		{
			return;
		}
		else
		{
			//
			if (diff == 1 || diff == 2)
			{
				getPivot(a, start, end);
				return;
			}
		}
		//确定锚点
		//此时锚点已经放置到end-1的位置
		int pivot = getPivot(a, start, end);
		//使用两个游标j,k在[start+1,end-2]范围内分别游走，当j>=k时表示游历完成
		//游标分别寻找大于和小于pivot的位置，然后交换
		//当结束时，jk会分别位于第一个大于/小于pivot的元素上
		int j = start + 1;
		int k = end - 2;
		while (1)
		{
			//找到第一个不符合要求的元素
			//不需要担心越界，因为左右各自有比pivot小/大的数
			while (a[j] < pivot)
			{
				j++;
			}
			//无需考虑等号，留在原地，其会最终靠在一起
			while (a[k] > pivot)
			{
				k--;
			}
			if (j >= k)
			{
				break;
			}
			else
			{
				swapEle(a, j, k);
			}
		}
		//此时j的位置为第一个大于pivot的元素，把它和右边end-1位置上的pivot交换
		swapEle(a, j, end - 1);
		//这样pivot恰好位于中间位置，把数组分为[start,j-1][j+1,end]两部分
		//使用递归，分别进行同样的操作
		QuickSort(a, start, j - 1);
		QuickSort(a, j + 1, end);
	}
	//交换数组中两个元素的位置
	void swapEle(vector<int> & a, int ia, int ib)
	{
		int tmp = a[ia];
		a[ia] = a[ib];
		a[ib] = tmp;
	}
	//确定pivot
	int getPivot(vector<int> & a, int ia, int ib)
	{
		int midi = (ia + ib) / 2;
		//比较左边和中间，确保左边相对小
		if (a[ia] > a[midi])
		{
			swapEle(a, ia, midi);
		}
		//比较左边和右边，确保左边相对小
		if (a[ia] > a[ib])
		{
			swapEle(a, ia, ib);
		}
		//比较中间和右边，确保中间相对小
		if (a[midi] > a[ib])
		{
			swapEle(a, midi, ib);
		}
		//此时midi处的值选为pivot，但面临的问题是：
		//1. pivot最终索引位置不确定
		//2.可以确定的是ia，ib的元素位置都不需要再变动
		//故先把pivot放于ib-1的位置，待分组完全后，再把其放到最终的中间位置
		swapEle(a, midi, ib - 1);
		return a[ib - 1];
	}
}