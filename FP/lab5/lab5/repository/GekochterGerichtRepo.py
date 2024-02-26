from repository.data_repo import DataRepo
from Models.gekochter_gericht import GekochterGericht

def cvt_dict_gericht(dict):
    
    gericht = GekochterGericht(-1, -1, -1, "")

    gericht.id = dict["id"]
    gericht.portions_grosse = dict["portions_grosse"]
    gericht.preis = dict["preis"]
    gericht.zeit = dict["zeit"]

    return gericht



def convert_gericht_to_dictionary(gericht):
    
    return gericht.todict()

class GekochterGerichtRepo(DataRepo):

    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, liste):
        return list(map(convert_gericht_to_dictionary, self.ret_alle()))

    def convert_from_string(self, dictionary_list_from_json) -> list:
        return list(map(cvt_dict_gericht, dictionary_list_from_json))
