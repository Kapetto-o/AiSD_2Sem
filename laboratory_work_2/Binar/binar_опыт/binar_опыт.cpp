#include <iostream>
#include <string>
#include <cmath> // Добавляем библиотеку для использования функции log2()

using namespace std;

void play_guess_game() {
    int n;
    cout << "Введите число N: ";
    cin >> n;

    // Проверка на корректность ввода числа N
    if (n < 1) {
        cout << "Введите число начиная с 1." << endl;
        return;
    }

    double low = 1.0; // Изменено на тип double
    double high = n; // Изменено на тип double
    int max_steps = log2(n); // Максимальное количество шагов для числа n

    while (low <= high) { // Изменено условие выхода из цикла
        int mid = floor((low + high) / 2); // Округление до ближайшего меньшего целого
        cout << mid << endl; // Выводим текущее значение

        int answer;
        cout << "Введите 1 для 'мало', 2 для 'много' или 3 для 'угадал': ";
        cin >> answer;

        if (answer == 3) {
            cout << "Вы угадали число " << mid << "!" << endl;
            cout << "Максимальное количество шагов = " << max_steps << endl; // Выводим максимальное количество шагов
            return;
        }
        else if (answer == 1) {
            high = mid; // Изменено на mid - 1, так как искомое число может быть mid или меньше
        }
        else if (answer == 2) {
            low = mid; // Изменено на mid + 1, так как искомое число может быть mid или больше
        }
        else {
            cout << "Неверный ответ. Попробуйте еще раз." << endl;
            continue;
        }
    }

    cout << "Число не найдено." << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    play_guess_game();
    return 0;
}
