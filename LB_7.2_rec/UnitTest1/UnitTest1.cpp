#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_7.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreate)
		{
            int matrix[MAX_SIZE][MAX_SIZE];
            generateMatrix(matrix, 0, 0, 5, 5);
            Assert::IsTrue(matrix[0][0] >= 1 && matrix[0][0] <= 100);
        }

        TEST_METHOD(TestMaxInRow)
        {
            int matrix[MAX_SIZE][MAX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
            int max = maxInRow(matrix, 0, 0, 3, INT_MIN);
            Assert::AreEqual(3, max);
        }

        TEST_METHOD(TestSumMaxInEvenRows)
        {
            int matrix[MAX_SIZE][MAX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
            int sum = sumMaxInEvenRows(matrix, 0, 3, 3, 0);
            Assert::AreEqual(12, sum);
        }
	};
}