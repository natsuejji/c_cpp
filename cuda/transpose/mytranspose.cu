/*
a4230755 矩陣轉置

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda_runtime.h>
void printMat(const float *mat, const int row, const int col);
void randomMat(float *mat, const int lenght);
__global__ void transpose_gpu(float *mat, float *result);

int main(){
    int row = 10;
    int col = 5;
    float *mat = (float*) malloc(sizeof(float)*row*col);
    float *result = (float*) malloc(sizeof(float)*row*col);
    float *device_mat, *device_result;

    //generate random matrix and print its
    randomMat(mat,row*col);
    printf("pre-transpose : \n");
    printMat(mat,row,col);
    
    cudaMalloc((void**)&device_mat, sizeof(float)*row*col);
    cudaMalloc((void**)&device_result, sizeof(float)*row*col);
    cudaMemcpy(device_mat, mat, sizeof(float)*row*col, cudaMemcpyHostToDevice);

    //allocation gpu resource
    dim3 grid(row,1,1),block(col,1,1);
    //transpose matrix on gpu
    transpose_gpu<<<grid,block>>>(device_mat,device_result);
    cudaMemcpy(result, device_result, sizeof(float)*row*col, cudaMemcpyDeviceToHost);
    printf("transposed : \n");
    printMat(result,col,row);

}

__global__ void transpose_gpu(float *mat, float *result){
    int row = blockIdx.x;
    int col = threadIdx.x;
    result[col*gridDim.x + row] = mat[blockDim.x*row+col];
}

void printMat(const float *mat, const int row, const int col){
    for(int i=0; i< row*col; i++){
        printf("%f ", mat[i]);
        if((i+1) % col == 0){
            printf("\n");
        }
    }
};

void randomMat(float *mat, const int lenght){
    srand(time(NULL));
    for(int i=0; i< lenght; i++){
        mat[i] = (float) rand()/ (float)(RAND_MAX) * 1.0;
    }
};