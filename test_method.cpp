
#include "stdafx.h"
#include "Mypractice.h"
#include <vector>
using namespace std;
namespace AlgorithmPractice
{
	void getRandVector(vector<int> & a,int n)
	{

		for (int i = 0; i < n; i++)
		{
			a.push_back(rand());
		}

	}
	void getSortedVector(vector<int> & a,int n)
	{

		getRandVector(a, n);
		QuickSort(a, 0, n - 1);
	}

}
