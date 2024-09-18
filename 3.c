#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//prototypes
int declaringElement();
void Sort(int *K, int n);
int* newArray(int n1, int n2, int K1[], int K2[]);
void output(int K[], int n);

int main(){
    
    //initial data
    int n1 = declaringElement();
    int K1[n1];
    for(int i =0; i<n1;i++){
        printf("Insert array %d element: ", i+1);
        scanf("%d", &K1[i]);
    }
    int n2 = declaringElement();
    int K2[n2];
    for(int i =0; i<n2;i++){
        printf("Insert array %d element: ", i+1);
        scanf("%d", &K2[i]);
    }
    int m = declaringElement();


    int n = n1 + n2;
    int *K = newArray(n1,n2,K1,K2);

    Sort(K, n);

    output(K, m);
    free(K);
}

//functions
int declaringElement(){
    int n = 0;
    printf("Insert number: ");
    scanf("%d",&n);
    return n;
    
}
int* newArray(int n1, int n2, int K1[], int K2[]) {
    int n = n1 + n2;
    int *K = (int *)malloc(n * sizeof(int));

    if (K == NULL) { 
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Copy elements from K1 to K
    for (int i = 0; i < n1; i++) {
        K[i] = K1[i];
    }

    // Copy elements from K2 to K
    for (int i = 0; i < n2; i++) {
        K[n1 + i] = K2[i];
    }

    return K;  // Return the combined array
}
void Sort(int *K, int n) {
    int temp;
    bool sorted = false;

    // Loop until the array is fully sorted
    while (!sorted) {
        sorted = true;  // Assume it's sorted, will change if we do any swaps

        // Iterate through the array using pointer arithmetic
        for (int a = 0; a < n - 1; a++) {
            // Compare adjacent elements using pointers
            if (*(K + a) > *(K + a + 1)) {  // Swap if the current element is larger
                temp = *(K + a);
                *(K + a) = *(K + a + 1);
                *(K + a + 1) = temp;

                sorted = false;  // A swap happened, so the array wasn't sorted
            }
        }
    }
}
void output(int K[], int m){
     for(int i=0; i<m;i++){
        printf("%d\n",K[i]);
    }
}