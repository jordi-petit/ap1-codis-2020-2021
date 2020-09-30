// calcula la mitjana d'una seqüència (no buida) de reals

#include <iostream>
using namespace std;

int main()
{
    // amb això tots els números reals s'escriuen amb 4 dígits darrera la coma
    cout.setf(ios::fixed);
    cout.precision(4);

    int c = 0;
    double s = 0;
    double x;
    while (cin >> x) {
        s += x;
        ++c;
    }
    cout << s / c << endl;
}
