#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void fillArray(int arr[], int N) {              // Рандомизатор чисел
    srand((unsigned)time(0));
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 10000;
    }
}

void printArray(int arr[], int N) {             // Вывод содержания массива
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int a[], int n) {               // Пузырьковая сортировка
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void insertionSort(int a[], int N) {            // Cортировка вставкой
    for (int i = 1; i < N; i++) {
        int buff = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > buff) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = buff;
    }
}

void selectionSort(int a[], int N) {            // Сортировка выбора
    int min, buf;
    for (int i = 0; i < N; i++) {
        min = i;
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        if (i != min) {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
}

void quicksort(int* mas, int first, int last) { // Быстрая сортировка
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2];
    do
    {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        if (f <= l) {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите число N: ";
    cin >> N;
    cout << endl;
    int* A = new int[N];
    fillArray(A, N);

    cout << "Исходный массив A: ";
    printArray(A, N);

    int* B = new int[N];
    copy(A, A + N, B);

    int* C = new int[N];
    copy(A, A + N, C);

    int* D = new int[N];
    copy(A, A + N, D);

    int* E = new int[N];
    copy(A, A + N, E);

    clock_t tStartBubbleSort = clock();
    bubbleSort(B, N);
    double timeBubbleSort = (clock() - tStartBubbleSort);
    cout << "\nОтсортированный массив B (Пузырьковая сортировка): ";
    printArray(B, N);

    clock_t tStartInsertionSort = clock();
    insertionSort(C, N);
    double timeInsertionSort = (clock() - tStartInsertionSort);
    cout << "\nОтсортированный массив C (Сортировка вставкой): ";
    printArray(C, N);

    clock_t tStartSelectionSort = clock();
    selectionSort(D, N);
    double timeSelectionSort = (clock() - tStartSelectionSort);
    cout << "\nОтсортированный массив D (Сортировка выбора): ";
    printArray(D, N);

    clock_t tStartQuickSort = clock();
    quicksort(E, 0, N - 1);
    double timeQuickSort = (clock() - tStartQuickSort);
    cout << "\nОтсортированный массив E (Быстрая сортировка): ";
    printArray(E, N);
    cout << "\n\t====================================================" << endl;
    cout << "\t     Время выполнения разных способов сортировки" << endl;
    cout << "\t====================================================" << endl;

    printf("\tПузырьковая сортировка:\t %.6fs\n", (timeBubbleSort) / CLOCKS_PER_SEC);
    printf("\tСортировка вставкой:\t %.6fs\n", (timeInsertionSort) / CLOCKS_PER_SEC);
    printf("\tСортировка выбора:\t %.6fs\n", (timeSelectionSort) / CLOCKS_PER_SEC);
    printf("\tБыстрая сортировка:\t %.6fs\n", (timeQuickSort) / CLOCKS_PER_SEC);

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;

    return 0;
}