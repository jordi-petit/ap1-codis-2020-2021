/*
    Programa amb un assortiment de funcions per a tots els gustos.
*/

#include <iostream>
using namespace std;

// funció que retorna el valor més petit de dos enters
int minim2(int x, int y)
{
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

// funció que retorna el valor més petit de tres enters
int minim3(int x, int y, int z)
{
    return minim2(minim2(x, y), z);
}

// retorna el valor absolut de x
int valor_absolut(int x)
{
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

// funció que, donat un natural x, retorna x! (el seu factorial)
// precondició: x >= 0
// implementació iterativa
int factorial(int x)
{
    int f = 1;
    for (int i = 2; i <= x; ++i) {
        f *= i;
    }
    return f;
}

// funció que, donat un natural x, retorna x! (el seu factorial)
// precondició: x >= 0
// implementació iterativa
int factorial(int x)
{
    if (x == 0) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

// programa principal
int main()
{
    /*
    int x, y;
    cin >> x >> y;

    cout << minim2(x, y) << endl;
    */

    /*
    int x, y, z;
    cin >> x >> y >> z;

    cout << minim3(x, y, z) << endl;
    */

    int n;
    cin >> n;
    cout << factorial(n) << endl;
}
