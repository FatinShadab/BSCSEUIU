#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int upvote_server = 0;
        // No need to keep track of downvote. without it the problem can be solved. 
        int downvote_server = 0;
        
        int reviewers;
        scanf("%d", &reviewers);
        
        while (reviewers--){
            int review;
            scanf("%d", &review);

            switch (review){
                case 1:
                    upvote_server++;
                    break;
                case 2:
                    downvote_server++;
                    break;
                case 3:
                    upvote_server++;
                    break;
            }
        }

        printf("%d\n", upvote_server);
    }

    return 0;
}