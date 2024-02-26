def nr_perf(n):
    s=0
    for d in range(1,(n//2)+1):
        if n%d==0:
            s+=d
    if s==n:
        return True
    else:
        return False




def unu(m):
    sem=True
    for i in range(0, len(m)):
        s=0
        for j in range(0,len(m[i])):
            s+=m[j][i]
            print(m[j][i])
        if nr_perf(s) == False:
            sem=False
    return sem



def suma_lista(m,i,j):
    s=0
    for x in range(0,len(m[i])):
        s+=m[i][x]
    s-=m[i][j]
    return s

m=[[4,3,1],[1,2,1],[0,5,1]]

def doi(m):
    a=[]
    for i in range(0, len(m)):
        sem=True
        if m[i][i]!=suma_lista(m,i,i):
            sem=False
        if sem==True:
            a.append('True')
        else:
            a.append('False')
    print(a)

def is_sort_asc(l):
    flag = 0
    i = 1
    while i < len(l):
        if(l[i] < l[i - 1]):
            flag = 1
        i += 1
      
    if (not flag) :
        return True
    else :
        return False

def is_sort_desc(l):
    flag = 0
    i = 1
    while i < len(l):
        if(l[i] < l[i - 1]):
            flag = 1
        i += 1
      
    if (not flag) :
        return True
    else :
        return False



def trei(m):
    sem=True
    if is_sort_asc(m[0]):
        sem=True
    for i in range(1,len(m)):
        if(i%2==0):
            if is_sort_asc(m[i]):
                if m[i][len(m[i]-1)]<m[i-1][0]:
                    sem=True
            else: 
                sem=False
        else:
            if not is_sort_desc(m[i]) and m[i][0]>m[i-1][len(m[i])-1]:
                sem=False
    return sem

m = [[1,2,3],[6,5,4],[7,8,9]]

def patru(m):
    res=[]
    for i in range(0, len(m)):
        max=0
        for j in range(0,len(m[i])):
            if len(m[i][j])>max:
                max=len(m[i][j])
        res.append(max)
    print(res)


def palindrom(x):
    return x==x[::-1]

def cinci():
    dict={}
    fr = open("C:\\Users\\Radu\\Desktop\\python\\sapt6\\text.txt", 'r')
    fw = open("C:\\Users\\Radu\\Desktop\\python\\sapt6\\text.txt", 'w') 
    for line in fr:
        m[line]=line.strip().split(" ")

    for i in range(0, len(m)):
        for j in range(0,len(m[i])):
            if palindrom(m[i][j]):
                if m[i][j] in dict:
                    dict[m[i][j]]+=1
                else:
                    dict[m[i][j]]=1
    print(dict)

cinci()