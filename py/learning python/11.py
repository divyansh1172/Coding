numbers = [12, 45, 7, 89, 23, 56]
largest=numbers[0]
sec_lar=largest

for x in numbers:
    if x>largest:
        largest, sec_lar=x, largest
    elif x>sec_lar and x!=largest:
        sec_lar=x

print(sec_lar)