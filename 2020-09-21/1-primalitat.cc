// Programa que llegeix un natural i escriu si és o no primer.
// ara ja funciona per 0 i 1, no fa feina extra si és compost i usa booleans

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool es_primer = true;
    if (n <= 1) {
        es_primer = false;
    } else {
        int i = 2;
        while (i * i <= n and es_primer) {
            if (n % i == 0) {
                es_primer = false;
            }
            i = i + 1;
        }
    }
    if (es_primer) {
        cout << "És primer!" << endl;
    } else {
        cout << "No és primer!" << endl;
    }
}
