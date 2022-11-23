#include <stdio.h>
/*
Task:
    create 3 sequences like below,
        sequence 1: 1^2, 2^2, 3^2 ... 27^2                         # seq_1
        sequence 2: 1^3, 2^3, 3^3 ... 27^3                         # seq_2
        sequence 3: seq_2[0] - seq_1[0], ... seq_2[27] - seq_1[27] # seq_3

    store each sequence in a 3d where (i:3, j:3, k:3 resulting to arr[3][3][3]) array and print them. 
*/
struct CONTAINER{
    int arr[3][3][3];
};

void print(struct CONTAINER con, int d1, int d2, int d3){
    for (int i=0; i<d1; i++){
        for (int j=0; j<d2; j++){
            for (int k=0; k<d3; k++){
                printf("%d", con.arr[i][j][k]);
                if (k < 2){
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
};

struct CONTAINER populate_series(struct CONTAINER series[], int d1, int d2, int d3, int con_id){
    
    struct CONTAINER con = series[con_id];
    
    if (con_id == 0){
        int num = 1;
        for (int i=0; i<d1; i++){
            for (int j=0; j<d2; j++){
                for (int k=0; k<d3; k++){
                    con.arr[i][j][k] = (num*num);
                    num++;
                }
            }
        }
    }else if (con_id == 1){
        int num = 1;
        for (int i=0; i<d1; i++){
            for (int j=0; j<d2; j++){
                for (int k=0; k<d3; k++){
                    con.arr[i][j][k] = (num*num*num);
                    num++;
                }
            }
        }
    }else if (con_id == 2){
        for (int i=0; i<d1; i++){
            for (int j=0; j<d2; j++){
                for (int k=0; k<d3; k++){
                    con.arr[i][j][k] = series[1].arr[i][j][k] - series[0].arr[i][j][k];
                }
            }
        }
    }

    return con;
}

int main(){

    struct CONTAINER series[3];

    // prints the output
    printf("The series :\n");
    for (int x=0; x<3; x++){
        printf("series : %d \n", x+1);
        series[x] = populate_series(series, 3, 3, 3, x);
        print(series[x], 3, 3, 3);
    }

    return 0;
}