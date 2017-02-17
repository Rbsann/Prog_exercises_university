#include <stdio.h>
int main(){
  int m=10;
  int n=20;
  int p=30;
  int *pz=&m;
  printf("%d\n",m);
  printf("%d\n",*pz);
  printf("%p\n",pz);
  pz=&n;
  printf("%d\n",*pz);
  printf("%p\n",pz);
  pz=&p;
  printf("%d\n",*pz);
  printf("%p\n",pz);
  return 0;
}