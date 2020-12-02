"""
Nombres de Fibonacci a la Pitonesca
"""

import jutge
import time
import math


def fibo1(n):
    """calcula l'n-èsim nombre de Fibonacci recursivament - O(ϕ^n)"""
    if n <= 1:
        return n
    else:
        return fibo1(n - 1) + fibo1(n - 2)


def fibo2(n):
    """calcula l'n-èsim nombre de Fibonacci iterativament amb els dos anteriors - O(n)"""
    a, b = 0, 1
    for i in range(n):
        a, b = b, a + b
    return a


def fibo3(n):
    """calcula l'n-èsim nombre de Fibonacci amb fórmula matemàtica - O(1)
       ⚠ té problemes de resolució i falla a partir de n=71
    """
    ϕ = (1 + math.sqrt(5)) / 2
    return int(ϕ**n / math.sqrt(5) + 1/2)


def fibo4(n):
    """calcula l'n-èsim nombre de Fibonacci amb exponenciació ràpida - O(log n)"""
    M = [[1, 1],
         [1, 0]]
    Mn = eleva(M, n)
    return Mn[1][0]


def multiplica(A, B):
    """retorna A*B on A i B són matrius 2×2"""
    [[a, b],
     [c, d]] = A        # preciós
    [[p, q],            # ❤ ❤ ❤ ❤
     [r, s]] = B
    return [[a*p + b*r, a*q + b*s],
            [c*p + d*r, c*q + d*s]]


def eleva(M, n):
    """retorna M^n on M és matriu 2×2, usa exponenciació ràpida"""
    if n == 0:
        return [[1, 0],
                [0, 1]]
    else:
        Mn2 = eleva(M, n//2)
        if n % 2 == 0:
            return multiplica(Mn2, Mn2)
        else:
            return multiplica(multiplica(Mn2, Mn2), M)


def main():
    """prova les funcions anteriors tot cronometrant el seu temps"""

    for n in range(100):

        print(n, '\t', end='')

        for f in [fibo1, fibo2, fibo3, fibo4]:
            t1 = time.time()
            r = f(n) if f is not fibo1 or n <= 40 else '???'
            t2 = time.time()
            print(r, '\t', round(t2 - t1, 4), '\t', end='')

        print()


main()
