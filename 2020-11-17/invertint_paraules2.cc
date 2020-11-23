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
    int n;
    cin >> n;

    vector<string> paraules(n);

    for (int i = n - 1; i >= 0; --i) {
        cin >> paraules[i];
    }

    for (int i = 0; i < n; ++i) {
        girar_paraula(paraules[i]);
    }
}
