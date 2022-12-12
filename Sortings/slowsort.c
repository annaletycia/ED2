#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000
#define MOD 100000;

void printArray(int array[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void slowsort(int array[], int l, int r, int n){
    if(l >= r) return;

    int m = (l+r)/2;
    slowsort(array,l,m,n);
    slowsort(array,m+1,r,n);

    if(array[m] > array[r]){
        int temp = array[r];
        array[r] = array[m];
        array[m] = temp;
    }

    slowsort(array,l,r-1,n);
}

void slowsort_wrapper(int array[], int length){
    slowsort(array,0,length-1,length);
}

int main(){
    srand(time(0));
    int array_to_sort[SIZE];

    for(int i = 0; i < SIZE; i++){
        array_to_sort[i] = rand() % MOD;
    }
    
    time_t start = time(0);
    slowsort_wrapper(array_to_sort,SIZE);
    time_t end = time(0);

    printArray(array_to_sort,SIZE);
    printf("Time needed: %ld", end - start);
}