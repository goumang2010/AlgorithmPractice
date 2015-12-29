
#include "stdafx.h"
#include "CppUnitTest.h"

#include "Mypractice.h"
//#pragma comment(lib, "algorithmPractice.lib")
//extern "C" _declspec(dllimport) int Add(int a, int b);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace AlgorithmPractice;


namespace AlgorithmPracticeTest
{		
	
	TEST_CLASS(UnitTest1)
	{
	public:

	
		TEST_METHOD(TestMethod1)
		{
			vector<int> testarray = { 1,2,3,4,5,556,6,7 };

			int x = testMethod(3);


			Assert::AreEqual(x, 5);
		}

		

	};








	
}