#include <bits/stdc++.h>
using namespace std;

/*
    *** Given a sorted array of non-negative integers, find
    the smallest missing non-negative integer using binary search.

    let's assume the array,

        idx: | 0 | 1 | 2 | 3 | 4 | 5 |
        ------------------------------
        ele: | 0 | 1 | 3 | 5 | 7 | 8 |

    then we can see that the missing elements of the sequence (0-8) are,
                        
                        2, 4, 6      (lowest: 2)

    let's see what kind of logic we can use to find 2.
    before that, consider what do we know,

        i)   the given array is sorted in asending order

        ii)  the elements of the array will be in order to [0, +∞)

        iii) the indices of an array is an sorted asending order sequence
            of [0, n-1], where n is the size of the array size

    Notice something ?
    
    Yes ! the indices of the given array will always be an correct sub-sequence
    of [0, +∞) sequence.

    So, following our analysis, if we check from index 0 to n-1, that the element
    of that particular index is same as the index or not.

        if not same as the index, we can say that the lowest non-negative element
        which is missing from the sequcence is the index itslef.

    To do so, we have to search the array and check the index-element pair untill we
    encounter the specific situation.

    We can use any searching technique to achieve the results.

    when using linear search,
        to make sure that mention above is correct, we should check the 
        index-element in asending order *(must) mean 0 to n-1 and when we
        encounter the mismatch for 1st time we should break/stop the search.

    using linear search it is easy to implement but the cost is O(N).
    In order to reduce the cost we can use a more efficient algo like
    binary search which has a cost of O(logN). [O(N) > O(logN)]

    Assuming that we have clear understanding of the standered binary search,
    let's see how we can customize it so that checking of index-element pair
    happens in a way that the lowest index get the most priority because of
    the reason explained above.

    We know that the binary search checks the element of the middle index and
    divide the array in 2 sub array every time.

    while the bineary search do that, it also have the access to the lowest index of
    the sub array, so we just have to check the lowest index value of the subarray
    instead of checking the mid index-element as your "new base case"

    If base case isn't met, then we have to performe the binary search again.
    but on what basics ??? mean on which sub array should we do binary search?

    The answer is, we will approch the problem like below,

        i|  if the mid index and element is same, then we will search for the
            index-element pair on the right sub-array (as array is sorted in asending order)

        ii| else it means we have encounter an missing element of the sequence, but
            we can't ignore the possiblity that it isn't the lowest/smallest number of the
            sequence (because the number is on mid index not on lowest index of the sub array),
            so we will continue the search on the left sub array.

        iv| if the new base case never met and the normal base case of the binary search is met,
        then we will return the current upper-index + 1 as result,

        think like that if all elements exists on the array of sequence [0, n-1] then
        'n' is the number which is missing from the sequence [0, +∞).
*/


int bs(int arr[], int lb, int ub){

    int mid = (lb + ub)/2;

    printf("lb: %d, ub:%d, mid:%d, arr[mid]:%d\n", lb, ub, mid, arr[mid]);

    if (lb > ub){
        return ub+1;
    }

    if (arr[lb] != lb){
        return lb;
    }

    if (arr[mid] == mid){
        return bs(arr, mid+1, ub);
    }

    return bs(arr, lb, mid);
}

int main(){
    int arr[] = {0, 1, 2, 3, 5, 7, 8};
    //int arr[] = {0, 1, 3, 4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", bs(arr, 0, arr_size-1));

    return 0;
}