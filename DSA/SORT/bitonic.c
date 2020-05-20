#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//定義遞增(inc)和遞減(dec)
#define INC 0
#define DEC 1
//產生亂數的DATA
void randomdata(int *, const int);
//實作BITONIC SORT
void bitonic(int*, int, int);
//實作bitwise xor交換兩者pointer所指的address
void swap(int*a, int*b);
int printlist(const int *data,const int l);
//合併bitonic sequence
void bitonic_merge(int* data, int len, int dir);

int main(){
    const int length = 8;
    int *data =(int *)malloc(sizeof(int)*length);
    randomdata(data,length);
    printlist(data,length);
    bitonic(data,length, INC);
    printlist(data,length);
}

//隨機產生資料
void randomdata(int *data,const int l){
    srand(time(NULL));
    for(int i=0;i<l;i++){
        data[i] = rand() %10;
    }
}

//實作divide and conquer版本的bitonic sort
void bitonic(int *data, int n, int dir){
    if(n <= 1)
        return;
    //first和second形成一個bitonic sequence
    //上半段，遞增
    int helf = n/2;
    bitonic(data, helf, INC);
    //下半段，遞減
    bitonic(data+helf, helf, DEC);
    return bitonic_merge(data,n,dir);
}
//合併bitonic sequence
//data: 資料
//len: 資料長度
//dir: 排序方向
void bitonic_merge(int* data, int len, int dir){
    //如果長度唯一就return
    if(len == 1) return;
    //取得中點
    int helf = len/2;
    //將first和second兩個part逐一比對，若方向不同就swap
    for(int i=0;i<helf;i++){
        //  假設是長度為2的list(first和Second)，希望是遞增(inc)且INC = 0，
        //  判斷式左方判斷是否為遞減，也就是第I個元素有沒有大於第I+1個元素，
        //  若是遞減，就交換，此時(1 != 0)為真，所以交換。
        //  
        //  如果希望是遞減(DEC)，DEC = 1，
        //  左方判斷式結果為false(遞增)，此時(0 != 1)為真，所以交換。
        if((data[i] > data[i+helf]) != dir){
            swap(&data[i], &data[i+helf]);
        }
    }
    //持續合併剩下的部分
    bitonic_merge(data,helf,dir);
    bitonic_merge(data+helf,helf,dir);
}
//對ADDRESS作BITWISE交換
void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
//印出資料
int printlist(const int *data,const int l){
    for(int i=0; i<l; i++)
        printf("%d ",data[i]);
    printf("\n");
}