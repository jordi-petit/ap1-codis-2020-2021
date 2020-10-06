// problema de convertir nombres romans a decimals del Jutge

#include <iostream>
using namespace std;

int valor(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return 0; // no pot ser!
}

int main()
{
    char c1, c2;
    if (cin >> c1) {
        cout << c1;
        int n = 0;
        while (cin >> c2) {
            if (c2 == '.' or valor(c1) >= valor(c2)) {
                n += valor(c1);
            } else {
                n -= valor(c1);
            }
            if (c2 == '.') {
                cout << " = " << n << endl;
                n = 0;
            } else {
                cout << c2;
            }
            c1 = c2;
        }
    }
}
