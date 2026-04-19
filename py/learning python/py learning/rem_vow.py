def function(sent):
    s=""
    vowels="aeiouAEIOU"
    for i in sent:
        if i not in vowels:
            s = s+i
    return s

sent="my name is divy shampi"
print(function(sent))
print(len(str(10)))