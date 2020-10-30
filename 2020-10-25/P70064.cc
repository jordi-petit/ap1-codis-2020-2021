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
    // Estratègia: busquem el divisor p més petit de n (entre 2 i √n).
    // Si el trobem, és un nombre primer i per què n sigui semiprimer, cal que n / p sigui també primer.
    // Altrament (si no hi ha divisor o n / p no és primer), aleshores n no és semiprimer.
    for (p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
             q = n / p;
             b = primer(q);
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
