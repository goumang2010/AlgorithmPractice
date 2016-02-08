
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Mypractice.h"
#include "windows.h"
//#pragma comment(lib, "algorithmPractice.lib")
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace AlgorithmPractice;


namespace AlgorithmPracticeTest
{
	TEST_CLASS(SearchTest)
	{
		TEST_METHOD(binary_searchtest)
		{
			vector<int> a ;
			getSortedVector(a,10);
			for (int i = 0; i < 10; i++)
			{
				Assert::IsTrue(a[BinarySearch(a, a[i], 0, 9)] == a[i]);
			}
		}


	};
}