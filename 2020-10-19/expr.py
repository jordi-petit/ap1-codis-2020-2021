"""
P20006
Expressió prefixada
"""


from easyinput import read


def es_digit(c):
    """indica si el caràcter c és un dígit"""
    return c >= '0' and c <= '9'


def caracter_a_enter(c):
    """converteix un dígit al seu enter corresponent"""
    return ord(c) - ord('0')


def avaluar():
    """llegeix i avalua una expressió prefixada"""
    c = read(chr)
    if es_digit(c):
        return caracter_a_enter(c)
    else:
        assert c == '+' or c == '-' or c == '*'
        op1 = avaluar()
        op2 = avaluar()
        if c == '+':
            return op1 + op2
        elif c == '-':
            return op1 - op2
        else:
            return op1 * op2


def main():
    print(avaluar())


main()
