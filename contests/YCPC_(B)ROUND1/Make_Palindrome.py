def change(s):
    n = len(s)
    cc = 0
    for i in range(n//2):
        if(s[i]== s[n-i-1]):
            continue
        cc+= 1
        if(s[i]<s[n-i-1]):
            s[n-i-1]= s[i]
        else:
            s[i]= s[n-i-1]
 
    return cc
     

inputs = []
while True:
    try:
        input_ = input()
        inputs.append(input_)
    except EOFError:
        break
    except:
        break

for _input in inputs:
    if _input == _input[::-1]:
        print(0)
    else:
        print(change(list(_input)))