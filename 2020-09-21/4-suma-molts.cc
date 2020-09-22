// programa que suma una seqüència de naturals, accabada per un negatiu

#include <iostream>
using namespace std;

int main()
{
    int s = 0;
    int x;
    cin >> x;
    while (x >= 0) {
        s = s + x;
        cin >> x;
    }
    cout << s << endl;
}
