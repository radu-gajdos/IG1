import functools

def ub1(subject):
    file = open("text.txt", 'r')
    lines = file.readlines()
    result = filter(lambda x: subject in x, lines)
    result = list(result)
    file = open("text.txt", 'w')
    file.writelines(result)
    # print(lines[2][-3:])

    x = map(lambda a: int(a.split(',')[3]), result)
     # print(list(x))
     # x = list(x)
    # print(x)
    suma = functools.reduce(lambda a, b: a+b, x)

    print(suma)



    # for list in Lines:
    #     result = filter(lambda x: x == ",", list)
    #     for i in result:
    #         if i == subject:
    #             print(list.strip())

    file.close()

ub1("Advanced programming")

