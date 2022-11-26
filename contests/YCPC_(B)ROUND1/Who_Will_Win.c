#include <stdio.h>


int main() {

    int A, B; scanf("%d %d", &A, &B);
    
    if (A > B) printf("Argentina");
    else if (A < B) printf("Brazil");
    else printf("Draw");
        
    return 0;
}