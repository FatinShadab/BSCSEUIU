#include <stdio.h>
#include <string.h>


int main(){
    int is_dangerous = 0;

    char str[101];
    scanf("%s", str);

    int str_len = strlen(str);

    int start_idx = 0;
    int end_idx = 6;

    while (end_idx < str_len){ 
        int inner_flag = 1;
        char player = str[start_idx];

        for (int idx=start_idx+1; idx <= end_idx; idx++){
            if (str[idx] != player){
                inner_flag = 0;
                break;
            }
        }

        if (inner_flag){
            is_dangerous = 1;
            break;
        }
        else{
            start_idx += 1;
            end_idx += 1;
        }
    }

    printf((is_dangerous) ? "YES\n":"NO\n");

    return 0;
}