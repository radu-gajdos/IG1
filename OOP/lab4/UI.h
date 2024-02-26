#ifndef UI_H
#define UI_H
#pragma once

#include "FruitController.h"
#include <memory>

namespace UI
{

    class Console
    {
    public:
        Console(std::shared_ptr<Controller::FruitController> contr);
        void Run();

    private:
        std::shared_ptr<Controller::FruitController> controller;

        void DisplayMenu();
        void AddFruit();
        void UpdateFruitQuantity();
        void DeleteFruit();
        void SearchFruit();
        void SearchByLessThenQuantity();
        void GetAllFruitsSortedByExpiration();
        void GetAllFruitsSortedByName();
    };

}

#endif
