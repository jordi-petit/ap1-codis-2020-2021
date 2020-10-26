#include <iostream>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    cout << "----------" << endl;
    while (n > 0) {
        int d = n % b;
        n /= b;
        for (int r = 0; r < d; ++r) {
            cout << 'X';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}
