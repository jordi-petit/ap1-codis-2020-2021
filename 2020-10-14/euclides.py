# diferents transformacions l'algorisme d'Euclides
# per retorna el màxim comú divisor de dos naturals (zero si ambdós són zero)


# implementació iterativa

def mcd1(a, b):
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    return a


# en fem una implementació recursiva equivalent

def mcd2(a, b):
    if a == b:
        return a
    elif a > b:
        return mcd2(a - b, b)
    else:
        return mcd2(a, b - a)


# enlloc d'anar fins a la igualtat, anem una resta més enllà

def mcd3(a, b):
    if a == 0:
        return b
    elif a >= b:
        return mcd3(a - b, b)
    else:
        return mcd3(a, b - a)


# enlloc d'anar fent restes successives, podem fer un sol residu
# -> gran guany d'eficiència

def mcd4(a, b):
    if a == 0 or b == 0:
        return a + b  # el que no és zero
    elif a >= b:
        return mcd4(a % b, b)
    else:
        return mcd4(a, b % a)


# el mcd és commutatiu, ho apliquem al primer cas recursiu

def mcd5(a, b):
    if a == 0 or b == 0:
        return a + b  # el que no és zero
    elif a >= b:
        return mcd5(b, a % b)
    else:
        return mcd5(a, b % a)


# llavors podem contreure els casos

def mcd6(a, b):
    if b == 0:
        return a
    else:
        return mcd6(b, a % b)


# podem escriure amb una sola expressió amb aquesta nova sintàxi del if
# (valor1 if condició else valor2)

def mcd7(a, b):
    return a if b == 0 else mcd7(b, a % b)


# també ho podem escriure recursiu

def mcd8(a, b):
    while b != 0:
        a, b = b, a % b
    return a


# ✨🎆✨
