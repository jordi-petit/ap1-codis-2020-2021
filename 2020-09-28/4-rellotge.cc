// Funcions i accions al voltant de l'hora d'un rellotge.
// Fixeu-vos en els paràmetres d'entrada, de sortida i d'entrada-sortida
// i com es passen per valor o per referència.

#include <iostream>
using namespace std;

void escriure_hora(int h, int m, int s)
{
    cout << h << ":" << m << ":" << s << endl;
}

void llegir_hora(int& h, int& m, int& s)
{
    cin >> h >> m >> s;
}

void sumar_un_segon(int& h, int& m, int& s)
{
    ++s;
    if (s == 60) {
        s = 0;
        ++m;
        if (m == 60) {
            m = 0;
            ++h;
            if (h == 24) {
                h = 0;
            }
        }
    }
}

void descomposicio_horaria(int n, int& h, int& m, int& s)
{
    h = n / 60 / 60;
    m = n % (60 * 60) / 60;
    s = n % 60;
}

int main()
{
    int n;
    cin >> n;
    int h, m, s;
    descomposicio_horaria(n, h, m, s);

    escriure_hora(h, m, s);
    sumar_un_segon(h, m, s);
    escriure_hora(h, m, s);
    sumar_un_segon(h, m, s);
    escriure_hora(h, m, s);
}
