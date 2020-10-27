#include <cmath>
#include <iostream>
using namespace std;

int compta_solucions(int a, int b, int c, int d)
{
    int solucions = 0;
    for (int i = a; i <= b; ++i) {
        for (int j = c; j <= d; ++j) {
            int z = sqrt(i * i + j * j);
            if (i * i + j * j == z * z) {
                ++solucions;
            }
        }
    }
    return solucions;
}

int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        int solucions = compta_solucions(a, b, c, d);
        cout << solucions << endl;
    }
}
