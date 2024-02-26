def unu(arrunu:list, arrdoi:list):
    res=[]
    i=j=0
    while i<len(arrunu) and j<len(arrdoi):
        if arrunu[i]<arrdoi[j]:
            res.append(arrunu[i])
            i+=1
        else:
            res.append(arrdoi[j])
            j+=1
    
    res+=arrunu[i:] #daca nu au mai ramas elemtne in arrunu dupa oprirea while-ului -> adauga in res de la i incolo
    res+=arrdoi[j:]
    return res

def doi(l):
    if len(l)<1:
        return l
    else:
        if l[0]==0:
            return [0] + doi(l[1:])
        else:
            return doi(l[1:]) + [1]

def trei(l, start, end):
    if start > end:
        return end+1

    if start != l[start]:
        return start

    mid = (start+end)//2
    if mid == l[mid]:
        return trei(l, mid+1, end)
    else:
        return trei(l, start, mid-1)

def patru(l, nr):
    for i,a in enumerate(l):
        j=i+1
        k=len(l)-1
        while j<k:
            s=a+l[j]+l[k]
            if s==nr: return a,l[j],l[k]
            elif s>nr: k-=1
            else: j+=1

def cinci(l):
    indc=-1
    ct=0
    for i,a in enumerate(l):
        if a==1:
            indc=i
            break
    while l[indc]==1:
        ct+=1
        indc+=1
    return ct


def sase(l,nr):
    st=0
    dr=len(l)-1
    mid=(st+dr)//2
    while st<dr:    
        if l[mid] == nr:
            break
        if mid<nr:
            dr=mid
        elif mid>nr:
            st=mid
        mid=(st+dr)//2
        
        
    
    while l[mid]==nr:
        mid+=1
    return mid-1

def bucket(l):
    buckets=[]
    
    for i in range(len(buckets)):
        buckets.append([])

    for j in l:
        index_b = int(j*10)
        buckets[index_b].append(j)

    for i in range(len(buckets)):
        buckets[i].sort()

    res=buckets[0]+buckets[1]+buckets[2]+buckets[3]
    return res
    
def main():
    arrunu = [1,3,5,7]
    arrdoi = [2,4,6,8]
    print(unu(arrunu, arrdoi))
    l = [0,1,0,1,0,1]
    print(doi(l))
    l=[0,1,2,4]
    print(trei(l, 0 ,len(l)))
    l=[1,2,3,5,7]
    print(patru(l,15))
    l=[-2,-2,-1,0,1,1,1,2,3,3]
    print(cinci(l))
    l=[-2,-2,-1,0,1,1,1,2,3,3]
    print(sase(l,1))
    l=[50,31,21,28,72,41,73,93,68,43,45,78,5,17,97,71,69,61,88,75,99,44,55,9]
    print(bucket(l))

main()