// programa que suma n enters, on n és donat al principi de l'entrada

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = 0;
    int i = 1;
    while (i <= n) {
        int x;
        cin >> x;
        s = s + x;
        i = i + 1;
    }
    cout << s << endl;
}
