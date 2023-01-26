year = int(input())

while True:
    year += 1

    distinct_digits_year = True
    
    temp = str(year)
    for idx, digit in enumerate(temp):
        if digit in temp[idx+1:]:
            distinct_digits_year = False
            break
    
    if (distinct_digits_year):
        print(year)
        break