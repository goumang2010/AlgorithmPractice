#include "Mypractice.h"
#include "stdafx.h"
#include <vector>
using namespace std;
namespace AlgorithmPractice
{
	//���ֲ��ҷ�
	//����Ҫ���ҵ�ֵ����������û�У��򷵻�-1
	//Ҫ���ǰ���������
	//ͨ�����ϵ�ȡ��ֵ�жϴ�����ֵ��ռ��Χ��ÿ�ζ�����Сһ��Ĳ��ҷ�Χ
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
					//��ʹ�õݹ飬������Ҫֱ�ӷ��صݹ��֧�ķ���ֵ
					//return	BinarySearch(a, searchint, start, midi - 1);
					//��ֱ�Ӱѵݹ�������whileѭ��
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