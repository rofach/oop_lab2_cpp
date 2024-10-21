#include "pch.h"
#include "CppUnitTest.h"
#include "../matrix/MyMatrix.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestTr)
	{
		TEST_METHOD(Transpose) {
			double** arr = new double* [2]
			{
				new double[3] {2, 5, 1},
				new double[3] {7, 3, 4}
			};

			MyMatrix matrix(arr, 2, 3);
			matrix.transposeMe();

			double exp[3][2]
			{
				{2, 7},
				{5, 3},
				{1, 4}
			};

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					Assert::AreEqual(exp[i][j], matrix(i, j));
				}
			}

		}
	};
}
