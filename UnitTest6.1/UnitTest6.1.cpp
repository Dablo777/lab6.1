#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.1/lab6.1.cpp" // Підключаємо головний файл з кодом

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

            // Генерація масиву
            generateArray(array, size);

            // Перевіряємо, що всі елементи знаходяться в межах [-20; 50]
            for (int i = 0; i < size; ++i) {
                Assert::IsTrue(array[i] >= -20 && array[i] <= 50, L"Element out of range!");
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            const int size = 5;
            int array[size] = { 5, 10, -15, 20, -25 }; // Тестовий масив
            int count = 0;
            int sum = 0;

            // Викликаємо функцію обробки
            processArray(array, size, count, sum);

            // Очікувані результати (налаштуйте залежно від умов функції `processArray`)
            int expectedCount = 2; // Наприклад, якщо враховуються тільки додатні елементи
            int expectedSum = 30;  // Сума елементів, які відповідають умовам (5 + 10 + 15)

            // Перевірка результатів
            Assert::AreEqual(expectedCount, count, L"Incorrect count!");
            Assert::AreEqual(expectedSum, sum, L"Incorrect sum!");
        }
    };
}
