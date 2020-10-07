# programa que llegeix un natural i escriu el seu factorial

import easyinput

def factorial(n):
    f = 1
    for i in range(2, n + 1):
        f = f * i
    return f

def main():
    n = easyinput.read(int)
    print(factorial(n))

main()
