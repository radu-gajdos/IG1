def cinci():
    d={0:'0',1:'1',2:'2',3:'3',4:'4',5:'5',6:'6',7:'7',8:'8',9:'9'}#dictionarul de conversie din type:int in type:string
    str='x/y=2'#operatia matematica introdusa ca type:string
    res=[]#lista noua formata doar din numerele ce coincid cu regula data in str
    liste=[42, 12, 21, 11, 14, 41, 41, 15, 51, 62]#lista initiala
    for i in range(len(liste)):
        temp=str#operatia copiata pentru ca urmeaza sa fie modificata
        x=liste[i]//10#prima cifra
        y=liste[i]%10#a doua cifra
        a=d[x]#conversia primei cifre in type:string
        b=d[y]#conversia celei de a doua cifre in type:string
        temp=temp.replace('x', a).replace('y', b)#inlocuirea lui x si y cu cifrele propriuzise doar ca drept string
        if(eval(temp.split('=')[0]) == eval(temp.split('=')[1])):#daca evaluarea a ce este inainte de '=' este == cu evaluarea a ce este dupa'='
            res.append(liste[i])#adauga elementul din lista initiala in lista filtrata

    print(res)
