
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void tablica(int t[], int rozmiar, int klucz) {
    int x = 25;
    bool znaleziono = false;
    for(int i = 0; i < rozmiar; i++) {
        t[i] = rand() % x;
        cout << t[i] << ", ";
        if (t[i] == klucz && !znaleziono) {
            znaleziono = true;
        }
    }
    cout << "\n";
}

void SortowanieBombelkowe(int tab[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << tab[i] << ", ";
    }
    cout << "\n";
}

void SortowanieKoktajlowe(int tab[], int n) {
    bool zmiana = true;
    int start = 0;
    int koniec = n - 1;

    while(zmiana) {
        zmiana = false;

        for(int i = start; i < koniec; ++i) {
            if(tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zmiana = true;
            }
        }

        if(!zmiana)
            break;

        zmiana = false;
        --koniec;

        for(int i = koniec - 1; i >= start; --i) {
            if(tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zmiana = true;
            }
        }

        ++start;
    }

    for(int i = 0; i < n; ++i) {
        cout << tab[i] << ", ";
    }
    cout << "\n";
}
void scalanie(int tab[], int lewo, int srodek, int prawo) {
    int n1 = srodek - lewo + 1;
    int n2 = prawo - srodek;

    int* L = new int[n1];
    int* P = new int[n2];

    for(int i = 0; i < n1; i++)
        L[i] = tab[lewo + i];
    for(int j = 0; j < n2; j++)
        P[j] = tab[srodek + 1 + j];

    int i = 0;
    int j = 0;
    int k = lewo;

    while(i < n1 && j < n2) {
        if(L[i] <= P[j]) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = P[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        tab[k] = P[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] P;
}


void ScalanieSortowanie(int tab[], int lewo, int prawo) {
    if(lewo < prawo) {
        int srodek = lewo + (prawo - lewo) / 2;
        ScalanieSortowanie(tab, lewo, srodek);
        ScalanieSortowanie(tab, srodek + 1, prawo);
        scalanie(tab, lewo, srodek, prawo);
    }
}


int Sort(int tab[], int lewo, int prawo) {
    int h = tab[prawo];
    int i = lewo - 1;

    for(int j = lewo; j < prawo; j++) {
        if(tab[j] < h) {
            i++;
            swap(tab[i], tab[j]);
        }
    }

    swap(tab[i + 1], tab[prawo]);
    return i + 1;
}
void SzybkieSortowanie(int tab[], int lewo, int prawo) {
    if(lewo < prawo) {
        int indeks = Sort(tab, lewo, prawo);
        SzybkieSortowanie(tab, lewo, indeks - 1);
        SzybkieSortowanie(tab, indeks + 1, prawo);
    }
}