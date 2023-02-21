number = input()

freqDict = dict({})

for digit in number:
    if int(digit) not in freqDict.keys():
        freqDict[int(digit)] = 1
    else:
        freqDict[int(digit)] += 1

print(sorted([digit for digit in number if freqDict[int(digit)] == max(freqDict.values())])[0])