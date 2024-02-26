import math
from dataclasses import dataclass
@dataclass
class Point:
    x:float
    y:float

@dataclass(order=True)
class Circle:
    c:Point
    r:float
    def move(self,dx,dy):
        self.c.x+=dx
        self.c.y+=dy
    def area(self):
        return math.pi*(self.r**2)

def main():
    punu=Point(1,2)
    pdoi=Point(2,3)
    print(punu)
    lc=[Circle(Point(1,2),10),Circle(Point(1,5),7),Circle(Point(1,1),3)]
    for c in lc:
        print(c)

main()