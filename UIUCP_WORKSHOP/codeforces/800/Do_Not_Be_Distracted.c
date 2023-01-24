#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int n;
        scanf("%d", &n);
        getchar();

        if (n == 1){
            char temp;
            scanf("%c", &temp);
            printf("YES\n");
        }
        else if (n==2){
            char temp[3];
            scanf("%s", temp);
            printf("YES\n");
        }
        else{
            int distracted = 0;
            char str[n+1];
            scanf("%s", str);

            for (int i=0; i<n; i++){
                char task = str[i];
                
                int in_sequence = 1;
                for (int j=i+1; j<n; j++){
                    if (str[j] == str[i]){
                        if (!in_sequence){
                            distracted = 1;
                            break;
                        }
                    }
                    else{
                        in_sequence = 0;
                    }
                }

                if (distracted){
                    printf("NO\n");
                    break;
                }
            }

            if (!distracted)
                printf("YES\n");
        }
    }

    return 0;
}