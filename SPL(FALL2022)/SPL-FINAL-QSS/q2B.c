/*
Write a C program that takes a string from the keyboard. The program will count (case
insensitively) the number of different vowels and display the statistics as shown below.
                                                                                    [4]
Sample Input                                            Sample Output
---------------------------------------------------------------------------------------
Owls fly high above the clouds.     |A/a: 1
                                    |E/e: 2
                                    |I/i: 1
                                    |O/o: 3
                                    |U/u: 1

EXTRA: count all the alphabets  (case insenstively)
*/
#include <stdio.h>
#include <string.h>
#define max_len 10000

void countAlphabetFreqCaseInsensitive() {
    char str[max_len];
    int char_freq[91] = {0};
    int upper2lower_diff = 32;
    int char_freq_starting_idx = 65;
    
    fgets(str, max_len, stdin);

    for (int idx = 0; idx < strlen(str); idx++) {
        int char_ascii = str[idx];

        if (char_ascii > 90) {
            char_ascii -= upper2lower_diff;
            char_ascii %= 90;
        }

        char_freq[char_ascii] += 1;
    }

    for (int idx = char_freq_starting_idx; idx < 91; idx++) {
        if (char_freq[idx]) {
            printf("%c/%c: %d\n", idx, idx+upper2lower_diff, char_freq[idx]);
        }
    }

    return;
}

void countVowelCaseInsensitive() {
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    char str[max_len];

    fgets(str, max_len, stdin);

    for (int idx = 0; idx < strlen(str); idx++) {
        switch (str[idx]) {
            case 'a':
                case 'A':
                    a++; break;
            case 'e':
                case 'E':
                    e++; break;
            case 'i':
                case 'I':
                    i++; break;
            case 'o':
                case 'O':
                    o++; break;
            case 'u':
                case 'U':
                    u++; break;
        }
    }

    printf("A/a: %d\nE/e: %d\nI/i: %d\nO/o: %d\nU/u: %d\n", a, e, i, o, u);

    return;
}

int main() {
    
    countVowelCaseInsensitive();
    countAlphabetFreqCaseInsensitive();

    return 0;
}