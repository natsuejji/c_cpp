#include "stdio.h"
#include "stdlib.h"
#include "time.h"

__global__ void matMultiply_Gpu(int *a, int *b, int *c, int width){
    int row = threadIdx.x;
    int col = threadIdx.y;
    int partial_ans = 0;
    if(row < width && col < width){
        for(int n=0; n< width; n++){
            //sigma 0 to n > c(i,j) = a[i,n]*b[n,j];
            partial_ans = a[row*width+n] * b[n*width+col];
            c[row*width+col] += partial_ans;
        }
    }
}

//隨機產生矩陣
void intMatrixGen(int *mat, int length, char type){
    int i,j;
    for(i=0;i<length;i++){
        for(j=0;j<length;j++){
            switch(type){
                case 'r':
                    mat[i*length+j] = (rand() % 20)+1;    
                    break;
                case 0:
                    mat[i*length+j] = 0;
                    break;
                default:
                    mat[i*length+j] = 0;
            }
        }
    }
};



//印出矩陣
void printIntMatrix(int *mat,int length){
    int i,j;

    for(i=0;i<length;i++){
        for(j=0;j<length;j++){

            printf("%d ",mat[i*length+j]);
        }
        printf("\n");
    }

    printf("\n");
};

void matMultiply_Cpu(int *a, int *b, int *c, int length){
    for(int i=0; i< length; ++i){
        for(int j=0; j< length; ++j){
            for(int k=0; k< length; ++k){
                c[i*length+j] += a[i*length+k]*b[k*length+j];
            }
        }
    }
}

int main(){
    int length =3;
    //設定seed
    unsigned seed;
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed); // 以時間序列當亂數種子

    //初始化矩陣
    int *a = (int*) malloc(sizeof(int) * length * length);
    int *b = (int*) malloc(sizeof(int) * length * length);
    int *result = (int*) malloc(sizeof(int) * length * length);
    int *result_cpu = (int*) malloc(sizeof(int) * length * length);

    //產生矩陣
    intMatrixGen(a,length,'r');
    intMatrixGen(b,length,'r');
    intMatrixGen(result_cpu,length, 0);
    printIntMatrix(a,length);
    printIntMatrix(b,length);
    //分配資源
    int *gpu_a,*gpu_b,*gpu_result;
    cudaMalloc((void**)&gpu_a, length * length * sizeof(int));      
    cudaMalloc((void**)&gpu_b, length * length * sizeof(int));
    cudaMalloc((void**)&gpu_result, length * length * sizeof(int));
    //複製資料到gpu
    cudaMemcpy(gpu_a, a, length *length * sizeof(int), cudaMemcpyHostToDevice);    
    cudaMemcpy(gpu_b, b, length *length * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(gpu_result, result, 0, cudaMemcpyHostToDevice);
    //開始計算
    dim3 grid(1,1,1), block(length,length,1);
    matMultiply_Gpu<<<grid,block>>>(gpu_a,gpu_b,gpu_result,length);
    //複製回cpu
    cudaMemcpy(result, gpu_result, length * length * sizeof(int), cudaMemcpyDeviceToHost);
    printf("gpu result:\n");
    printIntMatrix(result,length);
    
    matMultiply_Cpu(a,b,result_cpu,length);
    printf("cpu result:\n");
    printIntMatrix(result_cpu,length);

    return 0;
}