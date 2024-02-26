import math
from functools import reduce
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def check_line_length(line):
    words = line.split()
    word_lengths = map(len, words)
    total_length = reduce(lambda x, y: x+y, word_lengths)
    if total_length > 124:
        return False

def check_file(file_name):
    num_sum = 0
    with open(file_name, 'r') as f:

        lines = f.readlines()

        for i, line in enumerate(lines):
            if (i+1) % 3 == 0 and not line.startswith('.'):
                return "Puncte"
            num_char=0
            words = line.split()
            m = len(list(filter(lambda x: len(x) > 124, words)))
            print(m)
            for word in line.split():
                num_char+=len(word)
                if word.isnumeric():
                    num_sum += int(word)

            if check_line_length(line)==False:
                return 'Lungimea prea mare'

    if not is_prime(num_sum):
        print(num_sum)
        return "Nu este prim"

    return "OK"

file_name = 'text.txt'
print(check_file(file_name))

