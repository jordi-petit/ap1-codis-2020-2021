# calcula la llista de tots els nombres primers fins a un valor donat

def eratostenes(n):
    p = [True for i in range(n + 1)]
    p[0] = False
    p[1] = False
    i = 2
    while i * i <= n:
        if p[i]:
            for j in range(2 * i, n + 1, i):
                p[j] = False
        i += 1
    return p


def llista_primers(n):
    p = eratostenes(n)
    primers = []
    for i in range(len(p)):
        if p[i]:
            primers.append(i)
    return primers


print(llista_primers(20))
