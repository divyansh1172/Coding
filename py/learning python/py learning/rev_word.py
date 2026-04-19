sentence="MY JAANU IS JAIMINIE"
words=sentence.split()
new=[]

for word in words:
    new.append(word[::-1])

res=""
for word in new:
    res = res + " " + word

print(res)
print(new)