/*
Programa que llegeix un llistat d'estudiants (nom, id, nota)
i l'ordena per nota (decreixentment), per nom i per id.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Estudiant {
    string nom;
    int id;
    double nota;
};

using Estudiants = vector<Estudiant>;

Estudiant llegir_estudiant()
{
    Estudiant estudiant;
    cin >> estudiant.nom >> estudiant.id >> estudiant.nota;
    return estudiant;
}

Estudiants llegir_estudiants()
{
    int n;
    cin >> n;
    Estudiants estudiants(n);
    for (Estudiant& estudiant : estudiants) {
        estudiant = llegir_estudiant();
    }
    return estudiants;
}

void escriure_estudiant(const Estudiant& estudiant)
{
    cout << estudiant.nom << '\t' << estudiant.id << '\t' << estudiant.nota << endl;
}

void escriure_estudiants(const Estudiants& estudiants)
{
    for (const Estudiant& estudiant : estudiants) {
        escriure_estudiant(estudiant);
    }
}

// indica si a < b en el criteri escollit
bool comparador_estudiants(const Estudiant& a, const Estudiant& b)
{
    if (a.nota != b.nota) {
        return a.nota > b.nota; // criteri decreixent
    }
    if (a.nom != b.nom) {
        return a.nom < b.nom;
    }
    return a.id < b.id;
}

void ordenar_estudiants(Estudiants& estudiants)
{
    sort(estudiants.begin(), estudiants.end(), comparador_estudiants);
}

int main()
{
    Estudiants estudiants = llegir_estudiants();
    ordenar_estudiants(estudiants);
    escriure_estudiants(estudiants);
}
