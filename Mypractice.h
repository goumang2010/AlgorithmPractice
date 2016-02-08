#pragma once
#include <vector>
using namespace std;
//extern int  onlineAlgo(const std::vector<int> & a);
namespace AlgorithmPractice
{
	extern int  onlineAlgo(const vector<int> & a);
	extern bool CheckIfAlldiff_1(string str);
	extern bool CheckIfAlldiff_2(string str);
	extern void InsertSort(vector<int> & a);
	extern void QuickSort(vector<int> & a, int start, int end);
}