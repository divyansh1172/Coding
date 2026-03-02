nums = [1,2,3,2,4,5,3,6]

seen =set()

for x in nums:
    if x in seen:
        print(x)
    else:
        seen.add(x)