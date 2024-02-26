class Student:

    def __init__(self, name):
        object.__setattr__(self, "name", name)
    
    def __setattr__(self, name, value):
        raise ValueError('Nu se puede!')

    def __delattr__(self, name):
        raise ValueError('Mortii mei!')
    
def main():
    bob=Student('bob')
    bob.name='dob'

main()