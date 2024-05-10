/*
Write a C program that performs the following tasks:

    1) Read the following “in.txt” file that has integer numbers on separate lines.
    Find the maximum value of those numbers.

    2) Create a new file “out.txt” and print the maximum number into the new file.

    3) Remember to display appropriate messages if the input or the output file
    couldn’t be opened.
*/
#include <stdio.h>
#include <limits.h>

int main() {
    FILE *inputFile, *outputFile;
    int num, max = INT_MIN;

    // Open input file
    inputFile = fopen("in.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read numbers from input file and find maximum
    while (fscanf(inputFile, "%d", &num) != EOF) {
        if (num > max) {
            max = num;
        }
    }

    // Close input file
    fclose(inputFile);

    // Open output file
    outputFile = fopen("out.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write maximum number to output file
    fprintf(outputFile, "%d", max);

    // Close output file
    fclose(outputFile);

    printf("Maximum number written to out.txt: %d\n", max);

    return 0;
}
