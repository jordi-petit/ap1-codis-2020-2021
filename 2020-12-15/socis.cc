// Martí P

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Data {
    int dia;
    int mes;
    int any;
};

struct Persona {
    string nom;
    int dni;
    Data naixement;
    string municipi;
};

using Persones = vector<Persona>;

struct Soci {
    int dni;
    bool la_junta;
    Data inscripcio;
};

using Socis = vector<Soci>;

Data llegir_data()
{
    Data data;
    cin >> data.dia >> data.mes >> data.any;
    return data;
}

bool la_junta()
{
    char c;
    cin >> c;
    return c == 'S';
}

// llegeix el nombre de persones i per cada persona llegeix les seves dades
Persones llegir_persones()
{
    int n_persones;
    cin >> n_persones;
    Persones persones(n_persones);
    for (int i = 0; i < n_persones; ++i) {
        cin >> persones[i].nom >> persones[i].dni;
        persones[i].naixement = llegir_data();
        cin >> persones[i].municipi;
    }
    return persones;
}

// llegeix el nombre de soci i per cada soci llegeix les seves dades
Socis llegir_socis()
{
    int n_socis;
    cin >> n_socis;
    Socis socis(n_socis);
    for (int i = 0; i < n_socis; ++i) {
        cin >> socis[i].dni;
        socis[i].la_junta = la_junta();
        socis[i].inscripcio = llegir_data();
    }
    return socis;
}

// retorna el nombre de socis que estan a la junta, nascuts en el municipi donat
// després de l'any donat
int nombre_de_socis_joves_a_la_junta_en_un_municipi(const Persones& persones, const Socis& socis, string municipi, int any)
{
    int n_socis = size(socis);
    int suma_socis = 0;
    int j = 0;
    for (int i = 0; i < n_socis; ++i) {
        if (socis[i].la_junta) {
            while (socis[i].dni >= persones[j].dni) {
                if (socis[i].dni == persones[j].dni) {
                    if (persones[j].municipi == municipi and persones[j].naixement.any >= any)
                        ++suma_socis;
                }
                ++j;
            }
        }
    }
    return suma_socis;
}

int main()
{
    Persones persones = llegir_persones();
    Socis socis = llegir_socis();
    int any;
    string municipi;
    cin >> any >> municipi;
    cout << nombre_de_socis_joves_a_la_junta_en_un_municipi(persones, socis, municipi, any);
}
