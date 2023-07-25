#include <bits/stdc++.h>
using namespace std;

/*
    Implement the binary search algorithm to find
    the square root of a non-negative integer within
    a range of 0-100

    input  : 25
    output : 5
*/

int bs(int lb, int ub, int target){
    if (lb > ub) return -1;

    int mid = (lb + ub)/2;

    if (mid*mid == target) return mid;
    if (mid*mid > target) return bs(lb, mid-1, target);

    return bs(mid+1, ub, target);
}

int main(){
    int sqr, sqrt;

    input:
        printf("Enter a perfect square value in range [0, 100] : ");
        scanf("%d", &sqr);

    if (sqr > 100){
        printf("Value (%d) out of range [0, 100]! \n", sqr);
        goto input;
    }

    sqrt = bs(0, 100, sqr);

    if (sqrt == -1)
        printf("Not a perfect square %d !!\n", sqr);
    else
        printf("Sqrt of %d is : %d\n", sqr, sqrt);

    return 0;
}