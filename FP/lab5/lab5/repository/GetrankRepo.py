from repository.data_repo import DataRepo
from Models.getrank import Getrank


def cvt_dict_getrank(dict):
    # takes a dictionary and converts it into a getrank object
    getrank = Getrank(-1, -1, -1, -1)

    getrank.id = dict["id"]
    getrank.portions_grosse = dict["portions_grosse"]
    getrank.preis = dict["preis"]
    getrank.alc = dict["alc"]

    return getrank


def cvt_getrank_dict(getrank):
    return getrank.todict()

class GetrankRepo(DataRepo):
    def __init__(self, file):
        super().__init__(file)

    def convert_to_string(self, object_list):
        return list(map(cvt_getrank_dict, self.ret_alle()))

    def convert_from_string(self, dictionary_list_from_json):
        return list(map(cvt_dict_getrank, dictionary_list_from_json))
