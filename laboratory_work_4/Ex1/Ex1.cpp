#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(vector<int>& prices) {
    int n = prices.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (prices[j] > prices[j + 1]) {
                swap(prices[j], prices[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    srand(time(0));
    int N;
    cout << "Введите количество товаров: ";
    cin >> N;

    vector<int> prices(N);

    // Блок, ручного ввода
    //cout << "Введите цены товаров: ";
    //for (int i = 0; i < N; ++i) {
    //    cin >> prices[i];
    //}
    // Блок, случайной генерации
    
    for (int i = 0; i < N; i++) {
        prices[i] = rand() % 100 + 1;
    }
    cout << "\nСгенерированные цены: ";
    for (int i = 0; i < N; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;
    

    bubbleSort(prices);

    int total = 0;
    vector<int> order;
    while (!prices.empty()) {
        total += prices.back();
        order.push_back(prices.back());
        prices.pop_back();
        if (!prices.empty()) {
            order.push_back(prices.front());
            prices.erase(prices.begin());
        }
    }

    cout << "Порядок пробивания на кассе: ";

    for (int price : order) {
        cout << price << " ";
    }
    cout << "\nМаксимальная сумма чека: " << total << endl;

    return 0;
}