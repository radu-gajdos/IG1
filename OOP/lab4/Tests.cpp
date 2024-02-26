#include "FruitRepository.h"
#include <memory>
#include <cassert>
#include <iostream>


void testAdd(){
    shared_ptr<Repository::FruitRepository> repo = make_shared<Repository::FruitRepository>();
    Domain::Fruit fruit("Apfel", "USA", "01-06-23", 120, 10);
    repo->AddFruit(fruit);
    assert(repo->GetAllFruitsSortedByName().size() == 1);
    assert(repo->GetAllFruitsSortedByName()[0].GetName() == "Apple");
    cout<<"Add Teste fertig!\n";
}

void testUpdate(){
    shared_ptr<Repository::FruitRepository> repo = make_shared<Repository::FruitRepository>();
    Domain::Fruit fruit("Apfel", "USA", "01-06-23", 120, 10);
    repo->AddFruit(fruit);
    repo->UpdateFruitQuantity("Apfel", "USA", 20);
    assert(repo->GetAllFruitsSortedByName()[0].GetQuantity() == 20);
    cout<<"Update Teste fertig!\n";

}

void testSearchByName(){
    shared_ptr<Repository::FruitRepository> repo = make_shared<Repository::FruitRepository>();
    Domain::Fruit fruit1("Apfel", "USA", "01-06-23", 120, 10);
    Domain::Fruit fruit2("Orange", "ES", "01-06-23", 100,  10);
    Domain::Fruit fruit3("Banana", "BR", "01-06-23",90, 10);
    repo->AddFruit(fruit1);
    repo->AddFruit(fruit2);
    repo->AddFruit(fruit3);
    auto results = repo->SearchByName("Apfe");
    assert(results.size() == 1);
    assert(results[0].GetName() == "Apfel");
    cout<<"SearchByName Teste fertig!\n";

}