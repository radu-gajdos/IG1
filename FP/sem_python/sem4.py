#varianta cu dict
'''
def fractie():
    n=int(input('n='))
    m=int(input('m='))
    return {'n':n, 'm':m}

def add(a,b):
    n=a['n']*b['m']+b['n']*a['m']
    m=a['m']*b['m']
    return {'n':n, 'm':m}

'''
#varianta cu tuplet
def fractie():
    n=int(input('n='))
    m=int(input('m='))
    return (n,m)

def add(a,b):
    n=a[0]*b[1]+b[0]*a[1]
    m=a[1]*b[1]
    return (n,m)

def cmmdc(a,b):
    while a!=b:
        if(a>b):
            a-=b
        else:
            b-=a
    return a

def kurz(a):
    temp=cmmdc(a[0],a[1])
    return (a[0]//temp, a[1]//temp)

def adauga(l, nr, poz):
    l.insert(poz,nr)

def scoate(l, poz):
    l.remove(l[poz])

def sum(l):
    s=l[0]
    for i in range(1,len(l)):
        s=add(s, l[i])
    return kurz(s)




