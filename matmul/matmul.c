#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//parameter
void matrixmultiply(int **matrix1, int **matrix2, int **result, int r1, int c2, int r2);

int main(){
    int r1,r2,c1,c2;
    int **matrix1, **matrix2, **result;
    FILE *fp1 , *fp2, *fp3;
    fp1 = fopen("Matrix1.txt","w");
    fp2 = fopen("Matrix2.txt","w");
    fp3 = fopen("Matrixmultiplied.txt","w");
    clock_t start,end;
    int i,j;
    start = clock();

    //taking input
    printf("Enter the number of rows and columns in Matirx 1: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of rows and columns in Matirx 2: ");
    scanf("%d%d",&r2,&c2);
    if(r2!=c1){
        printf("Matrix cannot be multiplied");
    }
    else{
        //allocating the memory
        matrix1 = (int **)malloc(r1*sizeof(int *));
        for(i=0;i<r1;i++)
        matrix1[i] = (int *)malloc(c1*sizeof(int));

        matrix2 = (int **)malloc(r2*sizeof(int *));
        for(i=0;i<r2;i++)
        matrix2[i] = (int *)malloc(c2*sizeof(int));

        result = (int **)malloc(r1*sizeof(int *));
        for(i=0;i<r1;i++)
        result[i] = (int *)malloc(c2*sizeof(int));

        //inputing the elements
        srand(time(0));
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                matrix1[i][j]=rand()%5;
            }
        }
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                matrix2[i][j]=rand()%5;
            }
        }

        //printing matrix1 and matrix2
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                fprintf(fp1,"%d",matrix1[i][j]);
            }
            fprintf(fp1,"\n");
        }
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                fprintf(fp2,"%d",matrix2[i][j]);
            }
            fprintf(fp2,"\n");
        }

        //calling the matrixmultiplied function
        matrixmultiply(matrix1,matrix2,result,r1,c2,r2);

        //printing the resultant matrix
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                fprintf(fp3,"%d",result[i][j]);
            }
            fprintf(fp3,"\n");
        }
        end = clock();
        printf("\n time taken is %1.10fs.\n",(float)((end-start)*1.0/CLOCKS_PER_SEC));

        // dealloacating the matrices
        free(matrix1);
        free(matrix2);
        free(result);
        return 0;
    }
}
//fucntion to make matrix multiplied
void matrixmultiply(int **matrix1, int **matrix2, int **result, int r1, int c2, int r2){
    int i,j,k;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            result[i][j]=0;
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<r2;k++){
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}