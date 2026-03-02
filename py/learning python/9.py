num = int(input("enter a number: "))
y=range(2, int(num**0.5) +1)
prime=1
for x in y:
    if num%x==0:
        prime=0
        break
if prime==0:
    print("Not a prime")
else:
    print("Prime")