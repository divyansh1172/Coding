def func(a1,a2):
    d1=set(a1)
    d2=set(a2)
    return list(d1 & d2)

a1=[1,2,3,4,5,6]
a2=[3,4,5,6,7,8]
print(func(a1,a2))