from Models.gericht import Gericht

class Getrank(Gericht):

    def __init__(self, id, portions_grosse, preis, alc):
        super().__init__(id, portions_grosse, preis)
        self.alc = alc

    def todict(self):
        return {'id': self.id,
                'portions_grosse': self.portions_grosse,
                'preis': self.preis,
                'alc': self.alc}
    
    def alc(self):
        return self.alc

    def set_alc(self, val):
        self.alc = val
