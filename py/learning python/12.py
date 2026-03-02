nums = [5,5,5,2,2,8,1,1,1,1]
freq={}

for x in nums:
    if x in freq:
        freq[x]+=1
    else:
        freq[x]=1
        
for key in freq:
    print(key, ":", freq[key])