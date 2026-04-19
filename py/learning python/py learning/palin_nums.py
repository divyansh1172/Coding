numbers=[121,343,51,151,44344, 100, 1001]

new=[]
for num in numbers:
    i=num
    rev=0
    while i>0:
        rev=rev*10 + i%10
        i//=10
    if rev==num:
        new.append(num)
# print(palins)
print(new)