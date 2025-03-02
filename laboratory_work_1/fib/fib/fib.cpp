#include <iostream>
#include <ctime>
using namespace std;

int recursive(int x) {
    if (x <= 1)
        return x;
    else              
        return recursive(x - 1) + recursive(x - 2);
}

int linear(int x) {
    if (x <= 1)
        return x;
    int a = 0, b = 1;
    for (int i = 2; i <= x; i++) {
        int dr = b;
        b = a + b;
        a = dr;
    }
    return b;
}

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    cout << "Введите число N: ";
    cin >> N;
    clock_t tStartRecursive = clock();
    cout << "N-ое число ряда Фибоначчи рекурсивным методом: " << recursive(N) << endl;
    printf("Время выполнения recursive: %.6fs\n", (double)(clock() - tStartRecursive) / CLOCKS_PER_SEC);

    clock_t tStartLinear = clock();
    cout << "N-ое число ряда Фибоначчи линейным методом: " << linear(N) << endl;
    printf("Время выполнения linear: %.6fs\n", (double)(clock() - tStartLinear) / CLOCKS_PER_SEC);
    return 0;
}