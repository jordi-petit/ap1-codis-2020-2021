#include <iostream>
using namespace std;

int main()
{
    int nin; // Per llegir la sequencia d'entrada

    // Dos darrers nombres de Fibonnaci
    int prev_fib = 1, new_fib = 1;

    bool good = true; // Ens indica si tot ha anat be
    while (good and cin >> nin) {
        // Mentre anem per darrera del nombre llegit
        // anem generant la serie de Fibonacci
        while (new_fib < nin) {
            int tmp = prev_fib + new_fib;
            prev_fib = new_fib;
            new_fib = tmp;
        }
        // Si ens passem, el nombre no es de Fibonacci
        good = new_fib == nin;
    }

    if (good)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
