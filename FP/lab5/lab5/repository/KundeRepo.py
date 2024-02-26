from repository.data_repo import DataRepo
from Models.kunde import Kunde


def convert_dict_kunde(dict):
    
    kunde = Kunde(0, "", "")
    kunde.id = dict["id"]
    kunde.name = dict["name"]
    kunde.addresse = dict["addresse"]

    return kunde

def convert_kunde_to_dictionary(kunde):
    return kunde.todict()


class KundeRepo(DataRepo):

    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, liste):
        return list(map(convert_kunde_to_dictionary, self.ret_alle()))

    def convert_from_string(self, dictionary_list_from_json) -> list:
        return list(map(convert_dict_kunde, dictionary_list_from_json))

    def search_name(self, name):
        return list(filter(lambda kunde: name.lower() in kunde.name.lower(), self.ret_alle()))

    def search_addresse(self, addresse):
        return list(filter(lambda kunde: addresse.lower() in kunde.addresse.lower(), self.ret_alle()))