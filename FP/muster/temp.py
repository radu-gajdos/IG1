import functools

def ub1(subject):
    file=open('C:\\Users\\Radu\\Desktop\\python\\muster\\text.txt', 'r')
    f=file.readlines()
    result=filter(lambda x:subject in x,f)
    result=list(result)
    file=open('ex_1','w')
    file.writelines(result)
    a=map(lambda x:int(x.split(',')[3]),result)
    suma=functools.reduce(lambda x,y:x+y,a)
    print(suma)
    file.close()
    return suma
    
#print(ub1('Advanced programming'))

import unittest

def test1():
     assert 49 == ub1('Advanced programming')
test1()

def test2():
     assert 39 == ub1('Advanced programming')
test2()