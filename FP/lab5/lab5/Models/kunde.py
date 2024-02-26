from Models.identifizierbar import Identifizierbar

class Kunde(Identifizierbar):

    def __init__(self, id, name, addresse):
        super().__init__(id)
        self.name = name
        self.addresse = addresse

    def todict(self):
        return {'id': self.id,
                'name': self.name,
                'addresse': self.addresse}

    def name(self):
        return self.name

    def set_name(self, val):
        self.name = val

    def addresse(self):
        return self.addresse

    def set_address(self, val):
        self.addresse = val
