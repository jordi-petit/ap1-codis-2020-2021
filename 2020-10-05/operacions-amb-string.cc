// llegir dos textos i comparar-los

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a > b) {
        cout << a << " es mes gran que " << b << endl;
    } else {
        cout << a << " es mes petit o igual que " << b << endl;
    }
}
