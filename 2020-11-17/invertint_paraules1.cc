// Alexandra G.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void girar_paraula(const string& paraula)
{
    int mida = paraula.size();
    for (int i = mida - 1; i >= 0; --i) {
        cout << paraula[i];
    }
    cout << endl;
}

int main()
{
    string paraula;
    while (cin >> paraula) {
        girar_paraula(paraula);
    }
}
