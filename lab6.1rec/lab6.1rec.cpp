#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

// ���������� ������� ��� ��������� ������
void generateArrayRecursive(int* array, int size, int index = 0) {
    if (index >= size) return; // ������� �������: ���� ������ �������� �� ��� ������

    srand(static_cast<unsigned int>(time(0)) + index); // ���������� ��������� ���������� ����� �� ��������� seed

    if (index % 5 == 0) {
        // ���� ������ ������� 5, ������ ��������� ��'���� ����� �� -20 �� -1
        array[index] = -(rand() % 20 + 1);
    }
    else {
        // ���� ������ �� ������� 5, ������ ��������� ������� ����� �� 1 �� 50
        array[index] = rand() % 50 + 1;
    }

    // ���������� ��������� ��� ���������� �������
    generateArrayRecursive(array, size, index + 1);
}

// ���������� ������� ��� ������� ������
void processArrayRecursive(int* array, int size, int& count, int& sum, int index = 0) {
    if (index >= size) return; // ������� �������: ���� ������ �������� �� ��� ������

    // ���������� �����
    if ((index % 5 == 0 && array[index] < 0) || (index % 5 != 0 && array[index] > 0)) {
        sum += array[index];
        count++;
        array[index] = 0; // �������� ������� �� ����
    }

    // ���������� ���������� ��������� ������
    processArrayRecursive(array, size, count, sum, index + 1);
}

int main() {
    const int size = 20;
    int array[size];

    // ��������� ���������� ������� ���������
    generateArrayRecursive(array, size);

    // �������� ������������ �����
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

    // ��������� ���������� ������� �������
    processArrayRecursive(array, size, count, sum);

    // �������� ������� �� ���� ��������, �� ���������� �������
    std::cout << "Amount of elements, that satisfy condition: " << count << std::endl << std::endl;
    std::cout << "Sum of elements, that satisfy condition: " << sum << std::endl << std::endl;

    // �������� ������������� �����
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
