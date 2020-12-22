//Feu un programa que escrigui totes les combinacions de n − u zeros i u uns, per a un n i un u donats.

#include <iostream>
#include <vector>
using namespace std;

//Escriu totes les combinacions generades
void escriure(const vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
}

//Només genera les combinacions necessàries, les que contenen u uns
void generar(vector<int>& v, int i, int u, int z, int zeros_fixats, int uns_fixats)
{
    if (i == v.size()) {
        escriure(v);
    } else {
        if (zeros_fixats < z) {
            v[i] = 0;
            generar(v, i + 1, u, z, zeros_fixats + 1, uns_fixats);
        }
        if (uns_fixats < u) {
            v[i] = 1;
            generar(v, i + 1, u, z, zeros_fixats, uns_fixats + 1);
        }
    }
}

int main()
{
    //prec: n>0 i 0<=u<=n
    int n, u;
    cin >> n >> u;
    int z = n - u;
    vector<int> v(n);

    generar(v, 0, u, z, 0, 0);
}
