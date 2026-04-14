nums = [3, 5, 2, 8, 11]
target = 10

for x in range(0, len(nums)):
    for y in range(x+1, len(nums)):
        if nums[x]+nums[y] == target:
            print(nums[x], " + ", nums[y], " = ", target)
            break
        y+=1
    x+=1

seen =set()



