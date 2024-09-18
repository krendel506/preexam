#include <stdio.h>
#include <stdlib.h>

#define N 4

int compare(const void* a, const void* b);

int main(){

int A[3][N] = {{3,3,2,2},{9,2,6,5},{7,5,9,3}};
int sum[3] = {0};
int sumsize = sizeof(sum) / sizeof(sum[0]);


for (int i=0; i<3;i++){
    for(int j=0; j<N;j++){
        if(A[i][j] < N){
        sum[i] = sum[i] + A[i][j];
        }
    }
}

//sorts sum array from biggest to smallest
qsort(sum, sumsize, sizeof(int), compare);

 for (int i = 0; i < sumsize; i++) {
     printf("%d\n",sum[i]);
    }
    return 0;

}

int compare(const void* a, const void* b) {
      
      // If a is smaller, positive value will be returned
    return (*(int*)b -*(int*)a);
}