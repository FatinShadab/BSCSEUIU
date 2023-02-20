s1 = input()
s2 = input()

l = dict({})

for char in s1:
    if char not in l.keys():
        l[char] = 1
    else:
        l[char] += 1

anagramStr = True

for char in s2:
    if char not in l.keys():
        anagramStr = False
        break
    else:
        if (l[char] != s2.count(char)):
            anagramStr = False
            break

print("Yes" if anagramStr else "No") 