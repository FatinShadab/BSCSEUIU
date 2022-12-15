#include <stdio.h>
#include <string.h>

int main(){
    int produce_output = 0;
    char validInputs[4] = {'H', 'Q', '9'};
    
    char userInput[101];
    scanf("%s", userInput);

    for (int idx=0; idx < strlen(userInput); idx++){
        for (int _idx=0; _idx < 3; _idx++){
            if (userInput[idx] == validInputs[_idx]){
                produce_output = 1;
                break;
            }
        }
        if (produce_output){
            break;
        }
    }

    printf((produce_output) ? "YES\n":"NO\n"); 

    return 0;
}