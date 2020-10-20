// P19724 - Arlet C.

#include <iostream>
using namespace std;

int descomposicio_temps(int t)
{
    return t / 1440;
}

int normalitzar_hora(int h)
{
    if (h > 12) {
        return h - 12;
    }
    if (h == 0) {
        return 12;
    }
    return h;
}

int main()
{
    int h, m, t;
    while (cin >> h >> m >> t) {
        int c = 0;

        int n_dies = descomposicio_temps(t);
        int t2 = t % 1440;

        while (t2 > 0) {
            if (m >= 60) {
                ++h;
                m = 0;
                if (h >= 24) {
                    h = 0;
                }
            }

            if (m == 15) {
                c += 1;
            } else if (m == 30) {
                c += 2;
            } else if (m == 45) {
                c += 3;
            } else if (m == 0) {
                if (h == 12) {
                    c += 100 + 4;
                } else {
                    int h2 = normalitzar_hora(h);
                    c += 4 + h2;
                }
            }

            ++m;
            --t2;
        }
        cout << c + 484 * n_dies << endl;
    }
}
