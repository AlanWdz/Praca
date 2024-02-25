#include "cos.hpp"
#include "cos1.hpp"
#include <iostream>
using namespace std;

void tablica(int t[], int rozmiar, int klucz);
void SortowanieBombelkowe(int tab[], int n);
void SortowanieKoktajlowe(int tab[], int n);
void ScalanieSortowanie(int tab[], int lewo, int prawo);
void scalanie(int tab[], int lewo, int srodek, int prawo);
void SzybkieSortowanie(int tab[], int lewo, int prawo);
int Sort(int tab[], int lewo, int prawo);
int WyszukiwanieLiniowe(int tab[], int rozmiar, int klucz);
int WyszukiwanieLinioweZwartownikiem(int tab[], int rozmiar, int klucz);
int WyszukiwanieSkokowe(int tab[], int rozmiar, int klucz);
int WyszukiwanieBinarne(int tab[], int rozmiar, int klucz);
int WyszukiwanieInterpolacyjne(int tab[], int rozmiar, int klucz);

int main() {
    const int n = 12;
    int t[n];
    cout << "Tablica: ";
    int klucz = 8;
    tablica(t, n, klucz);
    cout << "Tablica po sortowaniu bombelkowym: ";
    SortowanieBombelkowe(t, n);
    cout << "Tablica po sortowaniu koktajlowym: ";
    SortowanieKoktajlowe(t, n);
    cout << "Tablica po sortowaniu przez scalanie: ";
    ScalanieSortowanie(t, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << t[i] << ", ";
    }
    cout << endl;
    cout << "Tablica po sortowaniu szybkim: ";
    SzybkieSortowanie(t, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << t[i] << ", ";
    }
    cout << endl;
    cout << "Wyszukiwanie liniowe: ";
    int index = WyszukiwanieLiniowe(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie liniowe z wartownikiem: ";
    index = WyszukiwanieLinioweZwartownikiem(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie skokowe: ";
    index = WyszukiwanieSkokowe(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie binarne: ";
    index = WyszukiwanieBinarne(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie interpolacyjne: ";
    index = WyszukiwanieInterpolacyjne(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    return 0;
}

