import turtle
def adauga_caracter():
  fw=open("C:\\Users\\Radu\\Desktop\\python\\sapt6\\unu\\dictionar.txt", 'a')
  window=turtle.Screen()
  t=turtle.Turtle()
  carac=str(input('Introduceti numele caracterului nou:'))
  temp=str(carac)
  temp+=':'
  fw.write(temp)
  x=input('Apasa instructiunea, iar apoi Enter: ')
  while x!='':
    if x == 'a':
      t.right(45)
      temp=str(x)
      temp+=','
      fw.write(temp) 
    if x == 'w':
      t.forward(10)
      temp=str(x)
      temp+=','
      fw.write(temp) 
    if x == 's':
      t.backward(10)
      temp=str(x)
      temp+=','
      fw.write(temp) 
    if x == 'd':
      t.left(45)
      temp=str(x)
      temp+=','
      fw.write(temp) 
    if x == 'f':
      t.penup()
      temp=str(x)
      temp+=','
      fw.write(temp) 
    if x == 'g':
      t.pendown()
      temp=str(x)
      temp+=','
      fw.write(temp) 
    x=input('Apasa instructiunea, iar apoi Enter: ')
  fw.write('\n') 
  t.clear()