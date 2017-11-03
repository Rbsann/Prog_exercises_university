#include <stdio.h>
int main(){
  int n=0;
  int *pn=&n;
  while (n!=-99999){
    printf("Entre com valor de n\n");
    scanf("%d",&n);
    printf(" \n");
    printf("%d\n",n);
    printf("%d\n",*pn);
  }
  return 0;
}