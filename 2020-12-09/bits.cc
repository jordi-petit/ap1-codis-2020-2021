// genera tots els vectors amb n bits

#include <iostream>
#include <vector>
using namespace std;

void escriure(const vector<int>& v)
{
    for (int x : v) {
        cout << x;
    }
    cout << endl;
}

void generar(vector<int>& v, int i)
{
    int n = v.size();
    if (i == n) {
        escriure(v);
    } else {
        v[i] = 0;
        generar(v, i + 1);
        v[i] = 1;
        generar(v, i + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    generar(v, 0);
}
