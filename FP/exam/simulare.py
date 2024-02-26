#I-A
#def f(x=0, y):
#    print(x, y)
#f(20, 22)
#FALSCH - default argument trebuie sa fie dupa non-default declared 


#I-B
# l = (1,2)
# v = [2,3]
# l[0] = 11
#FALSH tupla nu suporta asigment

#I-C
# x = y = 0
# print(1+1==2)
#TRUE

#I-D
#const x = 0
#FALSH sintaxa pur si simplu

#I-E
# class A: pass
# Class A:B
#     def f(self):
#         print(1)
#FALSH sintaxa pur si simplu

#II-A
# Um zwei Algorithmen zu vergleichen, kann man ihre Leistung und die benötigte Zeit messen.
# Die Laufzeit eines Algorithmus wird anhand der Anzahl der notwendigen Operationen definiert.
# Die asymptotische Komplexität beschreibt dagegen die maximale Leistung des Algorithmus in Bezug
# auf die Größe des Eingabedatensatzes.

# Ein Beispiel: Wenn wir eine Liste mit Zahlen sortieren möchten, können wir dafür zwei Algorithmen verwenden:
# den Bubble-Sort-Algorithmus und den Quick-Sort-Algorithmus. Wenn wir die benötigte Zeit messen, werden wir feststellen, dass
# der Quick-Sort-Algorithmus schneller ist. Die asymptotische Komplexität des Quick-Sort-Algorithmus ist jedoch höher 
# als die des Bubble-Sort-Algorithmus. Das bedeutet, dass bei sehr großen Datensätzen der Quick-Sort-Algorithmus langsamer 
# sein kann als der Bubble-Sort-Algorithmus.

# Daher ist es wichtig, bei der Auswahl eines Algorithmus sowohl die tatsächliche Leistung als auch die asymptotische 
# Komplexität zu berücksichtigen.

#II-B
#Definition:
# List comprehensions in Python sind eine einfache und kompakte Methode, um eine Liste anhand einer bestimmten 
# Bedingung zu erzeugen. Sie nutzen eine einzige Zeile Code, um eine Liste von Werten zu erzeugen, die eine 
# bestimmte Bedingung erfüllen.

#Beispiele
#Um eine Liste aller Zahlen von 1 bis 10 zu erzeugen:
list = [x for x in range(1, 11)]
print(list)

#Um eine Liste der Quadratzahlen von 1 bis 10 zu erzeugen:
liste = [x**2 for x in range(1, 11)]
print(liste)

#III-A

def rec(text, start=0):
    for i, char in enumerate(text[start:]):
        if char == '(':
            start = start + i + 1
            return rec(text, start)
        elif char == ')':
            end = start + i
            return '(' + text[start:end] + ')'
    return ""

s="22a3(abcd)Xy2Z"
print(rec(s))

#III-B

from functools import reduce
def matrix_sum(m):
    result=0
    for i in range(len(m)):
        result += reduce(lambda x, y: x + y, m[i])
    return result

m=[[1,2,3],
    [3,2,1],
    [2,1,3]]
print(matrix_sum(m))

#IV-
class Square():
    def __init__(self, x, y, side=0):
        self.x=x
        self.y=y
        self.side=side

#IV-B
class Rectangle():
    def __init__(self, x, y, length=0, width=0):
        self.x=x
        self.y=y
        self.length=length
        self.width=width

#IV-C

def contains(r:Rectangle, l:list):
    for i, s in enumerate(l):
        if s.side > r.length and s.side > r.width:
            return False

    return True

r=Rectangle(0,0,12,10)
sunu=Square(0,0,12)
sdoi=Square(0,0,11)
strei=Square(0,0,9)
l=[sunu,sdoi,strei]

print(contains(r,l))