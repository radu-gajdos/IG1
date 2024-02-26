class Raum:

    def __init__(self, id, raumnummer, plaetze):
        self.raumnummer= raumnummer
        self.plaetze = plaetze
        self.id = id #unique

    def __str__(self):
        return f'Raum(nummer={self.raumnummer},sp={self.plaetze})'
    
    def __eq__(self, other):
        return self.id == other.id

###

class RechnerRaum(Raum):

    def __init__(self, id, raumnummer, plaetze, os):

        validos=['unix', 'windows', 'linux', 'macos']
        Raum.__init__(self, id, raumnummer, plaetze)

        if os in validos:
            self.os=os
        else:
            raise AttributeError('OS invalid!!!')

    def __str__(self):
        return f'Raum(nummer={self.raumnummer},sp={self.plaetze},os={self.os})'
    
    def __eq__(self, other):
        return self.id == other.id

###
from dataclasses import dataclass
@dataclass
class Gebaeude:

    raume:list

    def wvPlatz(self, raumnummer):
        for raum in self.raume:
            if raum.raumnummer == raumnummer:
                return raum.plaetze

    def __str__(self):
        s=''
        for raum in self.raume:
            s+= str(f'ID:{raum.id}, Nr:{raum.raumnummer}, Plateze:{raum.plaetze}, OS:{raum.os}')
            s+='\n'
        return s


    def addRoom(self, Room):
        self.raume.append(Room)

    def filterRoom(self, plaetze):
        nou=[]
        for raum in self.raume:
            if raum.plaetze == plaetze:
                nou.append(raum)

        self.raume=nou

    def updateRoom(self, id, ):
        for raum in self.raume:
            if raum.id ==id:
                raum.raumnummer = input('Introduceti nr. nou in mortii mei: ')
                raum.plaetze = input('Introduceti plaetze nou in mortii mei: ')
                raum.os = input('Introduceti OS nou in mortii mei: ')
###

def main():
    r=RechnerRaum(1, 202, 60, 'windows')
    rdoi=RechnerRaum(2, 203, 60, 'linux')
    rtrei=RechnerRaum(3, 204, 25, 'linux')
    rpatru=RechnerRaum(4, 205, 22, 'linux')
    g = Gebaeude([r])
    g.addRoom(rdoi)
    print(g)
    g.addRoom(rtrei)
    g.addRoom(rpatru)
    print(g)
    g.filterRoom(60)
    print(g)
    g.updateRoom(2)
    print(g)
    
main()