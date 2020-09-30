// operacions amb majúscules i minúscules

#include <iostream>
using namespace std;

bool es_minuscula(char c)
{
    return c >= 'a' and c <= 'z';
}

// retorna c en majúsculles
// precondició: c és una minúscula
char a_majuscula(char c)
{
    // return char(int(c) - int('a') + int('A'));
    // return char(c - 'a' + 'A');
    return c - 'a' + 'A';
}

int main()
{
    char c;
    cin >> c;
    if (es_minuscula(c)) {
        cout << a_majuscula(c) << endl;
    }
}
