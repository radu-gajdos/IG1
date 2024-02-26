#ex1\
def unu():
    import random
    class DIE:
        def __init__(self,sides=6):
            self.sides=sides
        def roll(self):
            return random.randint(1,self.sides)
        
    def main():
        d=DIE(10)
        r=d.roll()
        while r!=6:
            print(r)
            r=d.roll()
        print(r)

    main()

def doi():
    class Bruch():
        def __init__(self,n,m):
            self.n=n
            self.m=m
        
        def erw(self,k):
            self.n*=k
            self.m*=k
        
        def kurz(self,k):
            self.n/=k
            self.m/=k

        def erw_new(self,k):
            return Bruch(self.n *k,self.m *k)

        def print(self):
            print(str(self.n) + '/' + str(self.m))
        
        def print_fancy(self):
            print(f'{self.n}/{self.m}')
        
        def print_old(self):
            print('%d/%d'%(self.n,self.m))

    def main():
        b=Bruch(1,2)
        b.erw(10)
        b.print()
        g=b.erw_new(10)
        g.print_fancy()
        b.print_old()

    main()

def trei():
    class Auto:
        def __init__(self,b,f,m):
            self.b=b
            self.f=f
            self.m=m
        
    class Stats:
        def __init__(self):
            self.autos=[]
        
        def add_auto(self,auto):
            self.autos.append(auto)

        def caf(self,farbe):
            c=0
            for auto in self.autos:
                if auto.f==farbe:
                    c+=1
            return c

        def abm(self,marke):
            b=0
            ct=0
            for auto in self.autos:
                if auto.m == marke:
                    b+=auto.b
                    ct+=1
            return b//ct

    def main():
        aunu=Auto(2003,'rot','opel')
        adoi=Auto(2004,'blau','jeep')
        atrei=Auto(2009,'rot','mazda')
        apatru=Auto(2009,'braun','opel')

        s=Stats()
        s.add_auto(aunu)
        s.add_auto(adoi)
        s.add_auto(atrei)
        s.add_auto(apatru)

        print(s.caf('rot'))
        print(s.abm('opel'))

    main()

def cinci():
    import math
    class Dreieck:
        def __init__(self,sunu,sdoi,strei,wunu,wdoi,wtrei):
            self.sunu=sunu
            self.sdoi=sdoi
            self.strei=strei
            self.wunu=wunu
            self.wdoi=wdoi
            self.wtrei=wtrei
        
        def flache(self):
            s=self.sunu+self.sdoi+self.strei
            s/=2
            return math.sqrt(s*(s-self.sunu)*(s-self.sdoi)*(s-self.strei))

    class Kreis:
        def __init__(self,c,rad):
            self.c=c
            self.rad=rad
        
        def flache(self):
            return (math.pi)*math.pow(self.rad,2)
    
    def main():
        tri=Dreieck(1,2,2,30,60,90)
        print(tri.flache())
        cer=Kreis(2)
        print(cer.flache())
        
    main()

cinci()
    
    

