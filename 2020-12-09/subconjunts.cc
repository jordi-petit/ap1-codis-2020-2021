// llegeix una seqüència de p i n'escriu tots els seus subconjunts

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void escriure(const vector<int>& v, const vector<string>& p)
{
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            cout << p[i] << " ";
        }
    }
    cout << endl;
}

void generar(vector<int>& v, int i, const vector<string>& p)
{
    int n = v.size();
    if (i == n) {
        escriure(v, p);
    } else {
        v[i] = 0;
        generar(v, i + 1, p);
        v[i] = 1;
        generar(v, i + 1, p);
    }
}

int main()
{
    vector<string> p;
    string x;
    while (cin >> x) {
        p.push_back(x);
    }

    vector<int> v(p.size());
    generar(v, 0, p);
}
