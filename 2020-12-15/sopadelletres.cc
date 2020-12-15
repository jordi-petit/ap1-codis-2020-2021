// Marta N

#include <iostream>
#include <vector>
using namespace std;

//no haver d'escriure sempre el mateix
using filalletra = vector<char>;
using matriulletra = vector<filalletra>;
using filauntuacio = vector<int>;
using matr iupuntuacio = vector<filapuntuacio>;

int main()
{
    //creem les dos matrius:
    int f, c;
    while (cin >> f >> c) { //més d'una sopa de lletres
        //matriu lletres
        matriulletra ll(f, filalletra(c));
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++)
                cin >> ll[i][j];
        }
        //matriu puntuacio
        matriupuntuacio p(f, filapuntuacio(c));
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++)
                cin >> p[i][j];
        }
        //paraules que hem de tenir en compte
        int a;
        cin >> a;
        //comença el programa
        for (int i = 0; i < a; i++) {
            string o; //vector de char
            cin >> o;
            int n = o.size(); //quantes caselles ocuparà
            int max = 0; //sortida (compararem puntuacio vertical i horitzontal)
            bool existeix = false; //creem un boolea per si la paraula no estigues a la sopa
                //comencem a calcular puntuacions
                //horitzontal
            for (int i = 0; i < f; i++) {
                for (int j = 0; j < c - n + 1; j++) {
                    bool encaixa = true; //serveix per no fer mes iteracions de les necessaries
                    int horitzontal = 0; //puntuacio horitzontal
                    for (int k = j; k < j + n and encaixa; k++) { //si esta be, segueix funcionant sino acaba
                        if (ll[i][k] != o[k - j])
                            encaixa = false; //apareix la matriu de lletres perque ho comparem amb l'string
                        else
                            horitzontal += p[i][k]; //matriu puntuacio
                    }
                    if (encaixa and horitzontal >= max) {
                        max = horitzontal;
                        existeix = true;
                    }
                }
            }
            //vertical
            for (int j = 0; j < c; j++) {
                for (int i = 0; i < f - n + 1; i++) {
                    bool encaixa = true;
                    int vertical = 0; //puntuacio vertical
                    for (int k = i; k < i + n and encaixa; k++) {
                        if (ll[k][j] != o[k - i])
                            encaixa = false;
                        else
                            vertical += p[k][j];
                    }
                    if (encaixa and vertical >= max) { //realment estem comparant vertical vs horitzontal
                        max = vertical;
                        existeix = true;
                    }
                }
            }
            //sortida
            if (not existeix)
                cout << "no";
            else
                cout << max;
            cout << endl;
        }
    }
}
