#include <bits/stdc++.h>
using namespace std;

/*
    given a number 'n' find out if the sqrt of n is a
    whole number. if it is a integer (whole number)
    then print the sqrt of n.
*/

int bs(int target, int lb, int ub){
    if (lb > ub) return -1;

    int mid = (lb + ub)/2;
    int check = mid * mid;

    cout<< "\tChecking " << target << ", " << mid << "\n";
    
    if (target == check) return mid;
    if (target > check) return bs(target, mid+1, ub);
    
    return bs(target, lb, mid-1);
}

int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int int_sqrt = bs(n, 1, n);

    if (int_sqrt == -1){
        cout << "The sqrt of " << n << " is not an integer\n";
    }else{
        cout << "The sqrt of " << n << " is -> " << int_sqrt << "\n";
    }

    return 0;
}