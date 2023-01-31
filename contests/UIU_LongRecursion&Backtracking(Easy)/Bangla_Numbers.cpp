#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int MAXLIMIT = 10000000;

void printBanglaNumbers(int number, int unit){

    if (unit == 10){
        if (number)
            printf("%d", number);
        return;
    }

    printf("%d", number/unit);
    
    switch (unit){
        case 100:
            printf(" shata ");
            break;
        case 1000:
            printf(" hajar ");
            break;
        case 100000:
            printf(" lakh ");
            break;
    }
    
    printBanglaNumbers(number%unit, (unit <= 1000) ? unit/10:unit/100);
}

int main(){
    auto start = high_resolution_clock::now();
    unsigned long long int num;
    
    while (scanf("%llu", &num)){
        stack <int> nums;

        do{
            nums.push(num%MAXLIMIT);
            
            num /= MAXLIMIT;
        }
        while (num > MAXLIMIT);

        if (num)
            nums.push(num);

        while (!nums.empty()){
            int startUnit;
            int num = nums.top();

            switch (num){
                case 1 ... 99:
                    startUnit = 10;
                    break;
                case 100 ... 999:
                    startUnit = 100;
                    break;
                case 1000 ... 99999:
                    startUnit = 1000;
                    break;
                case 100000 ... 9999999:
                    startUnit = 100000;
                    break;
            }

            printBanglaNumbers(num, startUnit);

            nums.pop();

            if (nums.size() > 0)
                printf(" kuti ");
        }

        puts("");
        break;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<duration.count()<< " microseconds";

    return 0;
}