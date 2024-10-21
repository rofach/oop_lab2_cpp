#include "pch.h"
#include "CppUnitTest.h"
#include "../matrix/MyMatrix.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestAdd)
	{	
	private:
		void delArr(double** arr, int rows) {
			for (int i = 0; i < rows; i++)
				delete[] arr[i];
			delete[] arr;
		}
	public:
		TEST_METHOD(Add)
		{
			double** d_arr1 = new double* [4]
			{
			new double[3]{1, 2, 3},
			new double[3]{2, 2, 3},
			new double[3]{4, 8, 2},
			new double[3]{3, 0, 2}
			};
			double** d_arr2 = new double* [4]
			{
			new double[3]{1, 2, 3},
			new double[3]{2, 2, 3},
			new double[3]{4, 8, 2},
			new double[3]{3, 0, 2}
			};

			MyMatrix matrix1(d_arr1, 4, 3);
			MyMatrix matrix2(d_arr2, 4, 3);

			MyMatrix matrix3(matrix1 + matrix2);

			double exp[4][3] =
			{
			{2, 4, 6},
			{4, 4, 6},
			{8, 16, 4},
			{6, 0, 4}
			};

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++) {
					Assert::AreEqual(exp[i][j], matrix3(i,j));
				}
			}
			
			delArr(d_arr1, 4);
			delArr(d_arr2, 4);
		}
	};
}
