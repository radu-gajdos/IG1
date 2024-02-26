class BankAccount():
    def __init__(self,owner):
        self.owner=owner
        self.amount=0

    def withdraw(self, n):
        if self.amount >= n:
            self.amount -=n
            return self.amount
        else:
            print('NoMoney')
            return False

class CreditBankAccount(BankAccount):
    def __init__(self, owner):
        super().__init__(owner)
        self.credit_score=1

    def withdraw(self, n):
        if super().withdraw(n) != False:
            self.credit_score+=1
            return super().withdraw(n)
        else:
            self.credit_score-=1
            self.amount -=n

    def sum(self, cbdoi):
        self.amount+=cbdoi.amount
        self.credit_score+=cbdoi.credit_score
        cbdoi.amount=0
        cbdoi.credit_score=1


def my_func(n):
    if n in (0, 1):
        return n

    a, b = 0, 1
    for i in range(2, n + 1):
        a, b = b, a + b
    return b
    
def main():
    cb1=CreditBankAccount('Radu')
    cb2=CreditBankAccount('Gigi')
    cb1.withdraw(1)
    print(cb1.amount)
    print(cb1.credit_score)
    cb1=CreditBankAccount('Radu')
    cb2=CreditBankAccount('Gigi')
    cb1.sum(cb2)
    print(cb1.amount)
    print(cb1.credit_score)
    print(my_func(10))


main()



