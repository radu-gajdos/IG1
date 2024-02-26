from Models.gekochter_gericht import GekochterGericht
from Models.kunde import Kunde
from Models.getrank import Getrank
from Models.bestellung import Bestellung
from utils.aspect_helper.spacing import print_dict_spacing
from repository.GekochterGerichtRepo import GekochterGerichtRepo
from repository.GetrankRepo import GetrankRepo
from repository.KundeRepo import KundeRepo
from repository.BestellungRepo import BestellungRepo
from controller.controller import Controller
def HinzufügeneinesGerichts():
    controller = Controller(GekochterGerichtRepo, GetrankRepo, KundeRepo, BestellungRepo)
    kunde = Kunde(0, 'gigi', 'tecuci')
    k = controller.find_kunde_by_name('gi')

def testkunde():
    HinzufügeneinesGerichts()