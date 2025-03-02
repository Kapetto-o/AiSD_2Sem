#include <iostream>
#include <stack>

using namespace std;

bool areBracketsBalanced(string expr) {
    stack<char> s;
    char x;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    return (s.empty());
}

int main() {
    setlocale(LC_ALL, "Rus");
    string expr;
    char continueChoice;

    do {
        cout << "Введите строку: ";
        cin >> expr;

        if (expr.find_first_of("(){}[]") == string::npos) {
            cout << "Скобок в строке нет";
        }
        else if (areBracketsBalanced(expr)) {
            cout << "Скобки расставлены верно";
        }
        else {
            cout << "Скобки расставлены не верно";
        }

        cout << "\nХотите продолжить? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}