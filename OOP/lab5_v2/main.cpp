#include <iostream>
#include "Elektroscooter.h"
#include "ScooterRepo.h"
#include "ScooterController.h"
#include "ScooterUI.h"
//#include "RepoTest.cpp"
//#include "ControllerTest.cpp"
#include "memory"
using namespace scooterRepo;
using namespace Domain;
using namespace scooterController;
using namespace ScooterUINamespace;


int main() {
    //test();
    //testController();
    shared_ptr<ScooterRepo> repo = make_shared<ScooterRepo>();
    shared_ptr<ScooterController> controller = make_shared<ScooterController>(repo);
    shared_ptr<ScooterUI> ui = make_shared<ScooterUI>(controller);
    ui->start();
}
