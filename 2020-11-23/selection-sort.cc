#include <cassert>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void print(const vector<int>& v)
{
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

bool sorted(const vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i - 1] > v[i]) {
            return false;
        }
    }
    return true;
}

vector<int> random(int n)
{
    vector<int> v(n);
    for (int& x : v) {
        x = rand() % n;
    }
    return v;
}

int posmin(const vector<int>& v, int i)
{
    // retornar la posició del mínim del v[i..n-1]
    int n = v.size();
    int p = i;
    for (int j = i + 1; j < n; ++j) {
        if (v[j] < v[p]) {
            p = j;
        }
    }
    return p;
}

void selection_sort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        int p = posmin(v, i);
        swap(v[i], v[p]);
    }
}

int main2()
{
    vector<int> v = { 5, 12, 11, 9, 5, 2, 3, 7, 4, 6, 4, 1 };
    print(v);
    selection_sort(v);
    print(v);
    assert(sorted(v));
}

int main()
{
    vector<int> v = random(100000);
    selection_sort(v);
    assert(sorted(v));
}
