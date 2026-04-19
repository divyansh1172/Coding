def function(base,exp):
    num=1
    for i in range(exp):
        num*=base
    return num

def second_largest(nums):
    max,second=nums[0],nums[0]
    for i in nums:
        if i>max:
            second=max
            max=i
        elif i<max and i>second:
            second=i
        else:
            continue
    return second

print(second_largest(nums=[1,2,3,4,5,6,7,89,9]))            

def freq(sen):
    freq={}
    for i in sen:
        if i in freq:
            freq[i]+=1
        else:
            freq[i]=1
    return freq

print(freq("sentence"))