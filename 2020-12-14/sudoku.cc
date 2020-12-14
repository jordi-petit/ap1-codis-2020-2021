#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using Conjunt = vector<bool>;
using Sudoku = vector<vector<Conjunt>>;

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

void escriure_sudoku(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << element_unic(s[i][j]) + 1 << " ";
        }
        cout << endl;
    }
}

void xivato_sudoku(const Sudoku& s)
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

void casella_resolta(const Sudoku& s, int& i, int& j)
{
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (cardinal(s[i][j]) == 1) {
                return;
            }
        }
    }
    assert(false);
}

void propogar_restriccions(Sudoku& s, int i, int j)
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

void propagar_restriccions_a_tot(Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cardinal(s[i][j]) == 1) {
                propogar_restriccions(s, i, j);
            }
        }
    }
}

void resoldre(Sudoku& s)
{
    Sudoku c = s;
    while (true) {
        propagar_restriccions_a_tot(s);
        xivato_sudoku(s);
        if (s == c) {
            return;
        }
        c = s;
    }
}

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

int main()
{
    Sudoku s = llegir_sudoku();
    xivato_sudoku(s);
    resoldre(s);
    if (resolt(s)) {
        escriure_sudoku(s);
    } else {
        cout << "no hi ha solució" << endl;
    }
}
