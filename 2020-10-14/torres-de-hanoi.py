'''
dóna la solució de com moure n discos
a les torres de Hanoi.
'''

from easyinput import read


def hanoi(n, ori, dst, aux):
    if n > 0:
        hanoi(n - 1, ori, aux, dst)
        print(ori, '->', dst)
        hanoi(n - 1, aux, dst, ori)


def main():
    n = read(int)
    hanoi(n, 'a', 'c', 'b')


main()
