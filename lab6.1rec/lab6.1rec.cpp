#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

// Рекурсивна функція для генерації масиву
void generateArrayRecursive(int* array, int size, int index = 0) {
    if (index >= size) return; // Базовий випадок: якщо індекс виходить за межі розміру

    srand(static_cast<unsigned int>(time(0)) + index); // Ініціалізуємо генератор випадкових чисел із унікальним seed

    if (index % 5 == 0) {
        // Якщо індекс кратний 5, беремо випадкове від'ємне число від -20 до -1
        array[index] = -(rand() % 20 + 1);
    }
    else {
        // Якщо індекс не кратний 5, беремо випадкове додатне число від 1 до 50
        array[index] = rand() % 50 + 1;
    }

    // Рекурсивно викликаємо для наступного індексу
    generateArrayRecursive(array, size, index + 1);
}

// Рекурсивна функція для обробки масиву
void processArrayRecursive(int* array, int size, int& count, int& sum, int index = 0) {
    if (index >= size) return; // Базовий випадок: якщо індекс виходить за межі розміру

    // Перевіряємо умови
    if ((index % 5 == 0 && array[index] < 0) || (index % 5 != 0 && array[index] > 0)) {
        sum += array[index];
        count++;
        array[index] = 0; // Замінюємо елемент на нуль
    }

    // Рекурсивно обробляємо наступний індекс
    processArrayRecursive(array, size, count, sum, index + 1);
}

int main() {
    const int size = 20;
    int array[size];

    // Викликаємо рекурсивну функцію генерації
    generateArrayRecursive(array, size);

    // Виводимо згенерований масив
    std::cout << "Generated Array: [";
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(2) << array[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl << std::endl;

    int count = 0;
    int sum = 0;

    // Викликаємо рекурсивну функцію обробки
    processArrayRecursive(array, size, count, sum);

    // Виводимо кількість та суму елементів, що відповідають критерію
    std::cout << "Amount of elements, that satisfy condition: " << count << std::endl << std::endl;
    std::cout << "Sum of elements, that satisfy condition: " << sum << std::endl << std::endl;

    // Виводимо модифікований масив
    std::cout << "Array after exchange: [";
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(2) << array[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl << std::endl;

    return 0;
}
