def function(nums, target):
    pairs=[]
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i]+nums[j]==target:
                pairs.append((nums[i], nums[j]))
    return pairs

nums=[1,2,3,4,5,6]
target=7
print(function(nums,target=6))

