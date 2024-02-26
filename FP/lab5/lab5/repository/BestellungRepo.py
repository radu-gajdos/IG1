from repository.data_repo import DataRepo
from Models.bestellung import Bestellung
from repository.GekochterGerichtRepo import cvt_dict_gericht
from repository.GetrankRepo import cvt_dict_getrank

def cvt_dict_bestellung(dictionary_from_json):
    
    bestellung = Bestellung(0, 0, [], [])

    bestellung.id = dictionary_from_json["id"]
    bestellung.kunde_id = dictionary_from_json["kunde_id"]
    bestellung.gerichte = list(map(cvt_dict_gericht, dictionary_from_json["gerichte"]))
    bestellung.getranks = list(map(cvt_dict_getrank, dictionary_from_json["getranks"]))
    bestellung.gesamt_kost = dictionary_from_json["gesamt_kost"]

    return bestellung

def cvt_bestellung_dict(bestellung):
    return bestellung.todict()

class BestellungRepo(DataRepo):
    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, object_list) -> list:
        return list(map(cvt_bestellung_dict, self.ret_alle()))

    def convert_from_string(self, dictionary_list_from_json) -> list:
        return list(map(cvt_dict_bestellung, dictionary_list_from_json))

