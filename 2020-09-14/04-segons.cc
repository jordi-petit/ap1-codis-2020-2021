// Descomposició horària

#include <iostream>
using namespace std;

int main()
{
    // llegim les dades d'entrada
    int nombre_de_segons;
    cin >> nombre_de_segons;

    // calculem les dades de sortida
    int hores = nombre_de_segons / (60 * 60);
    int minuts = (nombre_de_segons % (60 * 60)) / 60;
    int segons = nombre_de_segons % 60;

    // escribim les dades de sortida
    cout << hores << " hores" << endl;
    cout << minuts << " minuts" << endl;
    cout << segons << " segons" << endl;
}
