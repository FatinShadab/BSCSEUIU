#include <stdio.h>

const int N = 51;

int main(){
    int n, t;

    scanf("%d %d", &n, &t);
    getchar();
    
    char studentQueue[N];
    gets(studentQueue);

    while (t--){
        int boyMoved = -1;
        for (int i=0; i<n; i++){
            switch (studentQueue[i]){
                case 'B':
                if (i != boyMoved){
                    if (i+1 < n){
                        switch (studentQueue[i+1]){
                            case 'G':
                                studentQueue[i] = 'G';
                                studentQueue[i+1] = 'B';
                                boyMoved = i+1;
                                break;
                        }
                    }
                }
                break;
            }
        }
    }

    puts(studentQueue);

    return 0;
}