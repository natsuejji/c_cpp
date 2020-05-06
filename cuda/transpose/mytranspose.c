#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void transpose(float *m,float *r, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            r[j*col+i] = m[i*row+j];
        }
    }
    printf("\n");
}

void intMatrixGen(float *mat, int row, int col){
    //設定seed
    unsigned seed;
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed); // 以時間序列當亂數種子

    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            mat[row*i+j] = (float) rand() / (RAND_MAX + 1.0);   
        }
    }
};

//印出矩陣
void printFloatMatrix(float *mat,int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%f ",mat[i*row+j]);
        }
        printf("\n");
    }
    printf("\n");
};

int main(){
    int row = 3;
    int col = 4;
    float *mat = (float*) malloc(sizeof(float)*row*col);
    float *r = (float*) malloc(sizeof(float)*row*col);

    if(mat == NULL){
        printf("Memory allocation falied!\n");
        return 0;
    }else{
        printf("Memory allocation seccess!\n");
    }

    intMatrixGen(mat, row, col);
    printFloatMatrix(mat, row, col);
    transpose(mat,r,row,col);
    printFloatMatrix(r, col, row);
    return 0;
}