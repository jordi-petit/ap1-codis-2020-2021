// funció que diu si un text conté un patró

#include <iostream>
#include <string>
using namespace std;

// indica si patro es troba a partir de la posició i del text
// precondició: 0 <= i <= n - m
bool conte_a_la_posicio(const string& text, const string& patro, int i)
{
    int n = text.size();
    int m = patro.size();
    for (int j = 0; j < m; ++j) {
        if (patro[j] != text[i + j]) {
            return false;
        }
    }
    return true;
}

// indica si patro es troba dins de text
bool conte(const string& text, const string& patro)
{
    int n = text.size();
    int m = patro.size();
    for (int i = 0; i <= n - m; ++i) {
        if (conte_a_la_posicio(text, patro, i)) {
            return true;
        }
    }
    return false;
}

int main()
{
    string text, patro;
    cin >> text >> patro;
    cout << conte(text, patro) << endl;
}
