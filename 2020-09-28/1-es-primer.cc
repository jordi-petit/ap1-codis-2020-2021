#include <iostream>
using namespace std;

// indica si n és un nombre primer o no
// precondició: n és un natural
bool es_primer(int n)
{
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (es_primer(n)) {
        cout << n << " es primer" << endl;
    } else {
        cout << n << " no es primer" << endl;
    }
}
