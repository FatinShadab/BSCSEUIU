number = int(input())

output = []

count = 1

if (number == 0):
    print(0)

while (number):
    output.append(str(number%10))
    if (count % 3 == 0 and number//10 != 0):
        output.append(",")
    number //= 10
    count += 1


print("".join(output[::-1]))