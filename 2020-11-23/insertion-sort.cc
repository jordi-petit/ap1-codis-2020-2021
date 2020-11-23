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

// prec: v[0..i-1] està ordenat
// postc: v[0..i] està ordenat
void insert(vector<int>& v, int i)
{
    int x = v[i];
    int j = i;
    while (j > 0 and v[j - 1] > x) {
        v[j] = v[j - 1];
        --j;
    }
    v[j] = x;
}

void insertion_sort(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        insert(v, i);
    }
}

int main2()
{
    vector<int> v = { 5, 12, 11, 9, 5, 2, 3, 7, 4, 6, 4, 1 };
    print(v);
    insertion_sort(v);
    print(v);
    assert(sorted(v));
}

int main()
{
    vector<int> v = random(100000);
    insertion_sort(v);
    assert(sorted(v));
}
