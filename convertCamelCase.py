def replaceWithIndex(word,i):
    if i >= len(word):
        return word
    return word[:i] + word[i].capitalize() + word[i+1:]

def convertToCamelCase(word):
    found = word.find("_")
    findAll = [ i for i in range(len(word)) if word.startswith("_",i) ]
    for i in findAll:
        if i+1 < len(word):
            word=replaceWithIndex(word,i+1)
    word = word.replace("_","")
    word = word[0].capitalize() + word[1:]
    return word
