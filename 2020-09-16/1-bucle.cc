// Programa que escriu "Hola" tantes vegades com digui l'usuari

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 0;
    while (i < n) {
        cout << "Hola" << endl;
        i = i + 1;
    }
}
