
def fusio(v1, v2):
    """retorna la fusió ordenada de dos vectors ordenats"""
    n1 = len(v1)
    n2 = len(v2)
    i = 0
    j = 0
    v = []
    while i < n1 and j < n2:
        if v1[i] <= v2[j]:
            v.append(v1[i])
            i = i + 1
        else:
            v.append(v2[j])
            j = j + 1
    v.extend(v1[i:])
    v.extend(v2[j:])
    return v


def main():
    v1 = [1, 3, 4, 5, 6, 6]
    v2 = [2, 3, 5, 10, 11, 12]
    print(fusio(v1, v2))


main()
