#include <string>
#include <vector>
#include <iostream>

class Customer {
public:
    int id;
    std::string representantName;
    std::string firmName;
    bool deleted;

};

template<class T>
class AbstractCustomer {
public:
    int id;
    std::string representantName;
    std::string firmName;
    bool deleted;

    virtual ~AbstractCustomer() = default;
};

template<class T>
class CRUDRepository : public AbstractCustomer<T> {
public:
    CRUDRepository() = default;

    virtual void create(T c) = 0;

    virtual std::vector<T> findAll() = 0;

    virtual void update(int id, std::string &what) = 0;

    virtual void del(int id) = 0;

    virtual ~CRUDRepository() = default;
};

template<class T>
class InMemoryRepository : public CRUDRepository<T> {
private:
    std::vector<T> customers;
public:
    virtual void create(T c) {
        customers.push_back(c);
    };

    virtual std::vector<T> findAll() {
        std::vector<T> result;
        for (auto c: customers) {
            if (!c.deleted) {
                result.push_back(c);
            }
        }
        return result;
    };

    virtual void update(int id, std::string &what) {
        T customer;
        for (auto c: customers) {
            if (c.id == id && !c.deleted) {
                customer = c;
            }
        }
        if (what == "customerName") {
            std::string newName;
            std::cout << "Input customerName:" << std::endl;
            std::cin >> newName;
            customer.customerName = newName;
        }

        if (what == "firmName") {
            std::string newName;
            std::cout << "Input firmName:" << std::endl;
            std::cin >> newName;
            customer.firmName = newName;
        }

    };

    virtual void del(int id) {
        for (auto c: customers) {
            if (!c.deleted) {
                customers.erase(c);
            }
        }
    };

};