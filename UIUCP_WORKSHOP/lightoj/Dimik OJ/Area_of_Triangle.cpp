#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){

    int testcase; cin>>testcase;

    while (testcase){

        int a, b, c;
        cin>>a>>b>>c;

        double semi_p = (a+b+c) / 2.0; 

        double area = semi_p*(semi_p - a)*(semi_p - b)*(semi_p - c);
        area = pow(area, 0.5);

        printf("Area = %.3lf\n", area);

        testcase--;
    }

    return 0;
}