#include <iostream>
using namespace std;

// retorna si n no té cap divisor entre i i n-1
bool primer(int n, int i)
{
    return i * i > n or (n % i != 0 and primer(n, i + 1));
}

bool primer(int n)
{
    return n >= 2 and primer(n, 2);
}

void semiprimer(int n, bool& b, int& p, int& q)
{
    for (p = 2; p * p <= n; ++p) {
        if (n % p == 0 and primer(p) and primer(n / p)) {
            b = true;
            q = n / p;
            return;
        }
    }
    b = false;
}

int main()
{
    int n;
    while (cin >> n) {
        cout << n << ": ";
        bool b;
        int p, q;
        semiprimer(n, b, p, q);
        if (b) {
            cout << "yes (" << p << "," << q << ")" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
