#include <iostream> 
#include <chrono> 
#include <list> 
#include <vector> 
#include <string> 
#include <Windows.h>

using namespace std;

struct Record {
    int phone_number;
    string name;
};

class HashTable {
private:
    vector<list<Record>> table;
    int table_size;

    int hashFunction(int key) {
        return key % table_size;
    }

public:
    HashTable(int size) : table_size(size) {
        table.resize(table_size);
    }
    void InsertItTable(int phone_number, const string& name) {
        int index = hashFunction(phone_number);
        table[index].push_back({ phone_number, name });
    }

    void RemoveFromTable(int phone_number) {
        int index = hashFunction(phone_number);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->phone_number == phone_number) {
                table[index].erase(it);
                break;
            }
        }
    }

    Record SearchInTable(int phone_number) {
        int index = hashFunction(phone_number);
        for (const auto& record : table[index]) {
            if (record.phone_number == phone_number) {
                return record;
            }
        }
        return { -1, "Not Found" };
    }

    void ShowTable() {
        for (int i = 0; i < table_size; ++i) {
            std::cout << "Хэш " << i << ": ";
            for (const auto& record : table[i]) {
                std::cout << "(" << record.phone_number << ", " << record.name << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Размер хеш-таблицы: ";
    cin >> size;
    HashTable hash_table(size);

    while (true) {
        cout << "\tМеню" << endl;
        cout << "1. Добавление" << endl;
        cout << "2. Удаление" << endl;
        cout << "3. Поиск" << endl;
        cout << "4. Вывод таблицы" << endl;
        cout << "5. Выйти" << endl;
        cout << "Действие:";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int phone_number;
            string name;
            cout << "Номер телефона: ";
            cin >> phone_number;
            if (phone_number > 32767 || phone_number < 0) {
                cout << "Превышен INT_MAX" << endl;
                continue;
            }
            cout << "ФИО владельца: ";
            cin >> name;
            hash_table.InsertItTable(phone_number, name);
        }
        else if (choice == 2) {
            int phone_number;
            cout << "Введите номер телефона для удаления: ";
            cin >> phone_number;
            hash_table.RemoveFromTable(phone_number);
        }
        else if (choice == 3) {
            int phone_number;
            cout << "Введите номер телефона для поиска: ";
            cin >> phone_number;

            auto start = chrono::high_resolution_clock::now();
            Record found = hash_table.SearchInTable(phone_number);
            auto end = chrono::high_resolution_clock::now();

            if (found.phone_number != -1) {
                cout << "Элемент найден: " << found.phone_number << ", " << found.name << endl;
            }
            else {
                cout << "Элемент не найден." << endl;
            }

            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Время поиска: " << duration.count() << " микросекунд." << endl;
        }
        else if (choice == 4) {
            hash_table.ShowTable();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Неверный ввод, попробуйте еще раз." << endl;
        }
    }

    return 0;
}