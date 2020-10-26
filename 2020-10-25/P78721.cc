#include <iostream>
#include <string>
using namespace std;

int main()
{
    string p, s;
    cin >> p;
    while (cin >> s and s != "END") {
        if (p < s) {
            cout << p << endl;
            p = s;
        } else {
            cout << s << endl;
        }
    }
    cout << p << endl;
}
