
def file_lesen():
    with(open("something.txt") as f):
        continut=f.read()
        continut=continut.split('\n')
        return continut

def file_to_splitsplit():
    with(open("something.txt") as f):
        continut=f.read()
        continut=continut.split('\t')
        return continut
def ub_1(even):
    res=file_lesen()
    if even==True:
        res=res[::2]
    elif even==False:
        res=res[1::2]
        print(res)

    res=list(map(lambda x: x.split("\t")[0], res))

    return res

import unittest

class TestListElements(unittest.TestCase):
    def setUp(self):
        self.expected = ['Gheorghe', 'Maria', 'Paul', 'Marian']
        self.expected2 = ['Ioan', 'Alexandra', 'Shakira', 'Johnny', 'Vasile']
        self.result = ub_1(False)

    def test_list_eq(self):
        """Will fail"""
        self.assertListEqual(self.result, self.expected)
        self.assertListEqual(self.result, self.expected2)

if __name__ == "__main__":
    unittest.main()

