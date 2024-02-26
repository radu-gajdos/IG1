##############soc###########################

class Animal:

    def __init__(self, name):
        self.name=name

    def eat(self):
        print(f'{self.name} is eating')

##############animal_class######################

class Pig(Animal):

    def __init__(self, name, age):
        self.age=age
        Animal.__init__(self, name)

    def sleep(self):
        print(f'{self.name} is eating')

##############pig_class######################

class Chicken(Animal):

    def __init__(self, name, color):
        Animal.__init__(self, name)
        self.color=color

##############chicken_class###################

class Farm:
    def __init__(self, animals, name,  city):
        self.name=name
        self.animals=animals
        self.city=city

    def eat(self):
        for animal in self.animals:
            animal.eat()

##############farm_class###################
    
def main():
    f=Farm([Pig('porcunu', 5),Pig('porcdpo', 5),Chicken('fakeporc', 'alb')], 'Fermaasdasdasd', 'Dej')
    f.eat()

main()