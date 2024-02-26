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