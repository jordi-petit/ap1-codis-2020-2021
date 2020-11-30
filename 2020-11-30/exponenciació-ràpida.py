"""
Algorismes per calcular x^n.
"""

def expo(x, n):
    """Exponenciació per multipliació"""
    r = 1
    for i in range(n):
        r *= x
    return r


def expo2(x, n):
    """Exponenciació per ràpida"""
    if n == 0:
        return 1
    else:
        y = expo2(x, n//2)      # divisió entera!
        if n % 2 == 0:
            return y * y
        else:
            return y * y * x
