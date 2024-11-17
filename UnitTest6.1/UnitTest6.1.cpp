#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.1/lab6.1.cpp" // ϳ�������� �������� ���� � �����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab61
{
    TEST_CLASS(UnitTestLab61)
    {
    public:

        TEST_METHOD(TestGenerateArray)
        {
            const int size = 5;
            int array[size];

            // ��������� ������
            generateArray(array, size);

            // ����������, �� �� �������� ����������� � ����� [-20; 50]
            for (int i = 0; i < size; ++i) {
                Assert::IsTrue(array[i] >= -20 && array[i] <= 50, L"Element out of range!");
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            const int size = 5;
            int array[size] = { 5, 10, -15, 20, -25 }; // �������� �����
            int count = 0;
            int sum = 0;

            // ��������� ������� �������
            processArray(array, size, count, sum);

            // �������� ���������� (���������� ������� �� ���� ������� `processArray`)
            int expectedCount = 2; // ���������, ���� ������������ ����� ������ ��������
            int expectedSum = 30;  // ���� ��������, �� ���������� ������ (5 + 10 + 15)

            // �������� ����������
            Assert::AreEqual(expectedCount, count, L"Incorrect count!");
            Assert::AreEqual(expectedSum, sum, L"Incorrect sum!");
        }
    };
}
