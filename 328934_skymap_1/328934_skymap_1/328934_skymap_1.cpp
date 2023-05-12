// Zadanie: Mapa nieba
// Autor: Michał Ambroży
// Nr indeksu: 328934
#include <iostream>

#include <vector>

using namespace std;

int cc; // number of components
int N; // number of elements
vector < int > id; // id[i] = parent of i
vector < int > sz; // sz[i] = number of elements in subtree rooted at i

// initializes data structures
void init(int size) {
    cc = size;
    N = size;

    id.resize(size);
    sz.resize(size);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

// gets component's identifier of the element
int find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]]; // path compression by halving
        p = id[p];
    }

    return p;
}

// check if 2 elements belongs to the same component
bool connected(int p, int q) {
    return find(p) == find(q);
}

// connect components
void make_union(int p, int q) {
    int pid = find(p);
    int qid = find(q);

    if (pid == qid) return;

    // make smaller root point to larger one
    if (sz[qid] < sz[pid]) {
        id[qid] = pid;
        sz[pid] += sz[qid];
    }
    else {
        id[pid] = qid;
        sz[qid] += sz[pid];
    }

    cc--;
}

int main() {
    // Inicjalizacja struktur danych
    int l;
    cin >> l;
    init(l * l);

    vector < vector < int >> gwiazdy(l, vector < int >(l)); // Tworzenie dwuwymiarowego wektora
    for (int i = 0; i < l; i++) { // Sczytywanie danych z wejścia standardowego do wektora
        for (int j = 0; j < l; j++) {
            cin >> gwiazdy[i][j];
        }
    }

    //Łączenie konstelacji za pomocą komponentów
    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            if (gwiazdy[i][j] == 1) { // Jeśli napotkam konstelację, sprawdzam jej sąsiedztwo
                if (i > 0 && gwiazdy[i - 1][j] == 1) // Jeśli konstelacja ma gwiazdę w pionowym sąsiedztwie łączę je w jeden komponent
                    make_union(i * l + j, (i - 1) * l + j);
                if (j > 0 && gwiazdy[i][j - 1] == 1) // Jeśli konstelacja ma gwiazdę w poziomym sąsiedztwie łączę je w jeden komponent
                    make_union(i * l + j, i * l + j - 1);
            }

    //Znajdowanie największej konstelacji oraz ilości konstelacji
    int constellations_number = 0;
    int max_size = 0;
    int single_components = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            if (gwiazdy[i][j] == 1) {
                if (sz[find(i * l + j)] > max_size)
                    max_size = sz[find(i * l + j)];
            }
            else {
                single_components++;
            }
    constellations_number = cc - single_components;

    //Wypisywanie otrzymanego wyniku na wyjście standardowe
    cout << constellations_number << " " << max_size;
    return 0;
}