#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

void generateArray(int* array, int size) {
    srand(static_cast<unsigned int>(time(0))); // ���������� ��������� ���������� �����

    for (int i = 0; i < size; ++i) {
        if (i % 5 == 0) {
            // ���� ������ ������� 5, ������ ��������� ��'���� ����� �� -20 �� -1
            array[i] = -(rand() % 20 + 1);
        }
        else {
            // ���� ������ �� ������� 5, ������ ��������� ������� ����� �� 1 �� 50
            array[i] = rand() % 50 + 1;
        }
    }
}


void processArray(int* array, int size, int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < size; ++i) {
        // ���������� �����
        if ((i % 5 == 0 && array[i] < 0) || (i % 5 != 0 && array[i] > 0)) {
            sum += array[i];
            count++;
            array[i] = 0; // �������� ������� �� ����
        }
    }
}



int main() {
    const int size = 20;
    int array[size];

    generateArray(array, size);

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
    processArray(array, size, count, sum);

    // �������� ������� �� ���� ��������, �� ���������� �������
    std::cout << "Amount of elements, that satisfy condition: " << count << std::endl<<std::endl;
    std::cout << "Sum of elements, that satisfy condition: " << sum << std::endl << std::endl;

    // �������� ������������� ����� � ������ ����� � ���� ������ ��������������
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
