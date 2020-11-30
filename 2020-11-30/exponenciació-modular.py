"""
Exponenciació modular per calcular x^n mod m.
"""


def expmod(x, n, m):
    if n == 0:
        return 1
    else:
        y = expmod(x, n//2, m)
        if n %2 == 0:
            return (y * y) % m
        else:
            return (((y * y) % m) * (x % m)) % m
