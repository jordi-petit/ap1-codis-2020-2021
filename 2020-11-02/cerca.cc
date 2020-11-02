#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> v = { 1, 4, 6, 3, 8, 4, 2 };
    cout << posicio(v, 9) << endl;
}
