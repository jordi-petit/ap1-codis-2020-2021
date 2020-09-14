// Programa que llegeix tres nombres i escriu el seu màxim

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int m;
    if (a >= b) {
        if (a >= c) {
            m = a;
        } else {
            m = c;
        }
    } else {
        if (b >= c) {
            m = b;
        } else {
            m = c;
        }
    }

    cout << m << endl;
}
