from Models.gericht import Gericht

class GekochterGericht(Gericht):

    def __init__(self, id, portions_grosse, preis, zeit):
        super().__init__(id, portions_grosse, preis)
        self.zeit = zeit

    def todict(self):

        return {'id': self.id,
                'portions_grosse': self.portions_grosse,
                'preis': self.preis,
                'zeit': self.zeit}

    def zeit(self):
        return self.zeit

    def set_zeit(self, val):
        self.zeit = val
