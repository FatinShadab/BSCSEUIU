// PB LINK : https://codeforces.com/problemset/problem/677/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int number_of_persons, fence_height, person_height;
    int road_minimum_width_needed = 0;

    scanf("%d %d", &number_of_persons, &fence_height);

    for (int person=1; person <= number_of_persons; person++){
        scanf("%d", &person_height);
        road_minimum_width_needed += (person_height > fence_height) ? 2:1;
    }

    printf("%d\n", road_minimum_width_needed);

    return 0;
}