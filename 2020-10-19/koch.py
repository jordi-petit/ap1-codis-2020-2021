# pinta el triangle de Koch


import turtle
import easyinput


def koch(llargada, nivells):
    """pinta la corba de koch amb la llargada i el nombre de nivells donats"""
    if nivells == 1:
        turtle.fd(llargada)
    else:
        koch(llargada/3, nivells - 1)
        turtle.left(60)
        koch(llargada/3, nivells - 1)
        turtle.right(120)
        koch(llargada/3, nivells - 1)
        turtle.left(60)
        koch(llargada/3, nivells - 1)


def triangle_koch(llargada, nivells):
    """pinta el triangle de koch amb la llargada i el nombre de nivells donats"""
    for i in range(3):
        koch(llargada, nivells)
        turtle.right(120)


def main():
    llargada = easyinput.read(float)
    assert llargada > 0
    nivells = easyinput.read(int)
    assert nivells >= 0
    turtle.speed(10)  # accelera l'animació
    triangle_koch(llargada, nivells)
    easyinput.read(chr)  # espera abans de tancar la finestra


main()
