#1.EnfernenSie die Zahlen die sich wiederholen.
from audioop import reverse


def unu():
    liste=[10,10,12,14,12,10,11,11,14,11,15]
    res = [] 
    for i in liste: 
        if i not in res: 
            res.append(i)
    liste=res
    print(liste)
#unu()
#2.Schreiben Sie die Anzahl vonsymmetrischenPaaren(xy)und (yx).
def inv(n):
    inv=n%10;
    n//=10
    while n>9:
        inv=inv*10+n%10
        n//=10
    inv=inv*10+n%10
    return inv


def doi():
    liste=[10, 12, 21, 14, 11, 41, 15, 15]
    ct=0
    for i in range(0, len(liste)):
        for j in range(i+1, len(liste)):
            if(liste[i]==inv(liste[j])):
                ct+=1
    print(ct)

#doi()

#Generieren Sie die größtemöglicheZahl, die aus der Konkatenationder Elemente der Liste gebildet ist.
def trei():
    liste=[10, 12, 51, 14, 11, 41, 15, ]
    liste.sort(reverse=True)
    nou=liste[0]
    for i in range(1, len(liste)):
        nou=nou*100+liste[i]
        
    print(nou)

#trei()

#Verschlüsseln  Sie  die  Elemente  der  Liste,  indem  Sie dasersteElement  als  Schlüssel benützen und die Methode selbst wählen(+, *, XOR).
def patru():
    liste=[10, 12, 51, 14, 11, 41, 15, ]
    cheie=liste[0]
    for i in range(1, len(liste)):
        liste[i]*=cheie
    print(liste)    

#patru()

#Filtern Sie die Zahlen, die eine bestimmte Beziehung zwischen Zahlen haben, die in einem String angegeben wird.(z.B:“x=y*3”, “x/y=2“, ...)


def fct(a):
    if '+' in a:
        a=a.split('+')
        x=int(a[0])
        y=int(a[1])
        return x+y
    elif '-' in a:
        a=a.split('-')
        x=int(a[0])
        y=int(a[1])
        return x-y
    elif '*' in a:
        a=a.split('*')
        x=int(a[0])
        y=int(a[1])
        return x*y
    elif '/' in a:
        a=a.split('/')
        x=int(a[0])
        y=int(a[1])
        return x//y
    return int(a)
#varianta fara cu eval-homemade(fct()), varianta cu eval() ->Notion->info->Fundamentele->Sapt3.->Lab
def cinci():
    d={0:'0',1:'1',2:'2',3:'3',4:'4',5:'5',6:'6',7:'7',8:'8',9:'9'}#dictionarul de conversie din type:int in type:string
    exrp='x/y=2'#operatia matematica introdusa ca type:string
    res=[]#lista noua formata doar din numerele ce coincid cu regula data in str
    liste=[42, 12, 21, 11, 14, 41, 41, 15, 51, 62]#lista initiala
    for i in range(len(liste)):
        temp=exrp#operatia copiata pentru ca urmeaza sa fie modificata
        x=liste[i]//10#prima cifra
        y=liste[i]%10#a doua cifra
        a=str(x)#conversia primei cifre in type:string
        b=str(y)#conversia celei de a doua cifre in type:string
        temp=temp.replace('x', a).replace('y', b)#inlocuirea lui x si y cu cifrele propriuzise doar ca drept string
        if(fct(temp.split('=')[0]) == fct(temp.split('=')[1])):#daca evaluarea a ce este inainte de '=' este == cu evaluarea a ce este dupa'='
            res.append(liste[i])#adauga elementul din lista initiala in lista filtrata

    print(res)

cinci()

#Finden Sie die längste zusammenhängendeDominoTeilfolge. Eine Domino Teilfolge ist definiert als x1y1, x2y2, wo y1=x2. (z.B: 89, 95, 54)
def sase():
    liste=[10, 12, 21, 11, 14, 41, 41, 15, 51, 12]
    temp=[]
    result=[]
    for i in range(1, len(liste)):
        if (liste[i-1]%10)==(liste[i]//10):
            temp.append(liste[i-1])
        else:
            temp.append(liste[i-1])
            if len(temp)>len(result):
                result=temp
            temp=[]
    if(liste[i-1]%10)==(liste[i]//10):
        temp.append(liste[-1])
    if len(temp) > len(result):
        result=temp

    print(result)
#sase()

#Finden Sie den kleinsten gemeinsamen Vielfachenzwischen Index from und to, welche gegeben sind.
def cmmmc(a,b):
    n=a
    m=b
    while n!=m:
        if n<m:
            n+=a
        else:
            m+=b
    return n

def sapte():
    liste=[10, 12, 21, 11, 14, 41, 41, 15, 51, 12]
    fro=3
    to=6
    min=liste[fro]
    for i in range(fro+1,to):
        min=cmmmc(liste[i],min)
    print(min)

#sapte()

