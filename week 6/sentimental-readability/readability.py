# TODO
import string
import math

# printable = list(string.printable)

# letter_list = list(string.ascii_letters)

# for letter in printable[:]:
#     if letter in letter_list:
#         printable.remove(letter)
# printable.remove(" ")
# printable.remove("'")

text = str(input("Text: "))

count_word = 1
for letter in text:
    if letter == " ":
        count_word += 1

count_sentence = 0
for letter in text:
    if letter == "." or letter == "?" or letter == "!":
        count_sentence += 1

len_text = 0
for letter in text:
    if letter.isalpha() == True:
        len_text += 1

L = (len_text / count_word) * 100
S = (count_sentence / count_word) * 100

Grade = math.ceil(0.0588 * L - 0.296 * S - 15.8)

if Grade > 16:
    print("Grade 16+")
elif Grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {Grade}")

# print(f"count_word: {count_word}    count_sentence: {count_sentence}    len: {len_text}")
