#include <iostream>
#include "Elektroscooter.h"
#include "ScooterRepo.h"
#include "ScooterController.h"
#include "memory"
using namespace scooterRepo;
using namespace Domain;
using namespace scooterController;


int main() {
    shared_ptr<ScooterRepo> repo = make_shared<ScooterRepo>();
    shared_ptr<ScooterController> controller = make_shared<ScooterController>(repo);

}
