import turtle

def unu():
    t= turtle.Pen()
    #ersten rechteck
    t.forward(200)
    t.left(90)
    t.forward(100)
    t.left(90)
    t.forward()
    t.penup()
    t.left(90)
    t.forward(50)
    t.left(90)
    t.forward(50)
    t.left(90)
    t.forward(25)
    t.pendown()
    #end00)
    t.left(90)
    t.forward(100)
    #end

    #geht in ersten rechteck ohne zu mahlen
    
    
    #zweiten rechteck
    t.forward(50)
    t.left(90)
    t.forward(25)
    t.left(90)
    t.forward(50)
    t.left(90)
    t.forward(25)
    #end


def doi():
    
    t=turtle.Pen()
    t.left(45)
    t.forward(100)
    for i in range(0,45):
        t.left(4)
        t.forward(4)
    t.right(90)
    for i in range(0,45):
        t.left(4)
        t.forward(4)
    t.left(7)
    t.forward(120)




def trei(x,y):
    
    t=turtle.Pen()
    p=turtle.Pen()

    t.penup()
    t.goto(x,y)
    t.pendown()

    p.penup()
    p.goto(x-300,y)
    p.pendown()

    t.forward(250)
    p.forward(250)
    t.left(90)
    p.left(90)
    t.forward(125)
    p.forward(125)
    t.left(90)
    p.left(90)
    t.forward(250)
    p.forward(250)
    t.left(90)
    p.left(90)
    t.forward(125)
    p.forward(125)

    t.penup()
    p.penup()
    t.left(90)
    p.left(90)
    t.forward(100)
    p.forward(100)
    t.left(90)
    p.left(90)
    t.pendown()
    p.pendown()

    t.forward(74)
    p.forward(74)
    t.right(90)
    p.right(90)
    t.forward(37)
    p.forward(37)
    t.right(90)
    p.right(90)
    t.forward(74)
    p.forward(74)

    t.penup()
    p.penup()
    t.right(180)
    p.right(180)
    t.forward(74)
    p.forward(74)
    t.right(90)
    p.right(90)
    t.forward(20)
    p.forward(20)
    t.pendown()
    p.pendown()

    t.forward(40)
    p.forward(40)
    t.right(90)
    p.right(90)
    t.forward(40)
    p.forward(40)
    t.right(90)
    p.right(90)
    t.forward(40)
    p.forward(40)
    t.right(90)
    p.right(90)
    t.forward(40)
    p.forward(40)

    t.penup()
    p.penup()
    t.left(90)
    p.left(90)
    t.forward(77)
    p.forward(77)
    t.pendown()
    p.pendown()

    t.forward(40)
    p.forward(40)
    t.left(90)
    p.left(90)
    t.forward(40)
    p.forward(40)
    t.left(90)
    p.left(90)
    t.forward(40)
    p.forward(40)
    t.left(90)
    p.left(90)
    t.forward(40)
    p.forward(40)

    t.penup()
    p.penup()
    t.left(90)
    p.left(90)
    t.forward(80)
    p.forward(80)
    t.right(90)
    p.right(90)
    t.forward(54)
    p.forward(54)
    t.pendown()
    p.pendown()

    t.right(45)
    p.right(45)
    t.forward(175)
    p.forward(175)
    t.right(90)
    p.right(90)
    t.forward(175)
    p.forward(175)



print('Wählen Sie eine Zeichnung aus:')
print('1.Rechteck')
print('2.Herz')
print('3.Häuser')
n=int(input('n='))
if n==1:
    unu()
elif n==2:
    doi()
elif n==3:
    trei(0,0)
else:
    print('Wahle eine valide zahl')



