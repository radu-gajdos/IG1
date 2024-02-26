import math
class Point:

    def __init__(self, x, y):
        self.x=x
        self.y=y

    def __sub__ (self,other):
        return math.sqrt((self.x-other.x)**2 + (self.y-other.y)**2)

    def __str__(self):
        return f'Point(x={self.x}, y={self.y})'

class Circle:
    def __init__(self, x, y, r):
        self.c=Point(x,y)
        self.r=r

    def move(self,dx,dy):
        self.c.x+=dx
        self.c.y+=dy

    def area(self):
        return math.pi * (self.r**2)

    def __lt__(self,other):
        return self.area() < other.area()
    
    def __str__(self):
        return f'Centre(x={self.c.x}, y={self.c.y}), Radius={self.r}'

def sort_c(lc):
    #lc.sort(key=lambda c:c.area())
    list(map(lambda c :c.area(), lc)).sort()
def main():
    punu=Point(1,2)
    pdoi=Point(2,3)
    d=punu-pdoi
    print(d)
    print(punu)
    lc=[Circle(1,2,10),Circle(1,5,7),Circle(1,1,3)]
    sort_c(lc)
    for c in lc:
        print(c)

main()