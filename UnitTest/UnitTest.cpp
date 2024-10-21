#include "pch.h"
#include "CppUnitTest.h"
//#include "../matrix/MyMatrix.h"
#include "../matrix/MyMatrix.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*
TEST_CLASS(Class1)
{
public:
	Class1()
	{
		Logger::WriteMessage("In Class1");
	}
	~Class1()
	{
		Logger::WriteMessage("In ~Class1");
	}



	TEST_CLASS_INITIALIZE(ClassInitialize)
	{
		Logger::WriteMessage("In Class Initialize");
	}
	TEST_CLASS_CLEANUP(ClassCleanup)
	{
		Logger::WriteMessage("In Class Cleanup");
	}


	BEGIN_TEST_METHOD_ATTRIBUTE(Method1)
		TEST_OWNER(L"OwnerName")
		TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(Method1)
	{
		Logger::WriteMessage("In Method1");
		Assert::AreEqual(0, 0);
	}

	TEST_METHOD(Method2)
	{
		Assert::Fail(L"Fail");
	}
};
*/
namespace UnitTest
{
	TEST_CLASS(UnitTestDet)
	{
	private:
		void delArr(double** arr, int rows) {
			for (int i = 0; i < rows; i++)
				delete[] arr[i];
			delete[] arr;
		}
	public:
		TEST_METHOD(det140)
		{
			double** d_arr = new double*[4]
			{
			new double[4]{1, 2, 3, 4},
			new double[4] {2, 2, 3, 1},
			new double[4] {4, 8, 2, 1},
			new double[4] {3, 0, 2, 1}
			};
			 
			MyMatrix matrix(d_arr, 4, 4);
			int det = matrix.calcDeterminant();
			int exp = 140;
			Assert::AreEqual(exp, det);

			delArr(d_arr, 4);
		}

		TEST_METHOD(det62)
		{
			double** d_arr = new double*[4]
			{
			new double[4] {0, 2, 3, 4},
			new double[4] {2, 0, 3, 1},
			new double[4] {4, 8, 0, 1},
			new double[4] {3, 0, 2, 0}
			};

			MyMatrix matrix(d_arr, 4, 4);
			int det = matrix.calcDeterminant();
			int exp = 62;
			Assert::AreEqual(exp, det);

			delArr(d_arr, 4);
		}

		TEST_METHOD(det0)
		{
			double** d_arr = new double* [4]
			{
			new double[4] {1, 1, 1, 1},
			new double[4] {2, 0, 3, 1},
			new double[4] {4, 8, 0, 1},
			new double[4] {2, 2, 2, 2}
			};

			MyMatrix matrix(d_arr, 4, 4);
			int det = matrix.calcDeterminant();
			int exp = 0;
			Assert::AreEqual(exp, det);

			delArr(d_arr, 4);
		}

		TEST_METHOD(detn88)
		{
			double** d_arr = new double* [4]
			{
			new double[4] {0, 0, 1, 1},
			new double[4] {2, 0, 0, 1},
			new double[4] {4, 8, 0, 0},
			new double[4] {2, 2, 5, 0}
			};
			
			MyMatrix matrix(d_arr, 4, 4);
			int det = matrix.calcDeterminant();
			int exp = -88;
			Assert::AreEqual(exp, det);

			delArr(d_arr, 4);
		}
	};
}
