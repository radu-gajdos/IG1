def bucket_sort(lista_in):
    minim = min(lista_in)
    lungime_bucket = len(lista_in)
    buckets = [[] for _ in range(lungime_bucket)]
    print(buckets)
    for i in range(len(lista_in)):
        bucket_index = int((lista_in[i] - minim) / lungime_bucket)
        buckets[bucket_index].append(lista_in[i])
    for i in range(len(buckets)):
        buckets[i] = sorted(buckets[i])
    lista_out = []
    for i in range(len(buckets)):
        lista_out += buckets[i]
    return lista_out

import re

def validate(s):
    pattern = re.compile(r'^[A-Z]{2}-\d{2}-[A-Z]{3}$')
    return True if pattern.match(s) else False

def pig_latin(s):
    new = s[1:]
    new+=s[0]
    new+='ay'
    return new


assert pig_latin('word') == 'ordway'


def text(text: str):
    f = open(text, 'r')
    content = f.read()
    f.close()
    content = content.split('\n')
    content = list(map(lambda x: x.split(' '), content))
    return list(map(lambda i: list(map(lambda x: pig_latin(x), i)), content))




def main():
    lista = [0.89, 0.12, 0.79, 0.21, 0.45, 0.98, 10.67, 0.35, 66, 20.9, 3.9, 5, 1.87, 10, 0.99, 13, 13.6]
    print(bucket_sort(lista))
    strin="AB-12-ABC"
    print(validate(strin))
    print(text('text.txt'))
main()