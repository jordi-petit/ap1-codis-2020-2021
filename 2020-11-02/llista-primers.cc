// calcula la llista de tots els nombres primers fins a un valor donat

#include <iostream>
#include <vector>
using namespace std;

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

// retorna un vector ordenat amb tots els nombres primers <= n.
vector<int> trobar_primers(int n)
{
    vector<int> primers;
    vector<bool> p = eratostenes(n);
    for (int i = 0; i < n; ++i) {
        if (p[i]) {
            primers.push_back(i);
        }
    }
    return primers;
}

int main()
{
    const int n = 20;
    vector<int> primers = trobar_primers(n);
    for (int primer : primers) {
        cout << primer << endl;
    }
}
