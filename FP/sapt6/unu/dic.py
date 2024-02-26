def update_dictionar(d):
  fr=open("C:\\Users\\Radu\\Desktop\\python\\sapt6\\unu\\dictionar.txt", 'r')
  for line in fr:
    data=str(line)
    data=data.split(':')
    inst=str(data[1]).split(',')
    if '' in inst:
      inst.remove('')
    if '\n' in inst:
      inst.remove('\n')
    if data[0] not in d:
      d[data[0]]=inst
  return d
