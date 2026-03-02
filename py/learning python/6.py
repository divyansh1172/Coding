name = input("Enter a word:  ")
vowels= ['a', 'e', 'i', 'o', 'u']
count=0
for x in name:
    if x in vowels:
        count+=1

print(count)