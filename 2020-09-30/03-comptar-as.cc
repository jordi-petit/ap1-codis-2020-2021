// programa que compta quantes as hi ha en un text

#include <iostream>
using namespace std;

int main()
{
    int n_as = 0;
    char c;
    while (cin >> c) {
        if (c == 'a' or c == 'A') {
            ++n_as;
        }
    }
    cout << n_as << endl;
}
