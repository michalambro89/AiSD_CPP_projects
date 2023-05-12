// Zadanie: rank
// Autor: Michał Ambroży
// Nr indeksu: 328934
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N = 0;
    cin >> N; // Wczytuje rozmiar danych z wejścia standarowego
    // Deklaracja struktur danych
    vector < int > scores(N);
    unordered_map < int, int > scores_map;
    vector < int > scores_copy(N);

    // Wczytuje dane z wejścia standardowego do dwóch wektorów
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        scores_copy[i] = scores[i];
    }

    sort(scores.begin(), scores.end(), greater < int >()); // Sortuję wektor scores w porządku malejącym

    // Wypełniam mapę
    for (int i = 0; i < N; i++) {
        if (scores_map.find(scores[i]) == scores_map.end()) { // Jeśli nie ma takiego klucza w mapie
            scores_map[scores[i]] = i + 1; // Przypisuję w mapie miejsce w rankingu dla danych wartości zdobytych punktów z wektora scores
        }
    }

    // Wypisuję elementy mapy na wyjście standardowe na podstawie wartości początkowych kluczy z wektora scores_copy
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << scores_map[scores_copy[i]];
        }
        else {
            cout << " " << scores_map[scores_copy[i]];
        }
    }

    return 0;
}