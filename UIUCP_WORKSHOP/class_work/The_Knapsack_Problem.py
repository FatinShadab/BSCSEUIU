"""
    The famous knapsack problem. You are packing for a vacation on the sea side and you are going 
    to carry only one bag with capacity S (1 <= S <= 2000). You also have N (1<= N <= 2000) items 
    that you might want to take with you to the sea side. Unfortunately you can not fit all of them
    in the knapsack so you will have to choose. For each item you are given its size and its value.
    You want to maximize the total value of all the items you are going to bring. What is this
    maximum total value?

    Input
    On the first line you are given S and N. N lines follow with two integers on each line describing
    one of your items. The first number is the size of the item and the next is the value of the item.

    Output
    You should output a single integer on one like - the total maximum value from the best choice of 
    items for your trip.

    Example
        Input:     Output:
        4 5         13
        1 8
        2 4
        3 0
        2 5
        2 3

    !!! for some reason gives TLE (didn't use the sorting part then)
        Time limit        : 1000 ms
        Mem limit         : 1572864 kB
        Code length Limit : 50000 B
        OS                : Linux 

        Python 3 (PyPy 3.6.1)
"""
from typing import List, Tuple, Dict
from functools import cmp_to_key


def sortLogic(item1 : Tuple[int, int], item2 : Tuple[int, int]) -> bool:
    """
        Logic : I1V/I1S > I2V/I2S => I1V*I2S > I2V*I1S
        
        *** This implementation returns
            -1 if item1 is "greater" than item2,
            1 if item2 is "greater" than item1,
            0 if they are equal. 
        
            This is what the sorted() function expects 
            from the key argument.
    """

    itemOneValue : int = item1[1]; itemOneSize : int = item1[0]
    itemTwoValue : int = item2[1]; itemTwoSize : int = item2[0]

    if itemOneValue * itemTwoSize > itemTwoValue * itemOneSize:
        return -1
    elif itemOneValue * itemTwoSize < itemTwoValue * itemOneSize:
        return 1
    else:
        return 0

def getMaxValuePossible(cache : Dict[str, int], items : Tuple[Tuple[int, int]], cap : int, idx : int) -> int:
    key : str = f"{cap}_{idx}"

    if cap == 0 or idx >= len(items):
        return 0
    
    if cache.get(key, -1) != -1:
        return cache[key]

    itemValue : int = items[idx][1]; itemSize : int = items[idx][0]

    if itemSize <= cap:
        ifTake : int = itemValue + getMaxValuePossible(cache, items, cap-itemSize, idx+1)
        ifIgnr : int = getMaxValuePossible(cache, items, cap, idx+1)

        cache[key] = max(ifTake, ifIgnr)

    else:
        cache[key] = getMaxValuePossible(cache, items, cap, idx+1)

    return cache[key]


if __name__ == "__main__":
    S : int; N : int; _ : int
    ITEMS : Tuple[Tuple[int, int]]
    CACHE : Dict[str, int] = dict({})

    S, N = tuple(map(int, input().split()))

    #We do not need sorting in this case
    #ITEMS = sorted(tuple((tuple(map(int, input().split())) for _ in range(N))), key=cmp_to_key(sortLogic))
    #print(ITEMS)
    
    ITEMS = tuple((tuple(map(int, input().split())) for _ in range(N)))
    print(getMaxValuePossible(CACHE, ITEMS, S, 0))