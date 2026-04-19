sentence="My jaanu is is is XYZ"
words=sentence.split()
seen=[]

for word in words:
    if word not in seen:
        seen.append(word)

res=""
for word in seen:
    res = res + " " + word

print(words)
print(res)