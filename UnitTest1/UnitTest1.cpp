#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_rec/FileName.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 2;
            const int colCount = 2;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                a[i] = new int[colCount];
            }
            a[0][0] = 1;
            a[0][1] = 10;
            a[1][0] = 5;
            a[1][1] = 7;
            int max = 0;
            int maxx = 7;
            Find(a, rowCount, max, 0);
            Assert::AreEqual(max, maxx);

        }
    };
}
