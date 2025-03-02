#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(vector<int>& scores) {
    int n = scores.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                swap(scores[j], scores[j + 1]);
            }
        }
    }
}

int countWinners(vector<int>& scores) {
    int winners = 0;
    int top_scores[3] = { scores[0], -1, -1 };

    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] != top_scores[0] && top_scores[1] == -1) {
            top_scores[1] = scores[i];
        }
        else if (scores[i] != top_scores[0] && scores[i] != top_scores[1] && top_scores[2] == -1) {
            top_scores[2] = scores[i];
        }
    }

    for (int i = 0; i < scores.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (scores[i] == top_scores[j]) {
                winners++;
                break;
            }
        }
    }
    return winners;
}

int main() {
    setlocale(LC_ALL, "Rus");

    srand(time(0));
    int N;
    cout << "Введите количество участников: ";
    cin >> N;

    vector<int> scores(N);

    // Блок, ручного ввода
    /*
    cout << "Введите результаты участников: ";
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    */

    // Блок, случайной генерации
    for (int i = 0; i < N; i++) {
        scores[i] = rand() % 100 + 1;
    }
    cout << "Сгенерированные результаты: ";
    for (int i = 0; i < N; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;


    bubbleSort(scores);

    cout << "\nРезультаты в порядке убывания: ";
    for (int i = 0; i < N; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    int winners = countWinners(scores);

    cout << "Количество призеров: " << winners << endl;

    return 0;
}