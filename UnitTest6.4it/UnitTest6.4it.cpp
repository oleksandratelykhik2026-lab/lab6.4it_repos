#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4it/lab6.4it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            double a[] = { -2, 4, -5, 3, 6 };
            Assert::AreEqual(9.0, SumAfterMinimum(a, 5), 0.0001);
        }

        TEST_METHOD(TestMinimumIsLast)
        {
            double a[] = { 3, 2, -4 };
            Assert::AreEqual(0.0, SumAfterMinimum(a, 3), 0.0001);
        }

        TEST_METHOD(TestSortOddPositionsByAbs)
        {
            double a[] = { -5, 10, 2, 20, 0, 30, -1 };

            SortOddPositionsByAbs(a, 7);

            double expected[] = { 0, 10, -1, 20, 2, 30, -5 };

            for (int i = 0; i < 7; i++)
                Assert::AreEqual(expected[i], a[i], 0.0001);
		}
	};
}