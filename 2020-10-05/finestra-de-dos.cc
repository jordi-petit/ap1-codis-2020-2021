#include <iostream>
#include <string>
using namespace std;

int main()
{
    int nombre_patates_grans = 0;
    string p1;
    cin >> p1;
    while (cin >> p2) {
        if (p1 == "patata" and p2 == "gran") {
            ++nombre_patates_grans;
        }
        p1 = p2;
    }
    cout << nombre_patates_grans << endl;
}
