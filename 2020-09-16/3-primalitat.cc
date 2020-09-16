// Programa que llegeix un natural i esccriu si és o no primer.

/* Exercicis:

    - El programa encara no funciona bé del tot (n = 0 o 1) => arregleu-lo
    - El programa té diverses ineficiències => trobeu-les i proveu d'arreglar-les
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int es_primer = 1; // 1 vol dir que és primer, 0 vol dir que no ho és
    int i = 2;
    while (i < n) {
        if (n % i == 0) {
            es_primer = 0;
        }
        i = i + 1;
    }
    if (es_primer == 1) {
        cout << "És primer!" << endl;
    } else {
        cout << "No és primer!" << endl;
    }
}
