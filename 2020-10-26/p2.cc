// pupurri d'operacions sobre vectors de reals

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double suma(const vector<double>& v)
{
    double s = 0;
    for (double x : v) {
        s += x;
    }
    return s;
}

// precondició: v no és buit
double mitjana(const vector<double>& v)
{
    return suma(v) / v.size();
}

// precondició: x i y tenen la mateixa mida
double producte_escalar(const vector<double>& x, const vector<double>& y)
{
    assert(x.size() == y.size());
    double pe = 0;
    for (int i = 0; i < x.size(); ++i) {
        pe += x[i] * y[i];
    }
    return pe;
}

double modul(const vector<double>& x)
{
    return sqrt(producte_escalar(x, x));
}

// precondició: x i y tenen la mateixa mida
vector<double> suma_vectors(const vector<double>& x, const vector<double>& y)
{
    assert(x.size() == y.size());
    vector<double> vs(x.size());
    for (int i = 0; i < x.size(); ++i) {
        vs[i] = x[i] + y[i];
    }
    return vs;
}

void escriure(const vector<double>& v)
{
    // exercici: feu que els vectors s'escriguin en notació {1.00,2.50,6.67}
    for (double x : v) {
        cout << x << endl;
    }
}

bool es_capicua(const vector<double>& v)
{
    int n = v.size();
    for (int i = 0; i < n / 2; ++i) {
        if (v[i] != v[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void del_reves(vector<double>& v)
{
    // exercici: implementeu-ho de forma que v quedi del revés
}

vector<double> del_reves_funcio(const vector<double>& v)
{
    // exercici: implementeu-ho de forma que retorni v del revés
}

int main()
{
    // provetes

    vector<double> v = { 1.5, 2.5, 6, 2.5, -2 };
    cout << suma(v) << endl;
    cout << mitjana(v) << endl;
    vector<double> v1 = { 1, 2, 3.5 };
    vector<double> v2 = { 5, 2, 4.5 };
    cout << producte_escalar(v1, v2) << endl;
    cout << modul(v1) << endl;
    vector<double> vs = suma_vectors(v1, v2);
    escriure(vs);
}
