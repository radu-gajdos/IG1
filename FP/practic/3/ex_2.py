class BadValue(AssertionError):
    pass

class CaesarEncryptedText():
    def __init__(self, numbers:list):
        self.numbers=numbers

    def decrypt(self, decryption_key):
        res=[]
        for number in self.numbers:
            if number-decryption_key >=65 and number-decryption_key <=90:
                print(number-decryption_key)
                res.append(number)
            else:
                raise BadValue()
        return res

c=CaesarEncryptedText([66,67])
c.decrypt(1)

class ActualCaesarEncryptedText(CaesarEncryptedText):
    def __init__(self, message):
        super().__init__()
        self.message = message

    def decrypt(self, decryption_key):
        if type(super().decrypt(decryption_key))==list:
            self.message = super().decrypt(decryption_key)
        else:
            self.message = None

    def div(self, cdoi):
        return ascii(self.message)