/***********
 * You have been given the task of writing a program in C that reads a list of student names and id
 * from one text file and a list of student id and grades from another text file. The program should
 * then combine the information from both files and write the combined list of student names, IDs,
 * and grades to a new text file, with the names and IDs in the first two columns and the grades in
 * the third column.
 * 
 * ---------------------------------------------------------------------------------------------------
 *                                         Sample Input
 *                 names.txt                    |                   grades.txt
 * --------------------------------------------------------------------------------------------------- 
 * John 3                                       | 3 80
 * Mary 2                                       | 2 90
 * James 1                                      | 1 70
 * Yeasir 4                                     | 4 80
 * ---------------------------------------------------------------------------------------------------
 * 
 * ---------------------------------------------------------------------------------------------------
 *                                          Sample Output
 * output.txt
 * ---------------------------------------------------------------------------------------------------
 * John 3 80
 * Mary 2 90
 * James 1 70
 * Yeasir 4 80
 * ---------------------------------------------------------------------------------------------------
 *                                                                                         **********/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[10];
    int id, grade;

    FILE *srcFptr_1 = fopen("names.txt", "r");
    FILE *srcFptr_2 = fopen("greade.txt", "r");

    FILE *dstFptr = fopen("output3.txt", "w");

    if (srcFptr_1 == NULL || srcFptr_2 == NULL){
        printf("Invalid File path !\n");
        exit(1);
    }

    while (!feof(srcFptr_1)){
        fscanf(srcFptr_1, "%s %d", name, &id);
        fscanf(srcFptr_2, "%d %d", &id, &grade);

        fprintf(dstFptr, "%s %d %d\n", name, id, grade);
    }

    fclose(srcFptr_1);
    fclose(srcFptr_2);
    fclose(dstFptr);

    return 0;
}