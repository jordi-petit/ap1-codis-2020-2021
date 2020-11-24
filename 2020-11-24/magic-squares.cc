// Sergio C.

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

bool nombres_repetits(const Matriu& m)
{
    // prec: l'entrada és una matriu quadrada n*n on tots els valors són <= n^2

    int n = m.size();
    vector<bool> b(n * n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = m[i][j];
            if (b[x - 1])
                return true;
            b[x - 1] = true;
        }
    }
    return false;
}

int diagonal1(const Matriu& m)
{

    // retorna la suma de la primera diagonal

    int n = m.size();
    int d = 0;

    for (int i = 0; i < n; ++i) {
        int j = i;
        d += m[i][j];
    }
    return d;
}

int diagonal2(const Matriu& m)
{

    // retorna la suma de la segona diagonal

    int n = m.size();
    int d = 0;

    int i = 0;
    for (int j = n - 1; j >= 0; --j) {
        d += m[i][j];
        ++i;
    }
    return d;
}

bool files_columnes(const Matriu& m, int suma)
{

    // compara la suma de cadascuna de les files i cadascuna de les columnes i
    // retorna true si totes coincideixen amb la suma de la primera diagonal

    int n = m.size();

    for (int i = 0; i < n; ++i) {
        int files = 0;
        int columnes = 0;
        for (int j = 0; j < n; ++j) {
            files += m[i][j];
            columnes += m[j][i];
        }
        if (files != suma or columnes != suma)
            return false;
    }
    return true;
}

bool magic_square(const Matriu& m)
{

    // mirem que els números no es repeteixen
    if (nombres_repetits(m))
        return false;

    // prenem com a constant el valor de la suma de la primera diagonal
    const int suma = diagonal1(m);

    // comparem el valor de la primera diagonal amb el de la segona
    if (suma != diagonal2(m))
        return false;

    // retornem true si el valor de la suma de la diagonal coincideix amb el de
    // cadascuna de les files i columnes del quadrat
    return files_columnes(m, suma);
}

int main()
{
    int n;
    while (cin >> n) {

        Matriu m(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
            }
        }

        if (magic_square(m))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
