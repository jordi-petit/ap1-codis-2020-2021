// llegeix una seqüència de paraules i n'escriu totes les seves permutacions

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void escriure(const vector<int>& v, const vector<string>& p)
{
    for (int x : v) {
        cout << p[x] << " ";
    }
    cout << endl;
}

void generar(vector<int>& v, vector<bool>& u, int i, const vector<string>& p)
{
    int n = v.size();
    if (i == n) {
        escriure(v, p);
    } else {
        for (int j = 0; j < n; ++j) {
            if (not u[j]) {
                v[i] = j;
                u[j] = true;
                generar(v, u, i + 1, p);
                u[j] = false;
            }
        }
    }
}

int main()
{
    vector<string> p;
    string x;
    while (cin >> x) {
        p.push_back(x);
    }
    int n = p.size();
    vector<int> v(n);
    vector<bool> u(n, false);
    generar(v, u, 0, p);
}
