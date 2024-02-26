#include "FruitRepository.h"

using namespace std;

namespace Repository
{

    void FruitRepository::AddFruit(const Fruit &Fruit)
    {
        fruits.push_back(Fruit);
    }

    void FruitRepository::UpdateFruitQuantity(const string &name, const string &origin, int new_quantity)
    {
        for (auto &fruit : fruits)
        {
            if (fruit.GetName() == name && fruit.GetOrigin() == origin)
            {
                fruit.SetQuantity(new_quantity);
                break;
            }
        }
    }

    void FruitRepository::UpdateFruitQuantityAlreadyExists(const Fruit &Fruit, int new_quantity)
    {
        for (auto &fruit : fruits)
        {
            if (fruit.GetName() == Fruit.GetName() && fruit.GetOrigin() == Fruit.GetOrigin())
            {
                fruit.SetQuantity(new_quantity);
                break;
            }
        }
    }

    void FruitRepository::DeleteFruit(const Domain::Fruit &DeleteFruit)
    {
        for (auto it = fruits.begin(); it != fruits.end(); ++it)
        {
            if (it->GetName() == DeleteFruit.GetName() && it->GetOrigin() == DeleteFruit.GetOrigin())
            {
                fruits.erase(it);
                break;
            }
        }
    }

    vector<Fruit> FruitRepository::SearchByName(const string &name) const
    {
        vector<Fruit> results;
        for (const auto &fruit : fruits)
        {
            if (name.empty() || fruit.GetName().find(name) != string::npos)
            {
                results.push_back(fruit);
            }
        }
        return results;
    }

    vector<Fruit> FruitRepository::SearchByOrigin(const string &origin) const
    {
        vector<Fruit> results;
        for (const auto &product : fruits)
        {
            if (origin.empty() || product.GetOrigin().find(origin) != string::npos)
            {
                results.push_back(product);
            }
        }
        return results;
    }

    vector<Fruit> FruitRepository::SearchByQuantity(int quantity) const
    {
        vector<Fruit> results;
        for (const auto &fruit : fruits)
        {
            if (quantity == 0 || fruit.GetQuantity() == quantity)
            {
                results.push_back(fruit);
            }
        }
        return results;
    }

    vector<Fruit> FruitRepository::SearchByLessThenQuantity(int quantity) const
    {
        vector<Fruit> results;
        for (const auto &fruit : fruits)
        {
            if (quantity == 0 || fruit.GetQuantity() < quantity)
            {
                results.push_back(fruit);
            }
        }
        return results;
    }

    bool FruitRepository::FruitExists(const Domain::Fruit ExistsFruit)
    {
        for (const auto &fruit : fruits)
        {
            if (fruit.GetName() == ExistsFruit.GetName() && fruit.GetOrigin() == ExistsFruit.GetOrigin())
            {
                return true;
            }
        }
        return false;
    }

    vector<Fruit> FruitRepository::GetAllFruitsSortedByExpiration() const
    {
        vector<Fruit> results = fruits;
        for (int i = 0; i < results.size() - 1; i++)
        {
            for (int j = i + 1; j < results.size(); j++)
            {
                string date1 = results[i].GetExpirationDate();
                string date2 = results[j].GetExpirationDate();
                int day1 = stoi(date1.substr(0, 2));
                int month1 = stoi(date1.substr(3, 2));
                int year1 = stoi(date1.substr(6, 2));
                int day2 = stoi(date2.substr(0, 2));
                int month2 = stoi(date2.substr(3, 2));
                int year2 = stoi(date2.substr(6, 2));
                if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2))
                {
                    swap(results[i], results[j]);
                }
            }
        }
        return results;
    }

    vector<Fruit> FruitRepository::GetAllFruitsSortedByName() const
    {
        vector<Fruit> results = fruits;

        int length = results.size();

        for (int i = 0; i < length - 1; i++)
        {
            for (int j = 0; j < length - i - 1; j++)
            {
                if (results[j].GetName().compare(results[j + 1].GetName()) > 0)
                {
                    swap(results[j], results[j + 1]);
                }
            }
        }

        return results;
    }

}
