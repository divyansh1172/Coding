def func(s):
    cons, vow=0,0
    for i in s:
        if i not in ['a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'] and i!=' ':
            cons+=1
            continue
        elif i!=' ':
            vow+=1
    return cons,vow

s="i love jaiminie"
cons,vow=func(s)
print(cons)
print(vow)