def fact(nums):
    facs=[]
    for i in nums:
        if i==0:
            facs.append(1)
        else:
            f=1
            for j in range(1,i+1):
                f*=j
            facs.append(f)
    return facs

nums=[0,1,2,3,4,5,6,7,8,9]
print(fact(nums))