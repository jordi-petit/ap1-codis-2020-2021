# programa que llegeix tres enters i n'escriu el seu màxim

import easyinput

def max2(x, y):
    if x >= y:
        return x
    else:
        return y

def max3(x, y, z):
    return max2(x, max2(y, z))

#a = easyinput.read(int)
#b = easyinput.read(int)
#c = easyinput.read(int)
a, b, c = easyinput.read(int, int, int)
print(max3(a, b, c))
