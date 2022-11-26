#include <stdio.h>
#include <math.h>

int nextPower_2 ( unsigned  int  x){

    double nextnum = ceil  ( log2  x) ;

    double result = pow  (2.0  ,  nextnum) ;

    return  int ( result ) ;

}

int main(){
    int N;
    int testcase; scanf("%d", &testcase);

    while (testcase){
        scanf("%d", &N);
        int temp = N;
        while (((temp & (temp - 1)) != 0) || temp == 0){
            if (temp == 0 || temp == 1){
                temp = 1;
                break;
            }
            else{
                temp = nextPower_2(temp);
            }
        }
        printf("%d\n", temp);
        testcase--;
    }


    return 0;
}

/*
!!! TLE !!!
int main(){
    int N;
    int testcase; scanf("%d", &testcase);

    while (testcase){
        scanf("%d", &N);
        int temp = N;
        while (((temp & (temp - 1)) != 0) || temp == 0){
            if (temp == 0 || temp == 1){
                temp = 1;
                break;
            }
            else{
                if (temp % 2 == 0) temp += 2;
                else temp += 1;
            }
        }
        printf("%d\n", temp);
        testcase--;
    }


    return 0;
}
*/