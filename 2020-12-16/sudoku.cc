#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Conjunt de valors de 0 a 8 com a vector de booleans.
using Conjunt = vector<bool>;

// Un Sudoku correspon a una matriu 9x9 de Conjunts.
using Sudoku = vector<vector<Conjunt>>;

// Retorna el nombre d'elements en un conjunt
int cardinal(const Conjunt& c)
{
    int n = 0;
    for (int i = 0; i < 9; ++i) {
        if (c[i]) {
            ++n;
        }
    }
    return n;
}

// Retorna l'únic element d'un conjunt que només té un element.
// Prec: el conjunt té cardinal 1.
int element_unic(const Conjunt& c)
{
    assert(cardinal(c) == 1);
    for (int i = 0; i < 9; ++i) {
        if (c[i]) {
            return i;
        }
    }
    assert(false);
}

// Diu si un Sudoku està resolt (tots els seus conjunts tenen un sol element).
bool resolt(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinal(s[i][j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

// Diu si un Sudoku ha fallat resolt (algun dels seus conjunts és buit).
bool fallat(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinal(s[i][j]) == 0) {
                return true;
            }
        }
    }
    return false;
}

// Retorna el sudoku llegit de l'entrada.
Sudoku llegir_sudoku()
{
    Sudoku s(9, vector<Conjunt>(9, vector<bool>(9, true)));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c;
            cin >> c;
            if (c != '.') {
                int d = c - '0' - 1;
                s[i][j] = vector<bool>(9, false);
                s[i][j][d] = true;
            }
        }
    }
    return s;
}

// Escriu un sudoku tal com cal.
// Prec: el sudoku està solucionat.
void escriure(const Sudoku& s)
{
    assert(resolt(s));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << element_unic(s[i][j]) + 1 << " ";
        }
        cout << endl;
    }
}

// Escriu un sudoku amb els seus conjunts (per treballar).
void xivar(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << "[";
            for (int k = 0; k < 9; ++k) {
                if (s[i][j][k]) {
                    cout << k;
                } else {
                    cout << " ";
                }
            }
            cout << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

// Propaga les restriccions de la casella i,j.
// Prec: el cardinal del conjunt de la casella i,j és 1.
void propogar_restriccions_casella(Sudoku& s, int i, int j)
{
    int e = element_unic(s[i][j]);

    // treure de la fila i
    for (int jj = 0; jj < 9; ++jj) {
        if (jj != j) {
            s[i][jj][e] = false;
        }
    }
    // treure de la columna j
    for (int ii = 0; ii < 9; ++ii) {
        if (ii != i) {
            s[ii][j][e] = false;
        }
    }
    // treure de la caixa de i, j
    int ci = (i / 3) * 3;
    int cj = (j / 3) * 3;
    for (int ii = 0; ii < 3; ++ii) {
        for (int jj = 0; jj < 3; ++jj) {
            if (ci + ii != i or cj + jj != j) {
                s[ci + ii][cj + jj][e] = false;
            }
        }
    }
}

// Propaga les restriccions de totes les caselles.
void propagar_restriccions_arreu(Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinal(s[i][j]) == 1) {
                propogar_restriccions_casella(s, i, j);
            }
        }
    }
}

// Prova les restriccions del sudoku tant com es pugui.
void propagar_restriccions(Sudoku& s)
{
    Sudoku s2;
    do {
        s2 = s;
        propagar_restriccions_arreu(s);
    } while (s != s2);
}

void triar_cella(const Sudoku& s, int& i, int& j)
{
    int m = 10;
    for (int ii = 0; ii < 9; ++ii) {
        for (int jj = 0; jj < 9; ++jj) {
            int c = cardinal(s[ii][jj]);
            if (c > 1 and c < m) {
                m = c;
                i = ii;
                j = jj;
            }
        }
    }
}

// Prova de resoldre el sudoku.
void resoldre(Sudoku& s)
{
    propagar_restriccions(s);
    if (not resolt(s) and not fallat(s)) {
        int i, j;
        triar_cella(s, i, j);
        Sudoku s2 = s;
        for (int k = 0; k < 9; ++k) {
            if (s[i][j][k]) {
                s[i][j] = Conjunt(9, false);
                s[i][j][k] = true;
                resoldre(s);
                if (resolt(s)) {
                    return;
                }
                s = s2;
            }
        }
    }
}

// Llegeix un sudoku i prova de resoldre'l, tot escrivint el resultat.
int main()
{
    Sudoku s = llegir_sudoku();
    resoldre(s);
    if (resolt(s)) {
        escriure(s);
    } else {
        cout << "no hi ha solució" << endl;
    }
}
