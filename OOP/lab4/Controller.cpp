#include "FruitController.h"
#include <iostream>
#include <string>

using namespace std;

namespace Controller
{

    FruitController::FruitController(shared_ptr<Repository::FruitRepository> repo)
    {
        repository = repo;
    }

    bool FruitController::AddFruit(string name, string origin, string expiration_date, int quantity, double price)
    {

        Domain::Fruit TempFruit(name, origin, expiration_date, quantity, price);

        if (repository->FruitExists(TempFruit))
        {
            repository->UpdateFruitQuantityAlreadyExists(TempFruit, quantity);
            return false;
        }
        else
        {

            Domain::Fruit frucht(name, origin, expiration_date, quantity, price);
            repository->AddFruit(frucht);
        }

        return true;
    }

    void FruitController::UpdateFruitQuantity(string name, string origin, int quantity)
    {
        repository->UpdateFruitQuantity(name, origin, quantity);
    }

    void FruitController::DeleteFruit(string name, string origin, string expiration_date, int quantity, double price)
    {
        Domain::Fruit frucht(name, origin, expiration_date, quantity, price);
        repository->DeleteFruit(frucht);
    }

    vector<Domain::Fruit> FruitController::SearchFruit(int choice, string name, string origin, int quantity)
    {

        vector<Domain::Fruit> search_results;

        switch (choice)
        {
        case 1:
        {
            search_results = repository->SearchByName(name);
            break;
        }
        case 2:
        {
            search_results = repository->SearchByOrigin(origin);
            break;
        }
        case 3:
        {
            search_results = repository->SearchByQuantity(quantity);
            break;
        }
        default:
            return search_results;
        }

        return search_results;
    }

    vector<Domain::Fruit> FruitController::SearchByLessThenQuantity(int quantity)
    {

        vector<Domain::Fruit> search_results;
        search_results = repository->SearchByLessThenQuantity(quantity);

        return search_results;
    }

    vector<Domain::Fruit> FruitController::GetAllFruitsSortedByExpiration()
    {

        vector<Domain::Fruit> search_results;
        search_results = repository->GetAllFruitsSortedByExpiration();

        return search_results;
    }

    vector<Domain::Fruit> FruitController::GetAllFruitsSortedByName()
    {

        vector<Domain::Fruit> search_results;
        search_results = repository->GetAllFruitsSortedByName();

        return search_results;
    }

}
