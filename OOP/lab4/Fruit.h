#ifndef PRODUCT_H
#define PRODUCT_H
#pragma once

#include <string>

using namespace std;

namespace Domain
{
    class Fruit
    {

    private:
        string name_;
        string origin_;
        string expiration_date_;
        int quantity_;
        double price_;

    public:
        // Konstruktor
        Fruit(string name, string origin, string expiration_date, int quantity, double price);

        // Konstruktor fuer AddProductUpdate
        Fruit(string name, string origin, int quantity, double price);

        // Getters und Setters
        void SetName(string name);
        string GetName() const;

        void SetOrigin(string origin);
        string GetOrigin() const;

        string GetExpirationDate() const;
        void SetExpirationDate(string expiration_date);

        void SetQuantity(int quantity);
        int GetQuantity() const;

        void SetPrice(double price);
        double GetPrice() const;
    };
}
#endif
