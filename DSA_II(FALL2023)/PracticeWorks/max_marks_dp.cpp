/*
    Jam is taking an exam with N questions. Each question has a certain number of marks and takes a 
    specific amount of time. The total time for the exam is T. Additionally, Jam can select one
    question and double the marks awarded for it.

    Input:
        The first line contains an integer N (number of questions).
        The second line contains an integer T (total exam time).
        The third line contains N space-separated integers representing the marks for each question: m1, m2, ..., mn.
        The fourth line contains N space-separated integers representing the time for each question: t1, t2, ..., tn.
    
    Output:
        Output the maximum marks Jam can achieve.

    Solution Approach:
        Brute Force with Dynamic Programming (DP):
            Without the bonus, this is a classical knapsack problem where 
            we try to maximize the marks Jam can get under a time constraint.
            The twist here is that Jam can double the marks for one question.
            So, for each question, we try doubling its value and solve the problem,
            considering that question has double marks.
        
        Steps to solve:
        1. We first calculate the maximum marks Jam can get without doubling any marks using dynamic programming.
        2. For each question, we check how much we can gain if we double its marks and recalculate the maximum possible marks.
*/

#include <bits/stdc++.h>
using namespace std;

// DP memoization table to store results for each state
vector<vector<int>> dp;

// Recursive DP function
int maxMarksRec(vector<int>& marks, vector<int>& time, int idx, int remainingTime) {
    if (idx == 0 || remainingTime == 0) {
        return 0;
    }
    
    if (dp[idx][remainingTime] != -1) {
        return dp[idx][remainingTime];
    }

    // Case 1: We skip the current question
    int skip = maxMarksRec(marks, time, idx - 1, remainingTime);

    // Case 2: We take the current question (if time allows)
    int take = 0;
    if (time[idx - 1] <= remainingTime) {
        take = marks[idx - 1] + maxMarksRec(marks, time, idx - 1, remainingTime - time[idx - 1]);
    }

    // Store the maximum of taking or skipping
    return dp[idx][remainingTime] = max(skip, take);
}

// Wrapper function to calculate the maximum marks with the bonus option
int maximumMarksWithBonus(vector<int>& marks, vector<int>& time, int N, int T) {
    // Calculate the maximum marks without applying any bonus using recursive DP
    dp = vector<vector<int>>(N + 1, vector<int>(T + 1, -1));
    int maxMarksWithoutBonus = maxMarksRec(marks, time, N, T);

    // Now, consider the bonus - we double the marks of one question and see if it gives a better result
    int maxMarksWithBonus = maxMarksWithoutBonus;

    for (int i = 0; i < N; i++) {
        // Reset DP table to recalculate with bonus applied to the i-th question
        dp = vector<vector<int>>(N + 1, vector<int>(T + 1, -1));

        // Double the marks for question i
        marks[i] *= 2;

        // Recalculate the maximum marks with the i-th question's marks doubled
        maxMarksWithBonus = max(maxMarksWithBonus, maxMarksRec(marks, time, N, T));

        // Restore the original marks for question i after testing the bonus
        marks[i] /= 2;
    }

    return maxMarksWithBonus;
}

int main() {
    int N, T;

    // Input number of questions and total time available
    cin >> N >> T;

    vector<int> marks(N), time(N);

    // Input the marks for each question
    for (int i = 0; i < N; i++) {
        cin >> marks[i];
    }

    // Input the time required for each question
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    // Output the maximum marks Jam can achieve
    cout << maximumMarksWithBonus(marks, time, N, T) << endl;

    return 0;
}
