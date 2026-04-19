import random 

def new():
    nums=[]
    for i in range(10):
        nums.append(random.randrange(100))
    print(nums)
    new=[x**3 for x in nums]
    print(new)

def sum(nums):
    s=0
    for i in nums:
        s+=i
    return sum

def min_max(nums):
    max=nums[0]
    min=nums[0]
    for i in nums:
        if i>max:
            max=i
        if i<min:
            min=i
    return max,min

def even_od(nums):
    even,odd=0,0
    for i in nums:
        if i%2==0:
            even+=1
        else:
            odd+=1
    return even,odd

def even_offff(nums):
    even=[]
    odd =[]
    for i in nums:
        if i%2==0:
            even.append(i)
        else:
            odd.append(i)
    return even,odd
new()