"""
Module to draw an H-tree.

original author: Jordi Cortadella
date: Oct 10th, 2020

The module uses turtle: https://docs.python.org/3/library/turtle.html
"""

import turtle
import easyinput


def draw_H(x, y, s):
    """
    Draw an H of size s with center at (x, y). It assumes that the pen is up.
    After drawing the H, it returns the pen to the original state.
    """

    turtle.goto(x - s, y + s)
    turtle.pendown()
    turtle.goto(x - s, y - s)
    turtle.penup()
    turtle.goto(x + s, y - s)
    turtle.pendown()
    turtle.goto(x + s, y + s)
    turtle.penup()
    turtle.goto(x + s, y)
    turtle.pendown()
    turtle.goto(x - s, y)
    turtle.penup()


def h_tree(x, y, n, s):
    """
    Draw an h-tree with n levels centered at the current pointurtle. s is half
    of the length of the main trunk of the tree. The function assumes the
    pen is up. After drawing the tree, the function returns the pen to its
    original position, and the pen is up.
    """

    if n > 0:
        draw_H(x, y, s)
        h_tree(x-s, y+s, n-1, s/2)
        h_tree(x+s, y-s, n-1, s/2)
        h_tree(x+s, y+s, n-1, s/2)
        h_tree(x-s, y-s, n-1, s/2)


def main():
    n = 5  # Number of levels
    s = 200  # size of the tree (from center to one size of the main H)

    # Notice that the width of the window should hold an H-tree with total size
    # 2*(s + s/2 + s/4 + s/8 + ...) = 2s (1 + 1/2 + 1/4 + 1/8 + ...) < 4s
    # We will give 10 extra pixels to have some white frame at the boundaries
    turtle.setup(width=4 * s + 10, height=4 * s + 10)  # Size of the window.

    # By default, the coordinate (0,0) is always in the middle of the window
    # We do not need to call turtle.setworldcoordinates(...)
    turtle.speed(10)  # We speed up the turtle
    turtle.hideturtle()  # We hide the head of the turtle
    # According to the specification, the pen must be initially up.
    turtle.penup()
    h_tree(0, 0, n, s)  # Let's draw the tree!

    # wait for a key to not close window
    easyinput.read(chr)


main()
