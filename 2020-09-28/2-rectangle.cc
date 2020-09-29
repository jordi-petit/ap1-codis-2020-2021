#include <iostream>
using namespace std;

void pinta_fila(int columnes, string simbol)
{
    for (int j = 0; j < columnes; ++j) {
        cout << simbol;
    }
    cout << endl;
}

void pinta_rectangle(int files, int columnes, string simbol)
{
    for (int i = 0; i < files; ++i) {
        pinta_fila(columnes, simbol);
    }
}

void pinta_triangle(int files, string simbol)
{
    for (int i = 1; i <= files; ++i) {
        pinta_fila(i, simbol);
    }
}

int main()
{
    int files, columnes;
    string simbol;
    cin >> files >> columnes >> simbol;

    pinta_rectangle(files, columnes, simbol);
}
