

def is_prim(n):
    if(n==0 or n==1):
        return False
    if n%2==0:
        return False
    for i in range(2, n//2):
        if(n % i == 0):
            return False
    return True


def unu_a():
    n= input("N eingeben:")
    n= int(n)
    for i in range(n):
        if(is_prim(i)==True):
            print(i)

#VARIANTA CU INDICI (C++)
def unu_b_C():
    liste = [1,2,3,0,4,5,6,11,29,-1,10]
    ct=0
    pozmax=0
    pozmin=0
    lmax=0
    min=0
    max=0
    for i in range(len(liste)-1):
        if(liste[i]<liste[i+1]):
            ct=ct+1
            pozmax=pozmax+1
        else:
            if(ct>lmax):
                lmax=ct
                min=pozmin
                max=pozmax
            ct=0
            pozmin=i+1
            pozmax=i+1

    for i in range(len(liste)):
        if(i>=min and i<=max):
            print(liste[i])

#unu_b_C()


#VARIANTA CU APPEND(PYTHON)
def unu_b_P():
    liste = [1,2,3,0,4,5,6,11,29,-1,10, 11,12,13,14,15,20,100]
    result =[]
    temp =[]
    for i in range(1, len(liste)-1):
        if liste[i+1] > liste[i]:
            temp.append(liste[i-1])
        else:
            temp.append(liste[i-1])
            if len(temp)>len(result):
                result=temp
            temp=[]
    if liste[-1]>liste[-2]:
        result=temp
    if len(temp)>len(result):
                result=temp
    print(result)

unu_b_P()


    
    
    
