#include <cmath>
#include <iostream>
using namespace std;

bool es_solucio(int& a, int b, int& c, int& d)
{
    --c;
    int u = c;
    --a;
    while (a < b) {
        ++a;
        c = u;
        while (c < d) {
            ++c;
            int z = sqrt(a * a + c * c);
            if (a * a + c * c == z * z) {
                d = z;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (es_solucio(a, b, c, d)) {
        cout << a << "^2 + " << c << "^2 = " << d << "^2" << endl;
    } else {
        cout << "Sense solucio!" << endl;
    }
}
