// genera totes les permutacions de 0 a n-1.

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

void generar(vector<int>& v, vector<bool>& u, int i)
{
    int n = v.size();
    if (i == n) {
        escriure(v);
    } else {
        for (int j = 0; j < n; ++j) {
            if (not u[j]) {
                v[i] = j;
                u[j] = true;
                generar(v, u, i + 1);
                u[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> u(n, false);
    generar(v, u, 0);
}
