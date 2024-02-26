from modelle.gerichte import add_gerichte
from modelle.gerichte import del_gerichte
from modelle.gerichte import update_dict_gerichte
def gerichte():
    n=0
    while n != 9:
        print('1. Hinzufuegen einen Gericht')
        print('2. Einen Gericht loeschen')
        if n==1:
            add_gerichte()
        elif n==2:
            d={}
            d=update_dict_gerichte(d)
            print(d)
            x=input('ID des Gerichtes')
            del_gerichte(x)
            d={}
            d=update_dict_gerichte(d)
            print(d)
            print('1. Hinzufuegen einen Gericht')
            print('2. Einen Gericht loeschen')
        n=int(input('Option waehlen: '))

def main():
    class Gerichte:
        def __init__(self, liste):
            self.liste=liste
        def view_gerichte(self):
            print(self.liste)

    class Gericht(Gerichte):
        def __init__(self, id, name, gr, preis):
            self.name=Gerichte.liste[id][0]
        def view_gericht(self):
            print(self.name)
    d={}
    d=update_dict_gerichte(d)
    g=Gerichte(d)
    g.view_gerichte()
main()