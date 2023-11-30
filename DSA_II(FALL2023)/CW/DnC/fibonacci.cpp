/*
[~] In mathematics, the Fibonacci sequence is a sequence in which each number
is the sum of the two preceding ones.

[~] Means's,
	if the value of the 0'th term is    ->   0
	and the value of the 1'th term is   ->   1
	then the value of the 2'th term is  -> value of 0'th term + value of 1'th term
										->   (0 + 1)
										->   1

	So, we can formulate that, for the value of n'th term, 

		valueOf(n'th) = valueOf((n-1)'th) + valueOf((n-2)'th)

	Resulting a series like below,

[~] Fibonacci:	0, 1, 1, 2, 3, 5, 8, 13, 21
				^  ^  ^  ^  ^  ^  ^  ^   ^
				|  |  |  |  |  |  |  |   |
0'th term ->	0  |  |  |  |  |  |  |   |
				   |  |  |  |  |  |  |   |
1'th term ->	   1  |  |  |  |  |  |   |
				      |  |  |  |  |  |   |
2'th term ->	    (0+1)|  |  |  |  |   |
						 |  |  |  |  |   |
3'th term ->		   (1+1)|  |  |  |   |
					        |  |  |  |   |
4'th term ->			  (1+2)|  |  |   |
						       |  |  |   |
5'th term ->                 (2+3)|  |   |
							 	  |  |   |
6'th term ->					(3+5)|   |
									 |   |
7'th term ->					   (5+8) |
								         |
8'th term ->						   (8+13)

[~] Now if we observe the formula and the simulation for the problem of
calculating the value of n'th term of fibonacci series, we can notice that,

	we are solving the problem by calculating the value of the (n-1)'th and 
(n-2)'th term. Or we can say that we are dividing the problem in two parts
to solve it. [*** DIVIDE *** !!!]

	In programming we know a approach called, 'Divide and Conquer' (DnC)
in which we divide the problem in subproblems and use the solution of those
subproblems to solve our problem. So, let's try to solve the fibonacci problem
using the 'DnC' approach.

[~] Note: To be a DnC solve the solve must have three (3) part's, which are,

		1| Divide  part // Divide the problem in subproblems
		2| Conquer part // when reach to the easiest sub-problem to solve, solve it.
		3| Combine part // Use the solutions of the sub-problems to solve the initial problem. 


[~] In my opinion to implement a 'DnC' solution, 'Recursion' is the easiest method/technique.
As per my understanding, how to relate the 3 parts of the 'Dnc' approach in a recursive function
is shown below,

						*** [Recustion VS DnC Mapping] ***
```
$function_return_type $function_name($function_arguements) {
	
	//// Recursive Base Case : 'DnC' Conquer Part
	if ($base_case's) {
		return $solve // easiest problem's solve
	}

	//// Recursive logic and function call : 'DnC' Divide Part
	$recursive_logic
	$recursive_call

	//// Non-Base case solution return and logic : 'DnC' Combine part
	return $solve
}
```
*/

#include <bits/stdc++.h>
#define llint long long int

using namespace std;

/*
	Recursive function for fibonacci problem : 'DnC' implementation
	Assuming the value of the 0'th term is 0 and the value of the
	1'th term is 1 

	@param n (int) : the term to get value of. 

	@return the value (long long int) of n'th term of fibonacci series 

	@note returns -1 for invalid 'n'
*/
llint nthFibonacci(int n) {
	// checking for invalid input 
	if (n < 0) return (llint) -1;

	// base case's  [the conqure part]
	if (n == 0 || n == 1) return (llint) n;

	// recursive logic and function call [the divide part]
	llint n_minus_one_term_value = nthFibonacci(n - 1);
	llint n_minus_two_term_value = nthFibonacci(n - 2);

	// non-base case solution logic and return [the combine part]
	return n_minus_one_term_value + n_minus_two_term_value;
}


/*
	Driver function of the code
*/
int main() {
	int n;

	printf("Enter the term 'n' to get the n'th term of fibonacci [0th -> 0, 1th -> 1] : ");
	scanf("%d", &n);

	printf("The %d'th term of fibonacci series : %lld\n", n, nthFibonacci(n));

	return 0;
}
