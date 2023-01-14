/*
11.	Program that will take the final score of a student in a particular subject as input and find his/her grade. 

Marks	Letter Grade	Marks	Letter Grade	Marks	        Letter Grade
90-100	          A 	70-73	          C+ 	Less than 55	        F 
86-89	          A- 	66-69	          C 		
82-85	          B+ 	62-65	          C-		
78-81	          B 	58-61	          D+ 		
74-77	          B- 	55-57	          D 		 


Sample input	Sample output
91.5	            Grade: A
50	                Grade: F
*/
#include <stdio.h>

int main(){
    int marks;
    scanf("%d", &marks);

    if (marks >= 90 && marks <= 100) printf("Grade: A");
    else if (marks >= 86 && marks <= 89) printf("Grade: A-");
    else if (marks >= 82 && marks <= 85) printf("Grade: B+");
    else if (marks >= 78 && marks <= 81) printf("Grade: B");
    else if (marks >= 74 && marks <= 77) printf("Grade: B-");
    else if (marks >= 70 && marks <= 73) printf("Grade: C+");
    else if (marks >= 66 && marks <= 69) printf("Grade: C");
    else if (marks >= 62 && marks <= 65) printf("Grade: C-");
    else if (marks >= 58 && marks <= 61) printf("Grade: D+");
    else if (marks >= 55 && marks <= 57) printf("Grade: D");
    else if (marks < 55) printf("Grade: F");
    else printf("Invalid Marks");


    return 0;
}