/*
P20006
Expressió prefixada
*/

#include <cassert>
#include <iostream>
using namespace std;

// indica si el caràcter c és un dígit
bool es_digit(char c)
{
    return c >= '0' and c <= '9';
}

// converteix un dígit al seu enter corresponent
int caracter_a_enter(char c)
{
    return c - '0';
}

// llegeix i avalua una expressió prefixada
int avaluar()
{
    char c;
    cin >> c;
    if (es_digit(c)) {
        return caracter_a_enter(c);
    } else {
        assert(c == '+' or c == '-' or c == '*');
        int op1 = avaluar();
        int op2 = avaluar();
        if (c == '+') {
            return op1 + op2;
        } else if (c == '-') {
            return op1 - op2;
        } else {
            return op1 * op2;
        }
    }
}

int main()
{
    cout << avaluar() << endl;
}
