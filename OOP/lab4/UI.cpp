#include "UI.h"

#include <iostream>
#include <string>

namespace UI
{

    Console::Console(shared_ptr<Controller::FruitController> contr)
    {
        controller = contr;
    }

    void Console::Run()
    {
        char choice;
        do
        {
            DisplayMenu();
            std::cout << "Waehle: ";
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                AddFruit();
                break;

            case '2':
                UpdateFruitQuantity();
                break;

            case '3':
                DeleteFruit();
                break;

            case '4':
                SearchFruit();
                break;

            case '5':
                SearchByLessThenQuantity();
                break;

            case '6':
                GetAllFruitsSortedByExpiration();
                break;

            case '7':
                GetAllFruitsSortedByName();
                break;

            case '0':
                std::cout << "Danke byeee!\n";
                break;

            default:
                std::cout << "Ungultige Wahl\n";
            }

            std::cout << std::endl;

        } while (choice != '0');
    }

    void Console::DisplayMenu()
    {
        std::cout << "Fruchteladen:\n";
        std::cout << "1. Frucht hinzufuegen\n";
        std::cout << "2. Menge wechseln\n";
        std::cout << "3. Fruit loeschent\n";
        std::cout << "4. Suche Fruit\n";
        std::cout << "5. Suche nach wenigstens Menge: \n";
        std::cout << "6. Fruchte nach Haltbarkeitsdatum sortiert sehen: \n";
        std::cout << "7. Fruchte nach Name sortiert sehen: \n";
        std::cout << "0. Auschalten\n";
    }

    void Console::AddFruit()
    {

        string name, origin, expiration_date;
        int quantity;
        double price;

        cout << "Name des Fruchtes hinzufuegen: ";
        cin >> name;

        cout << "Name des Herkunft hinzufuegen: ";
        cin >> origin;

        cout << "Hinzufuegen die Menge: ";
        cin >> quantity;

        cout << "Hinzufuegen dem Preis: ";
        cin >> price;

        cout << "Hinzufuegen dem Haltbarkeitsdatum: ";
        cin >> expiration_date;

        bool check;
        check = controller->AddFruit(name, origin, expiration_date, quantity, price);
        
        if (check == false)
        {
            cout << "Frucht existiert shon, Menge updatiert\n";
        }
    }

    void Console::UpdateFruitQuantity()
    {

        string name, origin;
        int quantity;

        cout << "Name des Fruchtes hinzufuegen: ";
        cin >> name;

        cout << "Name des Herkunft hinzufuegen: ";
        cin >> origin;

        cout << "Hinzufuegen die Menge: ";
        cin >> quantity;

        controller->UpdateFruitQuantity(name, origin, quantity);
    }

    void Console::DeleteFruit()
    {

        string name, origin, expiration_date;
        int quantity, price;

        cout << "Name des Fruchtes hinzufuegen: ";
        cin >> name;

        cout << "Name des Herkunft hinzufuegen: ";
        cin >> origin;

        cout << "Haltbarkeitsdatum des Fruchtes hinzufuegen: ";
        cin >> expiration_date;

        cout << "Menge des Fruchtes hinzufuegen: ";
        cin >> quantity;

        cout << "Preis des Fruchtes hinzufuegen: ";
        cin >> price;

        controller->DeleteFruit(name, origin, expiration_date, quantity, price);
    }

    void Console::SearchFruit()
    {

        cout << "Suche Frucht nach:\n";
        cout << "1. Name\n";
        cout << "2. Herkunft\n";
        cout << "3. Menge\n";
        cout << "Waehle: ";

        vector<Domain::Fruit> search_results;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Name des Fruchtes hinzufuegen: ";
            cin >> name;
            search_results = controller->SearchFruit(1, name, "", 0);
            break;
        }
        case 2:
        {
            string origin;
            cout << "Herkunft des Fruchtes hinzufuegen: ";
            cin >> origin;
            search_results = controller->SearchFruit(2, "", origin, 0);
            break;
        }
        case 3:
        {
            int quantity;
            cout << "Menge des Fruchtes hinzufuegen: ";
            cin >> quantity;
            search_results = controller->SearchFruit(2, "", "", quantity);
            break;
        }
        default:
            cout << "Ungültige Auswahl\n";
            return;
        }

        cout << "Suchergebnisse:\n";
        if (search_results.empty())
        {
            cout << "Keine Fruchte gefunden!\n";
        }
        else
        {
            cout << "------------------------------\n";
            for (const auto &product : search_results)
            {
                cout << product.GetName() << " | " << product.GetOrigin() << " | " << product.GetExpirationDate() << " | " << product.GetQuantity() << " | " << product.GetPrice() << "\n";
                cout << "--------------------------------\n";
            }
        }
    }

    void Console::SearchByLessThenQuantity()
    {
        int quantity;

        cout << "Hinzufuegen die Menge: ";
        cin >> quantity;

        vector<Domain::Fruit> search_results;

        search_results = controller->SearchByLessThenQuantity(quantity);

        if (search_results.empty())
        {
            cout << "Keine Fruchte gefunden\n";
        }
        else
        {
            for (const auto &product : search_results)
            {
                cout << product.GetName() << " | " << product.GetOrigin()
                     << " | " << product.GetExpirationDate() << " | "
                     << product.GetQuantity() << " | " << product.GetPrice()
                     << "\n";
            }
        }
    }

    void Console::GetAllFruitsSortedByExpiration()
    {
        vector<Domain::Fruit> search_results;

        search_results = controller->GetAllFruitsSortedByExpiration();

        if (search_results.empty())
        {
            cout << "Keine Fruchte gefunden\n";
        }
        else
        {
            for (const auto &product : search_results)
            {
                cout << product.GetName() << " | " << product.GetOrigin()
                     << " | " << product.GetExpirationDate() << " | "
                     << product.GetQuantity() << " | " << product.GetPrice()
                     << "\n";
            }
        }
    }

    void Console::GetAllFruitsSortedByName()
    {
        vector<Domain::Fruit> search_results;

        search_results = controller->GetAllFruitsSortedByName();

        if (search_results.empty())
        {
            cout << "Keine Fruchte gefunden\n";
        }
        else
        {
            for (const auto &product : search_results)
            {
                cout << product.GetName() << " | " << product.GetOrigin() << " | " << product.GetExpirationDate() << " | " << product.GetQuantity() << " | " << product.GetPrice() << "\n";
            }
        }
    }

}
