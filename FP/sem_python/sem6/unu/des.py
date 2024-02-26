import turtle
from dic import update_dictionar
def deseneaza(cuv,spacing,x,y,d):
  t=turtle.Pen()
  d=update_dictionar(d)
  for litera in cuv:
    t.penup()
    t.goto(x,y)
    t.setheading(0)
    x+=spacing
    t.pendown()
    for instructiune in range(0,len(d[litera])):
      if d[litera][instructiune] == 'a':
        t.right(45)
      if d[litera][instructiune] == 'w':
        t.forward(10)
      if d[litera][instructiune] == 's':
        t.backward(10)
      if d[litera][instructiune] == 'd':
        t.left(45)
      if d[litera][instructiune] == 'f':
        t.penup()
      if d[litera][instructiune] == 'g':
        t.pendown()