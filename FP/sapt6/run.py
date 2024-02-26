from file import citeste_fisier
from res import init_res
from ad_lit import adauga_lit
def start():
    f=citeste_fisier('C:\\Users\\Radu\\Desktop\\python\\sapt6\\res_hm.txt')
    cuv=input('Introduce cuvantul ce trebuie ghicit: ')
    copie_cuv=cuv
    res=init_res(len(cuv))
    while res!=cuv:
        lit=input('Introduceti litera: ')
        if lit in copie_cuv:
            print('Litera se afla in cuvant')
            res=adauga_lit(copie_cuv,res,lit)
            copie_cuv=copie_cuv.replace(lit,'!')
            print(res)
            f.write(res + '\n')
        else:
            print('Litera NU se afla in cuvant')
    
    print('Ai castigat!!!')