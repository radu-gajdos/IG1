
import turtle

def meniu():

  n=0

  while(n!=9):

    print('1. Deseneaza cuvantul')
    print('2. Adauga caracter')
    print('9. Exit')
    n=int(input('Alege optiunea: '))

    if n==1:

      cuv=str(input('Alege cuvantul: '))
      spacing=int(input('Numarul de pixeli intre caractere (spacing): '))
      x=int(input('Coordinata x a inceputului cuvantului: '))
      y=int(input('Coordinata y a inceputului cuvantului: '))

      d={}

      from des import deseneaza
      deseneaza(cuv,spacing,x,y,d)

    if n==2:

      from add import adauga_caracter
      adauga_caracter()

    if n==9:

      import os
      os.system('cls' if os.name == 'nt' else 'clear')

meniu()

