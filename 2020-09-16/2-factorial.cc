// Programa que llegeix un natural i escriu el seu factorial

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    int f = 1;
    while (i <= n) {
        f = f * i;
        i = i + 1;
    }

    cout << f << endl;
}
