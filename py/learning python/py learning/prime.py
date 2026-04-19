# all prime nums in a list using a function

def prime(n):
    for i in range(2,int(n**0.5) +1):
        if n%i==0:
            return False
    return True

mylist=[2,3,4,5,765,26,46,7,99,71]
primes=[]
for i in mylist:
    if prime(i)==True:
        primes.append(i)
    else:
        pass

print(primes)