# TODO


while True:
    number = str(input("Number: "))
    if number.isnumeric():
        break

if len(number) == 15 and ((number[0:2] == "34") or (number[0:2] == "37")):
    print("AMEX\n")


elif len(number) == 16 and (
    number[0:2] == "51"
    or number[0:2] == "52"
    or number[0:2] == "53"
    or number[0:2] == "54"
    or number[0:2] == "55"
):
    print("MASTERCARD\n")

elif (len(number) == 13 or len(number) == 16) and number[0] == "4":
    print("VISA\n")

else:
    print("INVALID\n")
