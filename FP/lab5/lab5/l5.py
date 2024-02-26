from controller.controller import Controller
from repository.GekochterGerichtRepo import GekochterGerichtRepo
from repository.KundeRepo import KundeRepo
from repository.GetrankRepo import GetrankRepo
from repository.BestellungRepo import BestellungRepo
from ui.console import Console
from tests.kundetest import testkunde

controller = Controller(

    GekochterGerichtRepo("gerichte.json"),
    GetrankRepo("getranks.json"),
    KundeRepo("kunden.json"),
    BestellungRepo("bestellungen.json")
)

console = Console(controller)
testkunde()
console.console_run()