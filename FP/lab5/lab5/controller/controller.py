from repository.GekochterGerichtRepo import GekochterGerichtRepo
from repository.KundeRepo import KundeRepo
from repository.GetrankRepo import GetrankRepo
from repository.BestellungRepo import BestellungRepo

class Controller:
    def __init__(self,
                 gericht_repo: GekochterGerichtRepo,
                 getrank_repo: GetrankRepo,
                 kunde_repo: KundeRepo,
                 bestellung_repo: BestellungRepo):

        self.gericht_repo = gericht_repo
        self.getrank_repo = getrank_repo
        self.kunde_repo = kunde_repo
        self.bestellung_repo = bestellung_repo

    def find_kunde_by_name(self, name):
        return self.kunde_repo.search_name(name)

    def find_kunde_by_address(self, addresse):
        return self.kunde_repo.search_addresse(addresse)
        
    def add(self, obj, typ_obj):
        if typ_obj == "gericht":
            self.gericht_repo.add(obj)
        elif typ_obj == "getrank":
            self.getrank_repo.add(obj)
        elif typ_obj == "kunde":
            self.kunde_repo.add(obj)
        elif typ_obj == "bestellung":
            self.bestellung_repo.add(obj)

    def ret_alle(self, typ_obj):
        obj_list = []

        if typ_obj == "gericht":
            obj_list = self.gericht_repo.ret_alle()
        elif typ_obj == "getrank":
            obj_list = self.getrank_repo.ret_alle()
        elif typ_obj == "kunde":
            obj_list = self.kunde_repo.ret_alle()
        elif typ_obj == "bestellung":
            obj_list = self.bestellung_repo.ret_alle()

        return obj_list

    def next_id(self, id, typ_obj):
        obj = None

        if typ_obj == "gericht":
            obj = self.gericht_repo.next_id(id)
        elif typ_obj == "getrank":
            obj = self.getrank_repo.next_id(id)
        elif typ_obj == "kunde":
            obj = self.kunde_repo.next_id(id)
        elif typ_obj == "bestellung":
            obj = self.bestellung_repo.next_id(id)

        return obj

    def delete(self, id, typ_obj):
        if typ_obj == "gericht":
            self.gericht_repo.delete(id)
        elif typ_obj == "getrank":
            self.getrank_repo.delete(id)
        elif typ_obj == "kunde":
            self.kunde_repo.delete(id)
        elif typ_obj == "bestellung":
            self.bestellung_repo.delete(id)

    def update(self, id, obj_neu, typ_obj):
        if typ_obj == "gericht":
            self.gericht_repo.update(id, obj_neu)
        elif typ_obj == "getrank":
            self.getrank_repo.update(id, obj_neu)
        elif typ_obj == "kunde":
            self.kunde_repo.update(id, obj_neu)
        elif typ_obj == "bestellung":
            self.bestellung_repo.update(id, obj_neu)

    def file_lesen(self, typ_obj):
        if typ_obj == "gericht":
            self.gericht_repo.file_lesen()
        elif typ_obj == "getrank":
            self.getrank_repo.file_lesen()
        elif typ_obj == "kunde":
            self.kunde_repo.file_lesen()
        elif typ_obj == "bestellung":
            self.bestellung_repo.file_lesen()

    def file_schreiben(self, typ_obj):
        if typ_obj == "gericht":
            self.gericht_repo.file_schreiben()
        elif typ_obj == "getrank":
            self.getrank_repo.file_schreiben()
        elif typ_obj == "kunde":
            self.kunde_repo.file_schreiben()
        elif typ_obj == "bestellung":
            self.bestellung_repo.file_schreiben()

