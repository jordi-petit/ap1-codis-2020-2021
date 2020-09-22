// programa que suma 10 enters

#include <iostream>
using namespace std;

int main()
{
    int s = 0;
    int i = 1;
    while (i <= 10) {
        int x;
        cin >> x;
        s = s + x;
        i = i + 1;
    }
    cout << s << endl;
}
