#include <iostream>
using namespace std;

bool fermatcub(int a, int c)
{
    return a == 0 or c == 0;
}
int main()
{
    int a, b, c, d;
    bool es_solucio = false;
    while (not es_solucio and cin >> a >> b >> c >> d) {
        es_solucio = fermatcub(a, c);
        if (es_solucio) {
            cout << a << "^3 + " << c << "^3 = " << a + c << "^3" << endl;
        }
    }
    if (not es_solucio) {
        cout << "Sense solucio!" << endl;
    }
}
