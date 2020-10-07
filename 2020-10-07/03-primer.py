# programa que llegeix un natural i diu si és o no primer

from easyinput import read

def es_primer(x):
    """donat un natural x, diu si x és o no un nombre primer"""
    if x <= 1:
        return False
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i = i + 1
    return True

def main():
    """programa principal"""
    n = read(int)
    if es_primer(n):
        print(n, "és primer")
    else:
        print(n, "no és primer")

main()
