from typing import List

testcase : int = int(input())

while testcase:

    n : int = int(input())
    words : List[str] = [input() for word in range(n)]
    print("\n".join(sorted(words)))

    testcase -= 1