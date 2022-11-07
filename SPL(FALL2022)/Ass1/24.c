/*
Write a program (WAP) that will find the grade of N students.
For each student, it will take the marks of his/her the attendance
(on 5 marks), assignment (on 10 marks), class test (on 15 marks), midterm
(on 50 marks), term final (on 100 marks). Then based on the tables shown below,
the program will output his grade.

Attendance (A)	    - 5%
Assignments (HW)	- 10%
Class Tests  (CT)	- 15%
Midterm (MT)	    - 30%
Final (TF)	        - 40%

Marks	Letter Grade	Marks	Letter Grade	Marks	     Letter Grade
90-100	 A 	            70-73	C+ 	            Less than 55	F 
86-89	 A- 	        66-69	C 		
82-85	 B+ 	        62-65	C-		
78-81	 B 	            58-61	D+ 		
74-77	 B- 	        55-57	D 		 
*/
#include <stdio.h>

int main(){
    int students;
    scanf("%d", &students);

    for (int student=1; student <= students; student++){
        float A, HW, CT, MT, TF;
        scanf("%f %f %f %f %f", &A, &HW, &CT, &MT, &TF);

        float marks = (A + HW + CT + MT*(30.0/50) + TF*(40.0/100));

        if (marks >= 90 && marks <= 100) printf("Student %d: A\n", student);
        else if (marks >= 86 && marks <= 89) printf("Student %d: A-\n", student);
        else if (marks >= 82 && marks <= 85) printf("Student %d: B+\n", student);
        else if (marks >= 78 && marks <= 81) printf("Student %d: B\n", student);
        else if (marks >= 74 && marks <= 77) printf("Student %d: B-\n", student);
        else if (marks >= 70 && marks <= 73) printf("Student %d: C+\n", student);
        else if (marks >= 66 && marks <= 69) printf("Student %d: C\n", student);
        else if (marks >= 62 && marks <= 65) printf("Student %d: C-\n", student);
        else if (marks >= 58 && marks <= 61) printf("Student %d: D+\n", student);
        else if (marks >= 55 && marks <= 57) printf("Student %d: D\n", student);
        else if (marks < 55) printf("Student %d: F\n", student);

    }

    return 0;
}