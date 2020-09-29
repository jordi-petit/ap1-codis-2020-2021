#include <iostream>
using namespace std;

// intercanvia els valors dels paràmetres (pas per referència!)
void intercanviar(int& x, int& y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int a = 3;
    int b = 5;

    intercanviar(a, b);

    cout << a << endl
         << b << endl;
}
