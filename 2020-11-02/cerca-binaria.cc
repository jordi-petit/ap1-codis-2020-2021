// cerca d'un element en un vector ordenat, amb mesures de temps

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

double now()
{
    return clock() / double(CLOCKS_PER_SEC);
}

// retorna una posició de x en v si hi és, altrament retorna -1
// precondició: v està ordenat creixentment
int cerca_binaria(const vector<int>& v, int x)
{
    int n = v.size();
    int esq = 0;
    int dre = n - 1;
    while (esq <= dre) {
        int mig = (esq + dre) / 2;

        if (v[mig] < x) {
            esq = mig + 1;
        } else if (v[mig] > x) {
            dre = mig - 1;
        } else {
            return mig;
        }
    }
    return -1;
}

int main()
{
    const int n = 1000000000;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    // v està ordenat creixentment

    double t_inici = now();
    int p = cerca_binaria(v, n);
    double t_final = now();

    cout << t_final - t_inici << endl;
    cout << p << endl;
}
