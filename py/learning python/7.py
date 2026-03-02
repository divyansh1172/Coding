word = input("enter a string: ")
rev= ""
for x in word:
    rev = x + rev
    
print(rev)

if rev==word:
    print("Palindrome")
else:
    print("Not a palindrome")