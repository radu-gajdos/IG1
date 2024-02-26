def shoko():
    class Schokolade:
        def __init__(self, name, preis):
            self.name=name
            self.preis=preis

    l = [Schokolade("milka", 10), Schokolade("milka", 20), Schokolade("laura", 5), Schokolade("Milka", 7),Schokolade("kandia",10)]

    print(sum(s.preis if s.name=='milka' else 0 for s in l))

def en(n):
    e=0
    if(n==0):
        return e
    else:
        print((-1^(n+1))*n*(n+1) + en(n-1))
        e+= ((-1^(n+1))*n*(n+1) + en(n-1))

m=[[12, 6, 3, 0],
  [13, 7, 4, 1],
  [14, 8, 5, 2],
  [15, 9, 6, 9]]

def sol_matrice_b(m):
    size = len(m)
    from math import ceil
    cicluri = ceil(size / 2)
    start = 0
    for _ in range(cicluri):
        for i in range(start, size):
            print(m[start][i], end=' ')
        print()
    
        for i in range(1, size):
            print(m[i][size - 1], end=' ')
        print()
    
        for i in range(size - 1, start, -1):
            print(m[size - 1][i], end=' ')
        print()
    
        for i in range(size - 1, start, -1):
            print(m[i][start], end=' ')
        print()
        print()
    
        start += 1
        size -= 1

def zpunu():
    m=[
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ]

    start=0
    res=[]
    while start<len(m):
        for i in range(start,len(m)):
            res.append(m[start][i])
        for j in range(start+1,len(m)):
            res.append(m[j][start])
        start+=1
    assert res == [1, 2, 3, 4, 7, 5, 6, 8, 9]
   
def f ():
    return 1 == 2 == True

def do_stuff(s1 : str, s2 : str):
    arr= [0]*256
    if len(s1) != len(s2):
        return False
    for i in range (len(s1)):
        arr[s1[i]] += 1
        arr[s2[i]] -= 1
    for i in arr:
        if i:
            return False 
    return True

do_stuff('apa', 'pap')