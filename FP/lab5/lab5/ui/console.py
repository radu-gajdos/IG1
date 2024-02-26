from controller.controller import Controller
from Models.gekochter_gericht import GekochterGericht
from Models.kunde import Kunde
from Models.getrank import Getrank
from Models.bestellung import Bestellung
from utils.aspect_helper.spacing import print_dict_spacing

class Console:
    def __init__(self, controller: Controller):
        self.controller = controller

    def select_optiune(self):
        selectat = None

        print("1 - gekochter gericht")
        print("2 - getrank")
        print("3 - kunde")
        print("4 - bestellung")

        selector = input("->")

        if selector == "1":
            selectat = "gericht"
        elif selector == "2":
            selectat = "getrank"
        elif selector == "3":
            selectat = "kunde"
        elif selector == "4":
            selectat = "bestellung"

        return selectat

    def af_lista(self, typ_obj, obj_list):
        print("\n".join(map(lambda bestellunged_item: f"   {typ_obj}: {bestellunged_item.todict()}", obj_list))+"\n")

    def create_obj(self, typ_obj):
        
        obj_neu = None

        if typ_obj == "gericht":

            gericht = GekochterGericht(0, 0, 0, 0)

            gericht.id = int(input("id: "))
            gericht.portions_grosse = int(input("portions grosse: "))
            gericht.preis = int(input("preis: "))
            gericht.zeit = int(input("zeit: "))

            obj_neu = gericht

        elif typ_obj == "getrank":
            getrank = Getrank(0, 0, 0, 0)

            getrank.id = int(input("id: "))
            getrank.portions_grosse = int(input("portions grosse: "))
            getrank.preis = int(input("preis: "))
            getrank.alc = int(input("alc: "))

            obj_neu = getrank

        elif typ_obj == "kunde":
            kunde = Kunde(-1, "", "")

            kunde.id = int(input("id: "))
            kunde.name = input("name: ")
            kunde.addresse = input("addresse: ")

            obj_neu = kunde

        elif typ_obj == "bestellung":

            bestellung = Bestellung(0, 0, [], [])

            bestellung.id = int(input("ID: "))
            bestellung.kunde_id = int(input("kunde ID: "))

            gerichte = []

            while True:
                gerichtes_list = self.controller.ret_alle("gericht")

                if len(gerichtes_list) < 1:
                                    break
                

                self.af_lista("gericht", gerichtes_list)

                id = input("Select ID des getranks: ")
                print("\n --- Druck ` zu stoppen ---")

                if id == '`':
                    break
                else:
                    gerichte.append(self.controller.next_id(int(id), "gericht"))

            bestellung.gerichte = gerichte

            getranks = []

            while True:
                getranks_list = self.controller.ret_alle("getrank")

                self.af_lista("getrank", getranks_list)

                id = input("Select ID des getranks: ")
                print("\n --- Druck ` zu stoppen ---")

                if id == '`':
                    break
                else:
                    getranks.append(self.controller.next_id(int(id), "getrank"))

            bestellung.getranks = getranks
            bestellung.gesamt_kost=bestellung.calc_kosten()
            obj_neu = bestellung

        return obj_neu



    def console_print(self):

        print("Menu:")
        print(f"gerichte: {[ print_dict_spacing(gericht.todict()) for gericht in self.controller.ret_alle('gericht')]} \n\n")
        print(f"getranks: {[ print_dict_spacing(getrank.todict()) for getrank in self.controller.ret_alle('getrank')]} \n\n")
        print(f"kunden: {[ print_dict_spacing(kunde.todict()) for kunde in self.controller.ret_alle('kunde')]} \n\n")
        print(f"bestellungen: {[print_dict_spacing(bestellungen.todict()) for bestellungen in self.controller.ret_alle('bestellung')]} \n\n")

        print("\n---Console---")
        print("1 --- Hinzufügen eines item")
        print("2 --- Suchen eines nach Typ")
        print("3 --- Update eines item durch ID")
        print("4 --- Delete eines item durch ID")
        print("5 --- Suche Kunde nach Name")
        print("6 --- Suche Kunde nach Addresse")
        print("7 --- Update data")
        print("8 --- Save data")
        print("9 --- Menu zeigen")
        print("Stop --- `")

    def console_run(self):
        self.controller.file_lesen("gericht")
        self.controller.file_lesen("getrank")
        self.controller.file_lesen("kunde")
        self.controller.file_lesen("bestellung")

        self.console_print()

        selector = input("\nmain menu selector >>> ")

        while selector != "`":

            if selector == "1":
                typ_obj = self.select_optiune()
                obj_neu = self.create_obj(typ_obj)
                self.controller.add(obj_neu, typ_obj)

            elif selector == "2":
                typ_obj = self.select_optiune()
                self.af_lista(typ_obj, self.controller.ret_alle(typ_obj))

            elif selector == "3":
                typ_obj = self.select_optiune()
                self.af_lista(typ_obj, self.controller.ret_alle(typ_obj))
                id = int(input("ID "))
                obj_neu = self.create_obj(typ_obj)
                self.controller.update(id, obj_neu, typ_obj)

            elif selector == "4": 
                typ_obj = self.select_optiune()
                self.af_lista(typ_obj, self.controller.ret_alle(typ_obj))
                id = int(input("ID: "))
                self.controller.delete(id, typ_obj)

            elif selector == "5":
                name = input("Name: ")
                self.af_lista("kunde", self.controller.find_kunde_by_name(name))

            elif selector == "6": 
                addresse = input("addresse: ")
                self.af_lista("kunde", self.controller.find_kunde_by_address(addresse))

            elif selector == "9":
                self.console_print()
                
            elif selector == "7":
                typ_obj = self.select_optiune()
                self.controller.file_lesen(typ_obj)
                print("Item update complete")

            elif selector == "8":
                typ_obj = self.select_optiune()
                self.controller.file_schreiben(typ_obj)
                print("item save complete")

            selector = input("\nSelect:")

