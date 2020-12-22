#include <iostream>
#include <vector>
#include <string>

using namespace std;

using Matriu = vector<vector<int>>;
using Disposicio = vector<int>;

// Funció auxiliar recursiva que acaba trobant la disposició òptima d'asseure a la gent.
int optimitza(const Matriu& manies, Disposicio& optima, Disposicio& actual, int cost_minim, int cost_actual, vector<bool>& assegut, int i) {
  // Si aconseguim un cost menor al millor cost que tenim fins ara, seguim tractant aquesta disposició. En cas contrari, ja no seguim.
  if (cost_actual < cost_minim) {
    int n = actual.size();

    if (i == n) {  // Si i == n, llavors haurem acabat d'asseure a tothom i la disposició que tinguem ara serà millor que la que teníem fins ara.
      cost_minim = cost_actual;
      optima = actual;
    } else { // Si no (si i < n), seguim asseient a la gent que encara no està asseguda.
      for (int j = 1; j < n; ++j) { // j comença a l'1 perquè la primera posició ja sempre està fixada (el de l'esquerra de tot ja està assegut).
        if (not assegut[j]) {
          actual[i] = j;
          assegut[j] = true;
          cost_minim = optimitza(manies, optima, actual, cost_minim, cost_actual + manies[actual[i - 1]][j], assegut, i + 1);
          assegut[j] = false;
        }
      }
    }
  }

  return cost_minim;
}


// Retorna el "cost" de la disposició òptima i guarda la disposició òptima en el paràmetre de sortida 'optima'.
int calcula_disposicio_optima(const Matriu& manies, Disposicio& optima) {
  int n = optima.size();

  // Al principi tothom està dret.
  vector<bool> assegut(n, false);
  Disposicio actual(n);

  // Asseiem la primera persona (el 0) a la posició de més a l'esquerra (la posició 0).
  actual[0] = 0;
  assegut[0] = true;

  return optimitza(manies, optima, actual, 100000000, 0, assegut, 1);
}


int main() {
  int n;
  while (cin >> n) {
    // Llegim els noms.
    vector<string> noms(n);
    for (int i = 0; i < n; ++i) cin >> noms[i];

    // Llegim la matriu de manies.
    Matriu manies(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cin >> manies[i][j];
    }

    // Calculem la disposició òptima i el seu "cost".
    Disposicio optima(n);
    int cost_minim = calcula_disposicio_optima(manies, optima);

    // Escrivim el cost i els noms ordenats en la disposició òptima.
    cout << cost_minim << endl;
    cout << noms[0];
    for (int i = 1; i < n; ++i) cout << ' ' << noms[optima[i]];
    cout << endl;
  }
}
