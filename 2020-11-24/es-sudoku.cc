// Laura S.

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix;

//idea general: vector de 9 booleans on si apareix un nombre dues vegades es retorna fals
//se li resta 1 perquè mentre els nombres van de l'1-9 les posicions van del 0-8
bool es_sudoku(const Matrix& c)
{
    //es mira si hi ha nombres repetits a les files
    for (int i = 0; i < 9; ++i) {
        vector<bool> v_files(9);
        for (int j = 0; j < 9; ++j) {
            if (v_files[c[i][j] - 1])
                return false;
            v_files[c[i][j] - 1] = true;
        }
    }

    //es fa el mateix per les columnes
    for (int j = 0; j < 9; ++j) {
        vector<bool> v_columnes(9);
        for (int i = 0; i < 9; ++i) {
            if (v_columnes[c[i][j] - 1])
                return false;
            v_columnes[c[i][j] - 1] = true;
        }
    }

    //es miren els subquadrats d'esquerra a dreta en 3 "files" de quadrats
    for (int i2 = 0; i2 < 9; i2 += 3) {
        for (int j2 = 0; j2 < 9; j2 += 3) {
            vector<bool> v_subquadrats(9);
            for (int i = i2; i < i2 + 3; ++i) {
                for (int j = j2; j < j2 + 3; ++j) {
                    if (v_subquadrats[c[i][j] - 1])
                        return false;
                    v_subquadrats[c[i][j] - 1] = true;
                }
            }
        }
    }

    return true;
}

//es llegeix la matriu i es determina si és un sudoku n vegades
int main()
{
    int n_casos;
    if (cin >> n_casos) {
        while (n_casos > 0) {
            Matrix sudoku(9, vector<int>(9));
            for (int i = 0; i < 9; ++i)
                for (int j = 0; j < 9; ++j)
                    cin >> sudoku[i][j];
            if (es_sudoku(sudoku))
                cout << "si" << endl;
            else
                cout << "no" << endl;
            n_casos -= 1;
        }
    }
}
