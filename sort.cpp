#include "Mypractice.h"
#include "stdafx.h"
#include <vector>
using namespace std;
namespace AlgorithmPractice
{
	int getPivot(vector<int> & a, int ia, int ib);
	void swapEle(vector<int> & a, int ia, int ib);
	//��������ʹ���������Ϊ��С�������������
	//ʹ�õݹ飬���뽫ĳһԪ�ز��뵽������Ķ����У��γ��µ���������У��������
	//���������Ԫ���������еĶ����ɴ�Сһһ�Ƚϣ����ֱ���С��Ԫ�أ�����뵽���棬������Ԫ�ص�����һһ����
	void InsertSort(vector<int> & a)
	{
		int count = a.size();
		if (count <= 1)
		{
			return;
		}
		for (int i = 1; i < count; i++)
		{
			//�ݹ��߼�
			//�������Ԫ��
			int tmp = a[i];
			int k = i - 1;
			for (; k >= 0 && a[k] > tmp; k--)
			{
				a[k + 1] = a[k];
			}
			//��ǰkΪ-1����k��С��tmp
			a[k + 1] = tmp;
		}
	}

	//��������
	//����һ�������ʹ����pivotΪ�磬�������Ϊ���飬��һ��Ԫ�ر�ǰһ���ÿ��Ԫ�ض�Ҫ��
	//������ÿ������ظ������Ĳ�����ֱ�����޿ɷ֣�ÿ��ֻʣ��һ��Ԫ�أ������������������
	//��pivotѡΪ����Ԫ�غ��м�Ԫ�ص���ֵ
	//ʹ�õݹ�
	void QuickSort(vector<int> & a, int start, int end)
	{
		int diff = end - start;
		//����0����1��Ԫ��ʱ��ֱ�ӷ���
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
		//ȷ��ê��
		//��ʱê���Ѿ����õ�end-1��λ��
		int pivot = getPivot(a, start, end);
		//ʹ�������α�j,k��[start+1,end-2]��Χ�ڷֱ����ߣ���j>=kʱ��ʾ�������
		//�α�ֱ�Ѱ�Ҵ��ں�С��pivot��λ�ã�Ȼ�󽻻�
		//������ʱ��jk��ֱ�λ�ڵ�һ������/С��pivot��Ԫ����
		int j = start + 1;
		int k = end - 2;
		while (1)
		{
			//�ҵ���һ��������Ҫ���Ԫ��
			//����Ҫ����Խ�磬��Ϊ���Ҹ����б�pivotС/�����
			while (a[j] < pivot)
			{
				j++;
			}
			//���迼�ǵȺţ�����ԭ�أ�������տ���һ��
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
		//��ʱj��λ��Ϊ��һ������pivot��Ԫ�أ��������ұ�end-1λ���ϵ�pivot����
		swapEle(a, j, end - 1);
		//����pivotǡ��λ���м�λ�ã��������Ϊ[start,j-1][j+1,end]������
		//ʹ�õݹ飬�ֱ����ͬ���Ĳ���
		QuickSort(a, start, j - 1);
		QuickSort(a, j + 1, end);
	}
	//��������������Ԫ�ص�λ��
	void swapEle(vector<int> & a, int ia, int ib)
	{
		int tmp = a[ia];
		a[ia] = a[ib];
		a[ib] = tmp;
	}
	//ȷ��pivot
	int getPivot(vector<int> & a, int ia, int ib)
	{
		int midi = (ia + ib) / 2;
		//�Ƚ���ߺ��м䣬ȷ��������С
		if (a[ia] > a[midi])
		{
			swapEle(a, ia, midi);
		}
		//�Ƚ���ߺ��ұߣ�ȷ��������С
		if (a[ia] > a[ib])
		{
			swapEle(a, ia, ib);
		}
		//�Ƚ��м���ұߣ�ȷ���м����С
		if (a[midi] > a[ib])
		{
			swapEle(a, midi, ib);
		}
		//��ʱmidi����ֵѡΪpivot�������ٵ������ǣ�
		//1. pivot��������λ�ò�ȷ��
		//2.����ȷ������ia��ib��Ԫ��λ�ö�����Ҫ�ٱ䶯
		//���Ȱ�pivot����ib-1��λ�ã���������ȫ���ٰ���ŵ����յ��м�λ��
		swapEle(a, midi, ib - 1);
		return a[ib - 1];
	}
}