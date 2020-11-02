// compta quants primers hi ha fins a un nombre donat,
// utilitzant el garbell d'Eratostenes.

#include <iostream>
#include <vector>
using namespace std;

double now()
{
    return clock() / double(CLOCKS_PER_SEC);
}

// retorna un vector p amb n posicions
// tal que p[i] és cert ssi i és primer
vector<bool> eratostenes(int n)
{
    vector<bool> p(n + 1, true);
    p[0] = false;
    p[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (p[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }
    return p;
}

int main()
{
    const int n = 20000000;
    double t_inici = now();
    vector<bool> p = eratostenes(n - 1);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i]) {
            ++c;
        }
    }
    double t_final = now();
    cout << t_final - t_inici << endl;
    cout << c << endl;
}
