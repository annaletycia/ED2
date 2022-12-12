#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

bool is_sorted(int *a, int n)
{
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}
 
void shuffle(int *a, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }
}
 
void bogosort(int *a, int n)
{
  while ( !is_sorted(a, n) ) shuffle(a, n);
}
 
int main()
{
    printf("<<<Ordenando numeros com bogosort>>>\n\n");
  int numbers[MAX];
  int i , num;

    printf("Digite o numero de elementos do array: ");
    scanf("%d", &num);
    printf("Digite os %d elementos do array: \n", num);

    for(i=0; i<num; i++){
        scanf("%d", &numbers[i]);
    }

  bogosort(numbers, num);
  for (i=0; i < num; i++) printf("%d ", numbers[i]);
  printf("\n");
}
