#include <iostream>
#include <cmath>
using namespace std;

void binaryMethod() {
    int N;
    cout << "Введите число N: ";
    cin >> N;

    while (N < 1) {
        cout << "Вы должны ввести число равное или больше 1. Повторите попытку: ";
        cin >> N;
    }

    double low = 1.0, high = N, temp_low = 1.0, temp_high = N;
    int max_steps = ceil(log2(N)); 

    while (low <= high) { 
        int mid = floor((low + high) / 2);
        cout << mid << endl; 

        int answer;
        cout << "Выберите один из вариантов: 1 для 'меньше', 2 для 'больше', 3 для 'угадал': ";
        cin >> answer;

        if (answer == 3) {
            cout << "Ура, я угадал! Ваше число: " << mid << endl;
            if (mid == 1) {
                cout << "Максимальное количество шагов: " << max_steps + 1 << endl;
            }
            else {
                cout << "Максимальное количество шагов: " << max_steps << endl;
            }

            for (int i = 0; i <= max_steps; ++i) { 
                cout << temp_high << endl; 
                int mid1 = floor((temp_low + temp_high) / 2);  
                 
                temp_high = mid1;
            }
            return;
        }
        else if (answer == 1) {
            high = mid; 
        }
        else if (answer == 2) {
            low = mid; 
        }
        else {
            cout << "Неверный ответ. Попробуйте еще раз." << endl;
        }
    }
    cout << "Число не найдено." << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    binaryMethod();
    return 0;
}