#include <stdio.h>
#include <string.h>

int main(){

int num;

scanf("%d", &num);

if(num>0){
  for(int i=0; i<num; i++){
    if(i==0)
      printf("K");
    else
      printf("k");
  }
printf("!");
}
return 0;

}