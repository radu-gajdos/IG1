from operator import add
from functools import reduce

from Models.identifizierbar import Identifizierbar

class Bestellung(Identifizierbar):

    def __init__(self, id, kunde_id, gerichte, getranks):
        super().__init__(id)
        self.kunde_id = kunde_id
        self.gerichte = gerichte
        self.getranks = getranks
        self.gesamt_kost = self.calc_kosten()

    def todict(self):
        return {'id': self.id,
                'kunde_id': self.kunde_id,
                'gerichte': [gericht.todict() for gericht in self.gerichte],
                'getranks': [getrank.todict() for getrank in self.getranks],
                'gesamt_kost': self.gesamt_kost}

    def kunde_id(self):
        return self.kunde_id

    def set_kunde_id(self, val):
        self.kunde_id = val

    def gerichte(self):
        return self.gerichte

    def set_gerichte(self, val):
        self.gerichte = val

    def getranks(self):
        return self.getranks

    def set_getranke(self, val):
        self.getranks = val

    def total_cost(self):
        return self.total_cost

    def set_total_cost(self, val):
        self.total_cost = val

    #Functie luata de la cnv ca idk cum se foloseste reduce()

    def calc_kosten(self):
        gerichte_preisen = [gericht.preis for gericht in self.gerichte]

        getranke_preisen = [getrank.preis for getrank in self.getranks]

        if gerichte_preisen or getranke_preisen:
            return reduce(add, gerichte_preisen + getranke_preisen)
        else:
            return 0

