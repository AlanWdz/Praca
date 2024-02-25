
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int WyszukiwanieLiniowe(int tab[], int rozmiar, int klucz) {
    for (int i = 0; i < rozmiar; ++i) {
        if (tab[i] == klucz) {
            return i;
        }
    }
    return -1;
}

int WyszukiwanieLinioweZwartownikiem(int tab[], int rozmiar, int klucz) {
    int ostatni = tab[rozmiar - 1];
    tab[rozmiar - 1] = klucz;
    int i = 0;
    while (tab[i] != klucz) {
        ++i;
    }
    tab[rozmiar - 1] = ostatni;
    if ((i < rozmiar - 1) || (tab[rozmiar - 1] == klucz)) {
        return i;
    }
    return -1;
}

int WyszukiwanieSkokowe(int tab[], int rozmiar, int klucz) {
    int skok = sqrt(rozmiar);
    int prev = 0;
    while (tab[min(skok, rozmiar) - 1] < klucz) {
        prev = skok;
        skok += sqrt(rozmiar);
        if (prev >= rozmiar) {
            return -1;
        }
    }
    while (tab[prev] < klucz) {
        prev++;
        if (prev == min(skok, rozmiar)) {
            return -1;
        }
    }
    if (tab[prev] == klucz) {
        return prev;
    }
    return -1;
}

int WyszukiwanieBinarne(int tab[], int rozmiar, int klucz) {
    int lewo = 0, prawo = rozmiar - 1;
    while (lewo <= prawo) {
        int srodek = lewo + (prawo - lewo) / 2;
        if (tab[srodek] == klucz)
            return srodek;
        if (tab[srodek] < klucz)
            lewo = srodek + 1;
        else
            prawo = srodek - 1;
    }
    return -1;
}

int WyszukiwanieInterpolacyjne(int tab[], int rozmiar, int klucz) {
    int lewo = 0, prawo = rozmiar - 1;
    while (lewo <= prawo && klucz >= tab[lewo] && klucz <= tab[prawo]) {
        if (lewo == prawo) {
            if (tab[lewo] == klucz)
                return lewo;
            return -1;
        }
        int pos = lewo + (((double)(prawo - lewo) / (tab[prawo] - tab[lewo])) * (klucz - tab[lewo]));
        if (tab[pos] == klucz)
            return pos;
        if (tab[pos] < klucz)
            lewo = pos + 1;
        else
            prawo = pos - 1;
    }
    return -1;
}
