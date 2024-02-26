class Bag:
    def __init__(self,content):
        self.content=[]

    def add(self,elem):
        self.content.append(elem)

    def remove(self,elem):
        initial = self.content
        self.content.remove(elem)
        #remove-ul arunca eroere deja ifurile nu sunt necesare
        if len(self.content) < len(initial):
            return True
        if len(self.content) == len(initial):
            return False
        
    def search(self,elem):
        if elem in self.content:
            return True
        else:
            return False
        
    def size(self):
        return len(self.content)
    
    def nrOccurrence(self,elem):
        return self.content.count(elem)
    
    def destroy(self):
        del(self)
    
    from iterator import Iterator
    def iterator(self,I:Iterator):
        return self.I.i
        

    
    


    
def main():
    b=Bag([])
    b.add(1)
    assert (b.content == [1,2], f'doar 1 a fost adaugat asadar lista nu este [1,2]')

main()

