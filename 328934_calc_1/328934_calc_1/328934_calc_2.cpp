// Zadanie: calc
// Autor: Michał Ambroży
// Nr indeksu: 328934
#include <iostream>

#include <stack>

using namespace std;

int main() {
    // Tworzenie dwóch stosów
    stack < int > value_stack;
    stack < char > operator_stack;

    char token;

    while (cin >> token) // Wczytywanie danych, dodawanie ich na stosy i wykonywanie operacji
    {

        if (token == '(')
            continue;
        if ('0' <= token && token <= '9')
            value_stack.push(token - '0'); // Dodawanie liczb na stos
        else if (token == '+' || token == '-' || token == '*' || token == '/')
            operator_stack.push(token); // Dodawanie operatorów na stos
        else if (token == ')') {
            int value2 = value_stack.top();
            value_stack.pop(); // Zdejmowanie pierwszej wartości ze stosu
            int value1 = value_stack.top();
            value_stack.pop(); // Zdejmowanie drugiej wartości ze stosu
            char op = operator_stack.top();
            operator_stack.pop(); // Zdejmowanie operatora ze stosu

            // Wykonywanie operacji na zdjętych wartościach. Wynik dodawany jest na stos
            switch (op) {
            case '+':
                value_stack.push(value1 + value2);
                break;
            case '-':
                value_stack.push(value1 - value2);
                break;
            case '*':
                value_stack.push(value1 * value2);
                break;
            case '/':
                if (!value2) { // Sprawdzanie czy nie dzielimy przez 0
                    cout << "NaN";
                    return 1;
                }
                value_stack.push(value1 / value2);
                break;
            }
            if (cin.get() == '\n')
                break;
        }
    }
    cout << value_stack.top(); // Wypisywanie wyniku
    return 0;
}