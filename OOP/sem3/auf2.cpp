#include <string>
#include <map>
#include <iostream>

class GeometricForm
{
private:

    std::string name;

public:

    GeometricForm(std::string name) : name(name) {}

    double calculateArea();

    void printDescription(){
        std::cout<<"Diese geometrisch form ist einen: "<<name;
    };
};


template <typename t>
class Circle : public GeometricForm
{
public:

    Circle(t radius) : GeometricForm("Circle") {
        if (radius < 0) {
            throw std::invalid_argument("Radius can nicht negativ sein!!!");
        }
        this->radius = radius;
    }

    double calculateArea()
    {
        return 3.14 * radius * radius;
    }

    void printDescription() {
        GeometricForm::printDescription();
        std::cout << " mit Radius " << radius <<std::endl;
    }


private:
    t radius;
};

template <typename t>
class Square : public GeometricForm
{
public:

    Square(t laenge) : GeometricForm("Square") {
        if (laenge<0){
            throw std::invalid_argument("Laenge can nicht negativ sein!!!");
        }
        this->laenge=laenge;
    }

    double calculateArea()
    {
        return laenge*laenge;
    }

    void printDescription() {
        GeometricForm::printDescription();
        std::cout << " mit Laenge " << laenge  <<std::endl;
    }


private:
    t laenge;
};

int main(){
    Circle<float> c(3.1);
    std::cout<<std::endl;
    c.printDescription();
    std::cout<<std::endl;
    std::cout<<c.calculateArea();
    
    std::cout<<std::endl;

    Square<float> s(3.1);
    std::cout<<std::endl;
    s.printDescription();
    std::cout<<std::endl;
    std::cout<<s.calculateArea();
}