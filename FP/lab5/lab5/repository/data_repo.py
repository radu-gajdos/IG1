import json

class DataRepo:
    def __init__(self, file):
        self.data = [] 
        self.file = file

    def add(self, gekochter_gericht):
        self.data.append(gekochter_gericht)

    def ret_alle(self):
        return self.data

    def next_id(self, id):
        return next(filter(lambda obj: obj.id == id, self.data), None)

    def delete(self, id):
        self.data = list(filter(lambda obj: obj.id != id, self.data))

    def update(self, id, new_obj):
        self.data = [new_obj if obj.id == id else obj for obj in self.data]

    def file_lesen(self):
        with open(self.file) as inputfile:
            dictionary_list_from_json = json.load(inputfile)
            self.data = self.convert_from_string(dictionary_list_from_json)

    def file_schreiben(self):
        with open(self.file, 'w') as output:
            json.dump(self.convert_to_string(self.ret_alle()), output, indent=4)

    def convert_to_string(self, object_list):
        pass

    def convert_from_string(self, dictionary_list_from_json):
        pass
