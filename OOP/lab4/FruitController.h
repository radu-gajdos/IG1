#ifndef CONTROLLER_H
#define CONTROLLER_H
#pragma once

#include "FruitRepository.h"
#include <memory>

namespace Controller
{

    class FruitController
    {
    public:
        FruitController(shared_ptr<Repository::FruitRepository> repo);

        bool AddFruit(string name, string origin, string expiration_date, int quantity, double price);
        void UpdateFruitQuantity(string name, string origin, int quantity);
        void DeleteFruit(string name, string origin, string expiration_date, int quantity, double price);
        vector<Domain::Fruit> SearchFruit(int choice, string name, string origin, int menge);
        vector<Domain::Fruit> SearchByLessThenQuantity(int quantity);
        vector<Domain::Fruit> GetAllFruitsSortedByExpiration();
        vector<Domain::Fruit> GetAllFruitsSortedByName();

    private:
        std::shared_ptr<Repository::FruitRepository> repository;
        std::string name_;
        std::string origin_;
        int quantity_;
    };

}
#endif