// Zadanie: vote
// Autor: Michał Ambroży
// Nr indeksu: 328934
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int* nrKandydata = new int[n + 1]; // zadeklarowanie tablicy o długości liczby kandydatów (n) oraz zarezerwowanie miejsca w pamięci

    for (int i = 0; i < n + 1; i++) { // wypełnienie tablicy zerami
        nrKandydata[i] = 0;
    }

    int k;
    for (int i = 0; i < m; i++) { // wczytanie i zliczanie głosów na poszczególnych kandydatów
        cin >> k;
        nrKandydata[k]++;       
    }

    int maxWynik = 0;
    for (int i = 1; i < n + 1; i++) { // wyszukanie kandydata z największą liczbą głosów
        if (nrKandydata[i] > maxWynik) {
            maxWynik = nrKandydata[i];
        }
    }

    for (int i = 1; i < n + 1; i++) { // sprawdzenie, czy istnieje drugi kandydat, który otrzymał największą liczbę głosów i zwrócenie numerów kandydatów z największą liczbą głosów
        if (nrKandydata[i] == maxWynik) {
            cout << i << " ";
        }
    }
    delete[] nrKandydata; //zwalnianie pamięci
    return 0;
}