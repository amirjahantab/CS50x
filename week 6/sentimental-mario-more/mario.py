while True:
    height = input("Height: ")
    if height.isnumeric() and int(height) >= 1 and int(height) != 9:
        break
    else:
        print("Invalid input!")

temp = int(height)
for i in range(int(height)):
    print((temp - 1) * " ", (i + 1) * "#", sep="", end="  ")
    print("#" * (i +1))
    temp -= 1
