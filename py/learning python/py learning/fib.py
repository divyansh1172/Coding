def fib2(n):
    res=[]
    for i in range(0,n):
        if i==0:
            res.append(0)
        elif i==1:
            res.append(1)
        else:
            res.append(res[i-1]+res[i-2])
    return res

print(fib2(10))