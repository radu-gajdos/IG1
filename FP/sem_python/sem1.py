# / -> impartire reala 
# // -> impartire intreaga

s=0
i=1
while i<=10:
    if i%2==0:
        s+=i
    i+=1
#print(s)

l=[1,2]
#print(l[0])

def ex_1():
    b=input("Enter text: ")
    a=input("Caracterul cautat: ")
    cnt=0
    for i in range(0, len(b)):
        if b[i]==a:
            cnt+=1

    print(cnt)

#ex_1()

def ex_2():
    cuvant="abcdefghi"
    vocale="aeiou"
    nou=""
    for v in vocale:
        nou=nou.replace(v, "?")
    print(nou)

ex_2()