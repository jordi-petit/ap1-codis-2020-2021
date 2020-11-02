// compta quants primers hi ha fins a un nombre donat,
// utilitzant la funció es_primer.

#include <iostream>
using namespace std;

double now()
{
    return clock() / double(CLOCKS_PER_SEC);
}

// indica si el natural x és primer o no
bool es_primer(int x)
{
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return x >= 2;
}

int main()
{
    const int n = 20000000;
    double t_inici = now();
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (es_primer(i)) {
            ++c;
        }
    }
    double t_final = now();
    cout << t_final - t_inici << endl;
    cout << c << endl;
}
