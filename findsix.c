#include "stdio.h"

int findsix(int *array, int len);
int compare(int a, int b);

int main(){
    //declare an array with length of six.
    int array[6] = {
        1,6,2,6,3,4
    };
    //get count of the number of six. by function findsix
    int count = findsix(array,sizeof(array)/sizeof(array[0]));
    //print the number of six
    printf("count of six acount : %d\n", count);
    getchar();
    
    return 0;
}

int findsix(int *array, int len){
    int count = 0;
    // print array's length
    printf("array length: %d\n", len);
    //define forloop count
    for(int i = 0;i<len;i++){
        // print current number(array traversal)
        printf("current number: %d\n", *(array+i));
        //compare number in an array, if the value greater than six count plus 1.
        count += compare(*(array+i),6);
    }
    return count;
}

int compare(int a, int b){
    if(a == b) return 1;
    else return 0;
}