// comptar el nombre de pics en una seqüència

#include <iostream>
#include <string>
using namespace std;

bool es_pic(int a, int b, int c)
{
    return b > a and b > c;
}

int main()
{
    int n = 0;
    int a, b, c;
    cin >> a >> b;
    while (cin >> c) {
        if (es_pic(a, b, c)) {
            ++n;
        }
        a = b;
        b = c;
    }
    cout << n << endl;
}
