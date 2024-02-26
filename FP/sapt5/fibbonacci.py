l=[]
a=1
l.append(a)
b=1
l.append(b)
n=int(input())
ct=1
while ct<n:
    l.append(a+b)
    temp=a
    a=b
    b+=temp
    ct+=1
print(l)

