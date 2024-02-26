from Models.identifizierbar import Identifizierbar


class Gericht(Identifizierbar):

    def __init__(self, id, portions_grosse, preis):
        super().__init__(id)
        self.portions_grosse = portions_grosse
        self.preis = preis

    def portions_grosse(self):
        return self.portions_grosse

    def set_portions_grosse(self, val):
        self.portions_grosse = val

    def preis(self):
        return self.preis

    def set_preis(self, value):
        self.preis = value
