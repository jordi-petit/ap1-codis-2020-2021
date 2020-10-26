// programa que compta quants cops es repeteix el darrer element
// d'una seqüència d'enters

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 1. llegir la seqüència i desar-la en un vector
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }

    // 2. comptar repeticions del darrer element
    int ultim = v[v.size() - 1];
    int comptador = 0;
    for (int element : v) {
        if (element == ultim) {
            ++comptador;
        }
    }

    // 3. escriure el resultat
    cout << comptador << endl;
}
