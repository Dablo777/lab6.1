void processArray(int* array, int size, int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < size; ++i) {
        // Перевіряємо умови
        if ((i % 5 == 0 && array[i] < 0) || (i % 5 != 0 && array[i] > 0)) {
            sum += array[i];
            count++;
            array[i] = 0; // Замінюємо елемент на нуль
        }
    }
}


