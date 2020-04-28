#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void printlist(int *list, int len){
    for(int i=0; i< len; i++){
        printf("%d ",list[i]);
    }
    //姆咪
    printf("\n");
};

int merge(int *list, int low, int mid, int high){
    int *left =  malloc(sizeof(int) * ((mid-low)+1));
    int *right = malloc(sizeof(int) * (high - mid));

    for(int i=low; i<=mid ;i++){
        left[i-low] = list[i];
    }
    for(int i=mid+1; i<=high ;i++){
        right[i-(mid+1)] = list[i];
    }
    int i = low;
    int rightIndex =0;
    int leftIndex =0;
    left[(mid-low+1)] = 2147483647;
    right[(high - mid)] = 2147483647;
    while(i <= high){
        if(left[leftIndex] < right[rightIndex]){
            list[i] = left[leftIndex];
            leftIndex++;
        }else{
            list[i] = right[rightIndex];
            rightIndex++;
        }
        i++;
    }
};

void mergeSort(int *list, int low, int high){
    //base case 
    if(high <= low){
        return;
    }

    int mid = (high+low)/2;
    //左半 
    mergeSort(list, low, mid);

    //右半
    mergeSort(list, mid+1, high);
    merge(list, low, mid, high);
};

int main(){
    int list[] = {277,887,256,5};
    printlist(list,sizeof(list)/sizeof(int));
    mergeSort(list,0,sizeof(list)/sizeof(int));
    printlist(list,sizeof(list)/sizeof(int));
    return 0;
}