#include <iostream>
#include <vector>
using namespace std;

// Retorna la fusió ordenada de dos vectors ordenats.
// precondició: v1 i v2 estàn ordenats.
vector<int> fusio(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> v;
    int i = 0;
    int j = 0;
    int n1 = v1.size();
    int n2 = v2.size();
    while (i < n1 and j < n2) {
        if (v1[i] <= v2[j]) {
            v.push_back(v1[i]);
            ++i;
        } else {
            v.push_back(v2[j]);
            ++j;
        }
    }
    while (j < n2) {
        v.push_back(v2[j]);
        ++j;
    }
    while (i < n1) {
        v.push_back(v1[i]);
        ++i;
    }
    return v;
}

int main()
{
    vector<int> v1 = { 1, 5, 5, 7, 8, 9 };
    vector<int> v2 = { 2, 3, 5, 11 };
    vector<int> v = fusio(v1, v2);
    for (int x : v) {
        cout << x << endl;
    }
}
