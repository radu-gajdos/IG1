munu=[[{1,2,3},{2}],
      [{10,15},{3}]
        ]
mdoi=[[{1,2,3},{10,15}],
      [{9},{2}]
        ]
for i in range(len(mdoi)):
    for j in range(len(mdoi[i])):
        for k in range(len(mdoi[i][j])):
            if mdoi[i][j] in munu[i]:
                munu[i].remove(mdoi[i][j])

print(munu)