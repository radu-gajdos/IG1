def unu_v1(l, n):
    for i in range(len(l)-1):
        for j in range(i+1,len(l)):
            if(l[i]+l[j]==n):
                return i,j
    return None

l=[1, 2, 2, 5, 2, 8]
n=10
#print(unu_v1(l, n))

##2 si 5
def doi(a,b):
    c=0
    for i in range(0, len(a)):
        if(i<len(a) and i<len(b)):
            c=c*10+(eval(a[i])+eval(b[i]))
        else:
            if(len(a)>len(b)):
                for j in range(i, len(a)):
                    c=c*10+eval(a[j])
            else:
                for j in range(i, len(b)):
                    c=c*10+eval(b[j])
            c=str(c) 
            return c, type(c)

    c=str(c) 
    return c, type(c)

a = '1212312231231'
b = '55534123'
print(doi(a,b))

def swap(c, i, j):
    c = list(c)
    c[i], c[j] = c[j], c[i]
    return ''.join(c)

def trei(s):
    voc='aeiou'
    max=len(s)
    for i in range(0,max):
        if s[i] in voc:
            print(s[i])
            for j in range(max-1, len(s)//2, -1):
                if s[j] in voc:
                    print(s[j])
                    swap(s, i, j)
                    max-=j+1
                    break
    return s
s='Terminator'
print(trei(s))

