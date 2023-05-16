/***********************************************************************
 * You have been given the task of writing a program in C
 * that reads a list of names and ages from a text file and 
 * stores them in a struct called "Person." The program should
 * then sort the array of structs in ascending order by age and
 * d write the sorted list of names and ages back to another text file.
 * 
 * input.txt                        output.txt
 * 
 * John 35                          Mary 25
 * Mary 25                          Sue 30
 * James 45                         John 35
 * Sue 30                           James 45
 * *********************************************************************/                                                                  
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int age;
    char name[10];
}Person;

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(Person arr[], int n){
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].age > arr[j + 1].age)
                swap(&arr[j].age, &arr[j + 1].age);

    return;
}

int get_file_line_num(){
    int age;
    int line = 0;
    char name[10];

    FILE *srcFptr = fopen("input.txt", "r");

    // to get the file line number
    while (!feof(srcFptr)){
        fscanf(srcFptr, "%s %d", name, &age);
        line++;
    }

    fclose(srcFptr);

    return line;
}

int main(){
    int n = get_file_line_num();
    Person persons[n];

    FILE *srcFptr = fopen("input.txt", "r");

    if (srcFptr == NULL){
        printf("Invalid File path !\n");
        exit(1);
    }

    int index = 0;
    while (!feof(srcFptr)){
        fscanf(srcFptr, "%s %d", persons[index].name, &persons[index].age);
        index++;
    }

    fclose(srcFptr);

    bubbleSort(persons, n);

    FILE *dstFptr = fopen("output.txt", "w");

    for (int idx = 0; idx < n; idx++){
        if (idx < n-1)
            fprintf(dstFptr, "%s %d\n", persons[idx].name, persons[idx].age);
        else
            fprintf(dstFptr, "%s %d", persons[idx].name, persons[idx].age);
    }

    fclose(dstFptr);

    return 0;
}