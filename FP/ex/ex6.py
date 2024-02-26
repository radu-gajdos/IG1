#a. Lesen Sie eine Sequenz von natürlichen Zahlen (Sequenz mit 0 beendet) und bestimmen
#Sie die Anzahl von 0 Ziffern des Produkts der gelesenen Zahlen.
def sase_a():
    n= int(input())
    prod=1
    ct=0
    while n!=0 :
        prod=prod*n
        n= int(input())
    while prod!=0:
        if prod%10 == 0:
            ct=ct+1
        prod=prod/10
    print(ct)

#sase_a()

def prim(num):
    sem=True
    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                sem = False
    return sem

#b. Gegeben sei ein Vektor von Zahlen, finde die längste zusammenhängende Teilfolge so,
#dass die Summe von zwei aufeinanderfolgenden Elementen eine Primzahl ist.
#diese Losung beinhaltat auch dem lezten Nummer des arrays
def sase_b():
    liste=[2, 5, 3, 5, 2,3,2,3,2, 3, 9, 3, 5, 2, 3, 8, 3, 2, 6]
    result=[]
    temp=[]

    for i in range(1, len(liste)):
        if prim(liste[i]+liste[i-1]):
            temp.append(liste[i-1])
        else:
            temp.append(liste[i-1])
            if len(temp)>len(result):
                result=temp
            temp=[]
    #leztes Nummer if
    if(prim(liste[-1])):
        temp.append(liste[-1])
    #end
    if len(temp) > len(result):
        result=temp

    print(result)

sase_b()

