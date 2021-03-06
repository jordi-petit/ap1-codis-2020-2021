// Santi S

#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2)
{
    vector<double> v;
    int i = 0;
    int j = 0;

    while (i < v1.size() and j < v2.size()) {
        if (v1[i] < v2[j]) {
            if (v.empty() or v1[i] != v.back()) {
                v.push_back(v1[i]);
            }
            ++i;
        } else if (v1[i] > v2[j]) {
            ++j;
        } else {
            ++i;
        }
    }
    while (i < v1.size()) {
        if (v.empty() or v1[i] != v.back()) {
            v.push_back(v1[i]);
        }
        ++i;
    }
    return v;
}

int main() { }
