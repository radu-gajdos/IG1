class Box:
    def __init__(self):
        self.figs=[]

    def add_fig(self,f):
        self.figs.append(f)

    def compute_area(self):
        for fig in self.figs: 
            print(fig.area())#area() ii functia de Flache de la fiecare gifura geometrica (Clase definite in sapt7/seminar)

class Konto:
    def __init__(self,nr,betrag=0):
        self.nr=nr
        self.admin=None
        self.betrag=betrag

    def set_admin(self,admin):
        self.admin=admin

    def sub(self,ammount):
        self.betrag-=ammount

    def add(self,ammount):
        self.betrag+=ammount

class Zahler:
    def __init__(self,i,limit):
        self.i=i
        self.limit=limit
    def inc(self,ammount):
        if self.i<self.limit:
            self.i+=1
        else:
            self.i=0

def main():
    cunu=Zahler(0,59)
    for i in range(200):
        cunu.inc(1)
        print(cunu.i)

main()
