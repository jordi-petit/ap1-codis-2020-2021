// genera tots els vectors amb n valors on cada valor és un n´mero entre 0 i k-1.

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

void generar(vector<int>& v, int k, int i)
{
    int n = v.size();
    if (i == n) {
        escriure(v);
    } else {
        for (int j = k - 1; j >= 0; --j) {
            v[i] = j;
            generar(v, k, i + 1);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    generar(v, k, 0);
}
