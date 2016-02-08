
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Mypractice.h"
//#pragma comment(lib, "algorithmPractice.lib")
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace AlgorithmPractice;


namespace AlgorithmPracticeTest
{		
	
	TEST_CLASS(UnitTest1)
	{
	public:

	
		TEST_METHOD(onlineAlgoTest)
		{
			const vector<int> testarray = { 1,2,-3,-4,5,5,-1,6,-6,7 };
			int x = onlineAlgo( testarray);
			Assert::AreEqual(x, 16);
		}


		TEST_METHOD(CheckIfAlldiff_1TEST)
		{
			string str1 = "zxcvbnmloikjuhygtfrdewsqa";
			string str2 = "zxcvbnmmloikjuhygtfrdewsqa";
			Assert::AreEqual(CheckIfAlldiff_1(str1), true);
			Assert::AreEqual(CheckIfAlldiff_1(str2), false);

			


		}
		TEST_METHOD(CheckIfAlldiff_2TEST)
		{
			string str1 = "zxcvbnmloikjuhygtfrdewsqa";
			string str2 = "zxcvbnmmloikjuhygtfrdewsqa";

			Assert::AreEqual(CheckIfAlldiff_2(str1), true);
			Assert::AreEqual(CheckIfAlldiff_2(str2), false);



		}
		



		

	};








	
}