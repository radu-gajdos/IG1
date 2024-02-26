#ifndef PRODUCT_REPOSITORY_H
#define PRODUCT_REPOSITORY_H
#pragma once
#include <vector>
#include <string>
#include "Fruit.h"

using namespace std;
using namespace Domain;

#pragma once
namespace Repository
{

    class FruitRepository
    {
    public:
        void AddFruit(const Fruit &Fruit);
        void UpdateFruitQuantityAlreadyExists(const Fruit &Fruit, int new_quantity);
        void UpdateFruitQuantity(const string &name, const string &origin, int new_quantity);
        void DeleteFruit(const Domain::Fruit &DeleteFruit);
        vector<Fruit> SearchByName(const string &name) const;
        vector<Fruit> SearchByOrigin(const string &origin) const;
        vector<Fruit> SearchByQuantity(int quantity) const;
        vector<Fruit> SearchByLessThenQuantity(int quantity) const;
        bool FruitExists(const Domain::Fruit Fruit);
        vector<Fruit> GetAllFruitsSortedByExpiration() const;
        vector<Fruit> GetAllFruitsSortedByName() const;

    private:
        vector<Fruit> fruits;
    };

}

#endif