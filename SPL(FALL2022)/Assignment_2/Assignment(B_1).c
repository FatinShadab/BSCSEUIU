/*
Name : Md. Fatin Shadab Turja
Id   : 011 222 004
Sec  : B
*/

#include <stdio.h>

int M, N;

void preProcess(int matrix[M][N], int aux[M][N]);

int isVaildQuery(int tli, int tlj, int rbi, int rbj);

int getSubMatrixSum(int aux[M][N], int tli, int tlj, int rbi, int rbj);

int main(){
    int terminate = 0;
    int qRes = 0;
    int tlrow, tlcol, rbrow, rbcol;
    
    printf("Enter the matrix row and column value space seperated : ");
    scanf("%d %d", &M, &N);

    puts("Enter the matrix elements(int) :");
    int matrix[M][N];
    for (int row=0, col=0; row<M; (col < N) ? scanf("%d", &matrix[row][col++]):printf("",row++, col-=N));

    int aux[M][N];
    preProcess(matrix, aux);

    puts("Enter the queries (enter -1 -1 -1 -1 to terminate)");
    while (!terminate){

        puts("\nvalid: top right row & col followed by bottom right row & col index : ");
        scanf("%d %d %d %d", &tlrow, &tlcol, &rbrow, &rbcol);
        
        terminate = (tlrow + tlcol + rbrow + rbcol == -4) ? 1:0;
        if (terminate) break;

        if ((tlrow == rbrow) && (tlcol == rbcol) && ((tlrow >= 0) && (tlcol >= 0) && (rbrow >= 0) && (rbcol >= 0))){
            qRes = matrix[tlrow][tlcol];
        }
        else{
            int inner_flag = 0;
            while(!isVaildQuery(tlrow, tlcol, rbrow, rbcol)){

                puts("\nInvalid query !!");
                puts("valid: top right row & col followed by bottom right row & col index: ");

                scanf("%d %d %d %d", &tlrow, &tlcol, &rbrow, &rbcol);
                
                terminate = (tlrow + tlcol + rbrow + rbcol == -4) ? 1:0;
                if (terminate) break;

                if ((tlrow == rbrow) && (tlcol == rbcol) && ((tlrow >= 0) && (tlcol >= 0) && (rbrow >= 0) && (rbcol >= 0))){
                    inner_flag = 1;
                    break;
                }
            }

            qRes = (inner_flag) ? matrix[tlrow][tlcol]:getSubMatrixSum(aux, tlrow, tlcol, rbrow, rbcol);
        }

        if (!terminate)
            printf("\nSum : %d\n", qRes);
    }

    return 0;
}

void preProcess(int matrix[M][N], int aux[M][N]){

   for (int col=0; col<N; col++)
      aux[0][col] = matrix[0][col];
 

   for (int row=1; row<M; row++)
      for (int col=0; col<N; col++)
         aux[row][col] = matrix[row][col] + aux[row-1][col];
 

   for (int row=0; row<M; row++)
      for (int col=1; col<N; col++)
         aux[row][col] += aux[row][col-1];

    return;
}

int isVaildQuery(int tli, int tlj, int rbi, int rbj){
    return ((tli + tlj) <= (rbi+rbj) && (tlj < rbj) && (tli >= 0) && (tlj >= 0) && (rbi >= 0) && (rbj >= 0)) ? 1:0;
}

int getSubMatrixSum(int aux[M][N], int tli, int tlj, int rbi, int rbj){
    
    int res = aux[rbi][rbj];
 
    if (tli > 0)
       res = res - aux[tli-1][rbj];

    if (tlj > 0)
       res = res - aux[rbi][tlj-1];
 
    if (tli > 0 && tlj > 0)
       res = res + aux[tli-1][tlj-1];
 
    return res;
}