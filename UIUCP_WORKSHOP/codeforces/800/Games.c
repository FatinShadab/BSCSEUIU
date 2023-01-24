#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int guest_uinform = 0;
    int teams[n][2];
    
    for (int i=0; i<n; i++){
        scanf("%d %d", &teams[i][0], &teams[i][1]);
    }

    for (int i=0; i<n; i++){
        int host_uniform = teams[i][0];
        for (int j=0; j<n; j++){
            if (host_uniform == teams[j][1] && i != j)
                guest_uinform++;
        }
    }

    printf("%d\n", guest_uinform);

    return 0;
}