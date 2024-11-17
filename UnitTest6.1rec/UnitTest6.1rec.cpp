// Тестовий файл: TestLab6_1rec.cpp
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.1rec/lab6.1rec.cpp" // Замість цього шляху вкажіть ваш шлях до файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab6_1rec
{
	TEST_CLASS(UnitTestLab6_1rec)
	{
	public:

		// Тест на перевірку функції generateArrayRecursive
		TEST_METHOD(TestGenerateArrayRecursive)
		{
			const int size = 10;
			int array[size] = { 0 };

			// Виклик функції генерації
			generateArrayRecursive(array, size);

			// Перевірка, що масив згенеровано
			for (int i = 0; i < size; ++i)
			{
				if (i % 5 == 0)
				{
					Assert::IsTrue(array[i] >= -20 && array[i] <= -1, L"Element not in expected negative range");
				}
				else
				{
					Assert::IsTrue(array[i] >= 1 && array[i] <= 50, L"Element not in expected positive range");
				}
			}
		}

		// Тест на перевірку функції processArrayRecursive
		TEST_METHOD(TestProcessArrayRecursive)
		{
			const int size = 10;
			int array[size] = { -15, 20, 10, 25, 30, -18, 40, 50, 45, -5 }; // Тестовий масив
			int count = 0, sum = 0;

			// Очікувані результати
			int expectedCount = 9;
			int expectedSum = 187;

			// Виклик функції обробки
			processArrayRecursive(array, size, count, sum);

			// Перевірка результатів
			Assert::AreEqual(expectedCount, count, L"Count mismatch");
			Assert::AreEqual(expectedSum, sum, L"Sum mismatch");

			// Перевірка, що елементи, які відповідають умові, замінено на 0
			for (int i = 0; i < size; ++i)
			{
				if ((i % 5 == 0 && -20 <= array[i] && array[i] <= -1) ||
					(i % 5 != 0 && 1 <= array[i] && array[i] <= 50))
				{
					Assert::AreEqual(0, array[i], L"Element not set to 0");
				}
			}
		}
	};
}
