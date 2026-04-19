def sum(l1):
    sum=0
    for i in l1:
        if i%2==0:
            sum+=i
    return sum

l1=[1,2,3,4,5,6]
print(sum(l1))