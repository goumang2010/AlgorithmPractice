
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
		void getArray(vector<int> & a)
		{

			for (int i = 0; i < 2000; i++)
			{
				a.push_back(rand());
			}
	
			//OutputDebugString((LPCWSTR)outputstr);
		}

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


		TEST_METHOD(sorttest)
		{
			std::vector<int> a ;
			getArray(a);
			int length = a.size();
			//复制vector
			std::vector<int> b(a);
			//插入排序
			InsertSort(a);
			//快速排序
			QuickSort(b,0, length-1);	
			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(a[i], b[i]);

			}
		}




	};


}