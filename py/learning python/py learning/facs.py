def factors(n):
    facs=[]
    a=n
    for i in range(2,n+1):
        if a%i==0:
            facs.append(i)
            while a%i==0:
                a//=i
    return facs

n=2*3*4*5*7*19*17
print(n)
print(factors(n))
