#exemplu citire prelucarare map filter

def read_file():
    with(open("text.txt") as f):
        content = f.read()

        content = content.split("\n")
        return list(map(lambda x: x.split(" "), content))

content = read_file()
content = list(filter(lambda x: int(x[-1]) == 1, content))

noten = list(map(lambda x: int(x[-1]), content))