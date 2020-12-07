// P12284
// programa que llegeix una seqüència de n paraules i escriu les k paraules més freqüents, en ordre alfabètic en cas d'empat.
// Alba P

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comparador(const Paraulesa b, const Paraules& b)
{
    if (a.freq == b.freq)
        return a.paraula < b.paraula;
    return a.freq > b.freq;
}

struct Paraules {
    string paraula;
    int freq;
};

vector<Paraules> llegeix_paraules(int n)
{ //retorna el vector u que indica la freqüència de cada paraula
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    vector<Paraules> u(n);
    u.push_back({ v[0], 1 });
    for (int i = 1; i < n; i++) {
        while (i < n and v[i] == u[u.size() - 1].paraula) {
            i++;
            u[u.size() - 1].freq++;
        }
        if (i < n)
            u.push_back({ v[i], 1 });
    }
    return u;
}

void ordena_vector(vector<Paraules>& u)
{
    sort(u.begin(), u.end(), comparador);
}

void escriu_k_paraules(const vector<Paraules>& u, int k)
{
    for (int i = 0; i < k; i++)
        cout << u[i].paraula << endl;
}

void paraules_mes_frequents(int n, int k)
{
    vector<Paraules> u = llegeix_paraules(n);
    ordena_vector(u);
    escriu_k_paraules(u, k);
}

int main()
{
    int n, k;
    while (cin >> n >> k) {
        paraules_mes_frequents(n, k);
        cout << "----------" << endl;
    }
}
