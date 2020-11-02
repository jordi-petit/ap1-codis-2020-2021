// cerca d'un element en un vector, amb mesures de temps

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

double now()
{
    return clock() / double(CLOCKS_PER_SEC);
}

// retorna una posició de x en v si hi és, altrament retorna -1
int posicio(const vector<int>& v, int x)
{
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] == x) {
            return i;
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

    double t_inici = now();
    int p = posicio(v, n);
    double t_final = now();

    cout << t_final - t_inici << endl;
    cout << p << endl;
}
