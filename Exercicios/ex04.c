#include <stdio.h>
#include <ctype.h>

int main(){

int num;
char str[1000000];

scanf("%d", &num);

if(num>0){
  for(int i=0; i<num; i++){
    str[i] = 'k';
  }
  str[0] = toupper(str[0]);
  printf("%s!", str);
}
return 0;
}