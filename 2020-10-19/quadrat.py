
"""quadrats bonics en coloraines"""

import turtle
import easyinput
import random


def quadrat(mida):
    for i in range(4):
        turtle.forward(mida)
        turtle.right(90)


def main():
    turtle.hideturtle()
    turtle.speed(10)
    for i in range(20):
        r = random.random()
        g = random.random()
        b = random.random()
        turtle.pencolor(r, g, b)
        quadrat(100)
        turtle.right(18)
    easyinput.read(chr)


main()
