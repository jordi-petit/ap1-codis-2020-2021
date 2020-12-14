from easyinput import read


def escriu(q):
    n = len(q)
    for i in range(n):
        for j in range(n):
            if q[j] == i:
                print("O", end=" ")
            else:
                print(".", end=" ")
        print()
    print()


def diag1(i, j):
    return i + j


def diag2(i, j, n):
    return n - j - 1 + i


def collocable(n, i, j, r, d1, d2):
    return not r[i] and not d1[diag1(i, j)] and not d2[diag2(i, j, n)]


def colloca(n, i, j, q, r, d1, d2):
    q[j] = i
    r[i] = True
    d1[diag1(i, j)] = True
    d2[diag2(i, j, n)] = True


def retira(n, i, j, q, r, d1, d2):
    q[j] = None
    r[i] = False
    d1[diag1(i, j)] = False
    d2[diag2(i, j, n)] = False


def compta_reines(n, q, r, d1, d2, j):
    if j == n:
        return 1
    else:
        m = 0
        for i in range(n):
            if collocable(n, i, j, r, d1, d2):
                colloca(n, i, j, q, r, d1, d2)
                m += compta_reines(n, q, r, d1, d2, j + 1)
                retira(n, i, j, q, r, d1, d2)
        return m


def reines(n):
    q = [None for j in range(n)]
    r = [False for i in range(n)]
    d1 = [False for i in range(2*n - 1)]
    d2 = [False for i in range(2*n - 1)]
    print(compta_reines(n, q, r, d1, d2, 0))


def main():
    n = read(int)
    reines(n)

main()
