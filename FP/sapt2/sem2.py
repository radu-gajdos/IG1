def strtodict():
    s='abcdeface'
    d={}
    for i in s:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    print(d)

#strtodict()

def strpalindrom():
    s='aabbaa'
    l=len(s)
    for i in range(0,l//2):
        if s[i]!=s[l-i-1]:
            return False
    return True

#print(strpalindrom())

def str_find(a,b):
    for i in range(0,len(a)):
        if(a[i:i+len(b)] == b):
            return i
a='sssngtri'
b='tri'
print(str_find(a,b))