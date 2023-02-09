#include <stdio.h>

int d, m, y;
int MaxDateOfMonths[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(){
    return ((y%400 == 0) || (y%4 == 0)) && (y%100 != 0);
}

int isValidDate(){
    int valid = 1;

    /*if (isLeapYear(y)){
        Months[1] = 28;
    }
    else{
        Months[1] = 29;
    }*/
    // same
    MaxDateOfMonths[1] = (isLeapYear(y)) ? 29:28;

    if (y < 0){
        valid = 0;
    }

    if (m < 1){
        valid  = 0;
    }

    if (m > 12){
        valid = 0;
    }

    if (d < 0 || d > MaxDateOfMonths[m-1]){
        valid = 0;
    }

    return valid;
}

void getNextDate(){

    int temp_date = d;
    int temp_month = m;
    int temp_year = y;

    temp_date += 1;
    // 31/12/2022
    // 1/1/2023
    if (temp_date > MaxDateOfMonths[temp_month-1]){
        
        temp_date %= MaxDateOfMonths[temp_month-1];
        temp_month += 1;

        if (temp_month > 12){
            temp_month %= 12;
            temp_year += 1;
        }
    }

    d = temp_date;
    m = temp_month;
    y = temp_year;

    return;
}

int main(){
    printf("Day : ");
    scanf("%d", &d);

    printf("Month : ");
    scanf("%d", &m);

    printf("Year : ");
    scanf("%d", &y);

    if (isValidDate()){
        printf("\n%d/%d/%d is a valid date.\n", d, m, y);
    }else{
        printf("\n%d/%d/%d is not a valid date.\n", d, m, y);
        return 0;
    }

    getNextDate();

    printf("\nNext date :\n\tDay :%d\n", d);
    printf("\tMonth : %d\n", m);
    printf("\tYear : %d\n", y);

    return 0;
}