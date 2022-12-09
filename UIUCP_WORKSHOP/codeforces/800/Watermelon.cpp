#include <bits/stdc++.h>

using namespace std;

int main(){

    int watermelon_weight;
    scanf("%d", &watermelon_weight);

    if (watermelon_weight%2 == 0 && watermelon_weight != 2){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}