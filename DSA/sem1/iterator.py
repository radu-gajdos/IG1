from bag import Bag

class Iterator:
    def __init__(self,b:Bag):
        self.i=0
        self.b=b

    def valid(self):
        if self.b != []:
            return True
        else:
            return False
        
    def first(self):
        if self.b.content[0]!=None:
            self.i=1
        else:
            return None
        
    def next(self):
        assert self.b.content[self.i+1]!=None
        self.i+=1

    def getCurrent(self,elem):
        assert self.b.content[self.i]!=None
        return elem