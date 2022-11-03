testcase = int(input())

def fact(n : int) -> int:
    if n in (0, 1):
        return 1
    return n * fact(n-1)

for tcase in range(testcase):
    zeros = 0
    number = int(input())
    
    number_fact = str(fact(number))
    fact_str = str(int(number_fact[::-1]))
    
    print(len(number_fact) - len(fact_str))