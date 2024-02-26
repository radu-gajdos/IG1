class DataRepo():

    def __init__(self, data):
        self.data=data

    def convert_to_string(self):
        pass

    def convert_from_string(self):
        pass

    def save(self,file):
        file = open(file,'a')
        file.write(self.convert_to_string())
        file.close()


class Identifizierbar:

    def __init__(self, id):
        self.id = id

    def display(self):
      return self.id 

class Gericht(Identifizierbar):

    def __init__(self, id, gram, preis):
        super().__init__(id)
        self.gram = gram
        self.preis = preis


class GekochterGericht(Gericht):

    def __init__(self, id, gram, preis, zeit):
        super().__init__(id, gram, preis)
        self.zeit=zeit

class GekochterGerichtRepo(DataRepo):

    def __init__(self, data):
        super().__init__(data)

    def convert_to_string(self):
        s=[]
        delimiter = ' '
        s = delimiter.join(map(str, s))
        return s

    def convert_from_string(self,s):
        s=s.split('\n')
        return s[1]

# s=open('C:\\Users\\Radu\\Desktop\\python\\sapt9\\gerichte.txt','r')
# s=s.readline()
# obj=GerichtRepo([])
# print(obj.convert_from_string(s))



list=[GekochterGericht(1, 500, 12, 10),GekochterGericht(1, 500, 12, 10)]
obj=GekochterGerichtRepo((list))
f=open('C:\\Users\\Radu\\Desktop\\python\\sapt9\\gerichte.txt', 'r').read()
print(obj.convert_from_string(f))
obj.save('C:\\Users\\Radu\\Desktop\\python\\sapt9\\gerichte.txt')


# liste=['Mici','500', '12']
# obj=DataRepo(liste)
# obj.save('C:\\Users\\Radu\\Desktop\\python\\sapt9\\gerichte.json')