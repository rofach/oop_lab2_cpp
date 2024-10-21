#include "pch.h"
#include "CppUnitTest.h"
#include "../matrix/MyMatrix.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestMul)
	{
		void delArr(double** arr, int rows) {
			for (int i = 0; i < rows; i++)
				delete[] arr[i];
			delete[] arr;
		}
		TEST_METHOD(MultiplyExep) {
			double** d_arr1 = new double* [3]
			{
				new double[3] {1, 2, 3},
				new double[3] {2, 2, 3},
				new double[3] {0, 2, 3},
			};

			double** d_arr2 = new double* [2] 
			{
				new double[3] {2, 2, 5},
				new double[3] {1, 2, 3}
			};

			MyMatrix matrix1(d_arr1, 3, 3);
			MyMatrix matrix2(d_arr2, 2, 3);

			delArr(d_arr1, 3);
			delArr(d_arr2, 2);

			try {
				MyMatrix matrix3(matrix1 * matrix2);
				Assert::Fail(L"there is no exception");
			}
			catch(char* e){
				Assert::AreEqual("impossible", e);
			}

			

		}

		TEST_METHOD(Multiply3x4and4x3) {
			double** d_arr1 = new double* [3]
			{
				new double[4] {1, 2, 3, 2},
				new double[4] {2, 3, 0, 2},
				new double[4] {3, 2, 2, 2},
			};

			double** d_arr2 = new double* [4]
			{
				new double[3] {2, 2, 5},
				new double[3] {1, 2, 3},
				new double[3] {3, 4, 1},
				new double[3] {3, 2, 1}
			};

			MyMatrix matrix1(d_arr1, 3, 4);
			MyMatrix matrix2(d_arr2, 4, 3);

			MyMatrix matrix3(matrix1*matrix2);

			double** exp = new double* [3] {
				new double[3] {19, 22, 16},
				new double[3] {13, 14, 21},
				new double[3] {20, 22, 25}
			};


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Assert::AreEqual(matrix3(i, j), exp[i][j]);
				}
			}

			delArr(d_arr1, 3);
			delArr(d_arr2, 4);
		}


		TEST_METHOD(Multiply4x3and3x4) {
			double** d_arr1 = new double* [4]
				{
					new double[3] {1, 2, 3},
					new double[3] {2, 2, 3},
					new double[3] {0, 2, 3},
					new double[3] {2, 2, 2}
				};

			double** d_arr2 = new double* [3]
				{
					new double[4] {2, 2, 5, 1},
					new double[4] {2, 3, 3, 4},
					new double[4] {1, 3, 2, 1},
				};

			MyMatrix matrix1(d_arr1, 4, 3);
			MyMatrix matrix2(d_arr2, 3, 4);

			MyMatrix matrix3(matrix1 * matrix2);

			double** exp = new double* [4]
			{
				new double[4] {9,17,17,	12},
				new double[4] {11,19,22,13},
				new double[4] {7,15,12,11},
				new double[4] {10,16,20,12}
			};


			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::AreEqual(matrix3(i, j), exp[i][j]);
				}
			}

			delArr(d_arr1, 4);
			delArr(d_arr2, 3);
		}
	};
}