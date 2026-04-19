def dup(sen):
    words=sen.split()
    new=[]
    for word in words:
        if word not in new:
            new.append(word)
        else:
            pass
    return new

Sentence="my my my name name is divy is dicy"

print(dup(Sentence))