numbers = [4, 7, 1, 9, 2]
largest=numbers[0]
smallest=numbers[0]

for x in numbers:
    if x>largest:
        largest=x
    if x<smallest:
        smallest=x

print(largest)
print(smallest)