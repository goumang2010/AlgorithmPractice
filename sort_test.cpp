
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
	TEST_CLASS(SortTest)
	{
	public:

		string * convetToStr(vector<int> a)
		{
			string str = "";
			int length = a.size();
			for (int i = 0; i < length; i++)
			{
				char tmp[10];
				sprintf(tmp, "%d", a[i]);
				str = str + tmp + ";";
			}
			return &str;
		}


		TEST_METHOD(insert_sorttest)
		{
			std::vector<int> a;
			getRandVector(a);
			int length = a.size();
			InsertSort(a);
			for (int i = 0; i < length - 1; i++)
			{
				Assert::IsTrue(a[i] <= a[i + 1]);

			}

		}
		TEST_METHOD(quick_sorttest)
		{
			std::vector<int> a;
			getRandVector(a);
			int length = a.size();
			QuickSort(a, 0, length - 1);
			for (int i = 0; i < length-1; i++)
			{
				Assert::IsTrue(a[i]<=a[i+1]);

			}

		}




	};


}