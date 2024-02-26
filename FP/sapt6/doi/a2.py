def ex2():
    nr=0
    wort=input("Wort zum ersetzen:")
    erwort=input("Ersatzwort:")
    fr = open("C:\\Users\\Radu\\Desktop\\python\\sapt6\\doi\\text.txt", "r")
    data = fr.read()
    fr.close()
    fw = open("C:\\Users\\Radu\\Desktop\\python\\sapt6\\doi\\text.txt", "w")

    for word in data.split():
        if wort in word:
            nr+=1 #aici se contorizeaza
            data = data.replace(wort, erwort)
    fw.write(data)
    
    if nr == 0:
        print("Cuvantul nu se afla in fisier!!!")
    else:
        print('Cuvantul a fost inlocuit de ', nr, ' ori')
    
ex2()