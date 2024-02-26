def adauga_lit(cuv,res,lit):
    print(cuv)
    print(res)
    for i in range(len(cuv)):
        if cuv[i]==lit:
            res = res[:i]+lit+res[i:]
            res = res[:i+1] + res[i+2:]

            
    return res
