def function(nums):
    new=[]
    for i in nums:
        if len(str(i))%2==0:
            new.append(i)
    return new

nums=[12,666,11,22,44,123235235]
print(function(nums))
