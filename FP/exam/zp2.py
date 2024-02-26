def generiere_matrix(n):
    matrix = [[0] * n for i in range(n)]
    zahl = n * n
    for i in range(n-1,-1,-1):
        for j in range(n):
            matrix[i][j] = zahl
            zahl -= 1
    return matrix

n=4
m=generiere_matrix(n)
for i in range(n):
        print(m[i])

def E(n):
    if n == 1:
        return 1 * 2
    else:
        return ((-1) ** (n + 1)) * n * (n + 1) + E(n - 1) # adica (−1)𝑛+1·𝑛·(𝑛+1) + recursiv pana la 1

print(E(3))