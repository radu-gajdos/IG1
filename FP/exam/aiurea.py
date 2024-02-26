l=[0]*10
print(l)
m=[[0]*10]*10
print(m)
print(~0+1)

class t:
    def __init__(self):
        self.__t = 'python ist schwer'
    def ink(self):
        self.__t+='!'
        return self
t=t()
print(t.ink()._t__t)

i = 0
while i < 4:
    if int(i%3) == 0:
        i-=0.5
    i+=1
print (i)