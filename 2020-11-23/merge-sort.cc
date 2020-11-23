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

void merge(vector<int>& v, int e, int m, int d)
{
    vector<int> a(d - e + 1);
    int i = e;
    int j = m + 1;
    int k = 0;
    while (i <= m and j <= d) {
        if (v[i] <= v[j]) {
            a[k] = v[i];
            ++i;
        } else {
            a[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i <= m) {
        a[k] = v[i];
        ++i;
        ++k;
    }
    while (j <= d) {
        a[k] = v[j];
        ++j;
        ++k;
    }
    for (int p = e; p <= d; ++p) {
        v[p] = a[p - e];
    }
}

void merge_sort_rec(vector<int>& v, int e, int d)
{
    if (e < d) {
        int m = (e + d) / 2;
        merge_sort_rec(v, e, m);
        merge_sort_rec(v, m + 1, d);
        merge(v, e, m, d);
    }
}

void merge_sort(vector<int>& v)
{
    merge_sort_rec(v, 0, v.size() - 1);
}

int main2()
{
    vector<int> v = { 5, 12, 11, 9, 5, 2, 3, 7, 4, 6, 4, 1 };
    print(v);
    merge_sort(v);
    print(v);
    assert(sorted(v));
}

int main()
{
    vector<int> v = random(100000);
    merge_sort(v);
    assert(sorted(v));
}
