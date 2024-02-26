#include "Fruit.h"

using namespace Domain;

// Konstruktor
Fruit::Fruit(string name, string origin, string expiration_date, int quantity, double price)
    : name_(name), origin_(origin), expiration_date_(expiration_date), quantity_(quantity), price_(price) {}

Fruit::Fruit(string name, string origin, int quantity, double price)
    : name_(name), origin_(origin), quantity_(quantity), price_(price) {}

// Getters und Setters

// Name
string Fruit::GetName() const
{
    return name_;
}

void Fruit::SetName(string name)
{
    name_ = name;
}

// Herkunft
string Fruit::GetOrigin() const
{
    return origin_;
}

void Fruit::SetOrigin(string origin)
{
    origin_ = origin;
}

// Haltbarkeitsdatum
string Fruit::GetExpirationDate() const
{
    return expiration_date_;
}

void Fruit::SetExpirationDate(string expiration_date)
{
    expiration_date_ = expiration_date;
}

// Menge
int Fruit::GetQuantity() const
{
    return quantity_;
}

void Fruit::SetQuantity(int quantity)
{
    quantity_ = quantity;
}

// Preis
double Fruit::GetPrice() const
{
    return price_;
}

void Fruit::SetPrice(double price)
{
    price_ = price;
}