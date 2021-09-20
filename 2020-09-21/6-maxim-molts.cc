// programa que calcula el màxim una seqüència no buida d'elements enters

// recordeu que quan es llegeix del tecat, cal assenyalar el final
// de l'entrada amb Control+D

#include <iostream>
using namespace std;

int main()
{
    int maxim;
    cin >> maxim;
    int element;
    while (cin >> element) {
        if (element > maxim) {
            maxim = element;
        }
    }
    cout << maxim << endl;
}
