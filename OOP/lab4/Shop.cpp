#include "UI.h"
#include "Fruit.h"
#include <memory>
#include "Tests.cpp"

using namespace UI;

int main()
{
    testAdd();
    testUpdate();
    testSearchByName();

    shared_ptr<Repository::FruitRepository> repo = make_shared<Repository::FruitRepository>();
    shared_ptr<Controller::FruitController> controller = make_shared<Controller::FruitController>(repo);

    
    
    repo->AddFruit(Domain::Fruit("Apfel", "CA", "11/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "PO", "12/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "RO", "11/12/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Banana", "CB", "14/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Ananas", "ES", "06/06/12", 120, 12));
    repo->AddFruit(Domain::Fruit("Kiwi", "ES", "05/05/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "CA", "11/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "CA", "11/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "CA", "11/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "CA", "11/11/12", 123, 123));
    repo->AddFruit(Domain::Fruit("Apfel", "CA", "11/12/13", 123, 123));
    UI::Console ui(controller);
    ui.Run();

    return 0;
}