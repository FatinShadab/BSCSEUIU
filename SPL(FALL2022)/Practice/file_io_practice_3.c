/*****
 * You have been given the task of writing a program in C that reads
 * a text file and counts the number of characters, words, and lines
 * in the file. The program should then write the counts to a new 
 * text file, with each count on a separate line
 * 
 * ----------------------------------------------------------------------------------------
 *                    input.txt               |                 output.txt
 * ----------------------------------------------------------------------------------------
 * This is a sample text file.                |Characters: 88
 * It has three lines.                        |Words: 18
 * Each line has a different number of words. |Lines: 3
 * ----------------------------------------------------------------------------------------
 * ******/
#include <stdio.h>
#include <stdlib.h>

int count_word(char line[]){
    char last_char;
    int idx = 0;
    int count = 0;

    //printf("\n");
    while (line[idx++] != '\0'){
        //printf("%c", line[idx-1]);
        if (line[idx-1] == ' '){
            //printf("\n");
            count++;
        }
        last_char = line[idx-1];
    }
    
    if (last_char != ' '){
        count++;
    }

    return count;
}

int count_char(char line[]){
    int idx = 0;
    int count = 0;

    while (line[idx++] != '\0'){
        if (line[idx-1] != '\n'){
            count++;
        }
    };

    return count;
}

int main(){
    int chrs = 0;
    int lines = 0;
    int words = 0;
    char line[1000000];
    
    FILE *srcFptr = fopen("input4.txt", "r");

    if (srcFptr == NULL){
        printf("Invalid File path !\n");
        exit(1);
    }

    while (!feof(srcFptr)){
        fgets(line, 1000000, srcFptr);

        //printf("%s", line);

        words += count_word(line);
        chrs += count_char(line);
        lines++;
    }

    fclose(srcFptr);

    FILE *dstFptr = fopen("output4.txt", "w");

    //printf("\n%d %d %d", chrs, words, lines);

    fprintf(dstFptr, "Characters: %d\nWords: %d\nLines: %d\n", chrs, words, lines);

    fclose(dstFptr);

    return 0;
}