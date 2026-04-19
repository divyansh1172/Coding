def word_frequency(sentence):
    words = sentence.split()   # split sentence into words
    freq = {}

    for word in words:
        if word in freq:
            freq[word] += 1
        else:
            freq[word] = 1

    return freq

sentence = input("Enter a sentence: ")

result = word_frequency(sentence)

print(result)