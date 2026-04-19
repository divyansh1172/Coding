def rem(nums, k):
    new=[]
    for i in nums:
        if i%k!=0:
            new.append(i)
    return new

mylist=[5,6,7,10,15,19,20,69,67,3]
k=5
print(rem(mylist,k))