import functools
def ub1(subject):

    fr = open('C:\\Users\\Radu\\Desktop\\python\\muster\\text.txt', 'r')
    lines = fr.readlines()

    res = filter(lambda x: subject in x, lines)
    res=list(res)

    ct=len(res)

    fw = open('C:\\Users\\Radu\\Desktop\\python\\muster\\res.txt', 'w')
    fw.writelines(res)

    temp = map(lambda a: int(a.split(',')[3]), res)
    s = functools.reduce(lambda a, b: a+b, temp)

    return s/ct

import unittest

class TestOper(unittest.TestCase):
    def test_ub1(self):
        self.assertEqual(8.166666666666666,ub1('Advanced programming'))
        
    def test2_ub1(self):
        self.assertEqual(22,ub1('Advanced programming'))

if __name__ == '__main__':
    unittest.main()