#include <algorithm>
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

int main2()
{
    vector<int> v = { 5, 12, 11, 9, 5, 2, 3, 7, 4, 6, 4, 1 };
    print(v);
    sort(v.begin(), v.end());
    print(v);
    assert(sorted(v));
}

int main()
{
    vector<int> v = random(100000);
    sort(v.begin(), v.end());
    assert(sorted(v));
}
