import random
import os

from des import deseneaza

def rps():
    s=['r','p','s']
    rr=0
    ee=0
    while ee+rr<3:
        r=random.choice(s)
        e=input('Alege intre(r,p,s): ')
        print('Tu ai ales: ',e)
        deseneaza(e)
        if e not in s:
            print('Alegere invalida! Punct pentru robot')
        if r=='r' and e=='p':
            ee+=1
        elif r=='r' and e=='r':
            print('Egalitate')
        elif r=='r':
            rr+=1
        if r=='p' and e=='s':
            ee+=1
        elif r=='p' and e=='p':
            print('Egalitate')
        elif r=='p':
            rr+=1
        if r=='s' and e=='r':
            ee+=1
        elif r=='s' and e=='s':
            print('Egalitate')
        elif r=='s':
            rr+=1
        print('Robotul a ales: ',r)
        deseneaza(r)
        print('Scorul este: Tu - ',ee,' : Robot - ', rr)
    
    os.system('cls')

    if ee>rr:
        print('Ai castigat!!!')
        print('Scorul final este: Tu - ',ee,' : Robot - ', rr)
    else:
        print('Ai pierdut :(((')
        print('Scorul final este: Tu - ',ee,' : Robot - ', rr)

    

rps()
    
        
