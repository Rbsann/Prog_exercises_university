#include <stdio.h>
int main(void){
  int i=0;
  int V[100];
  for(i=0;i<100;i++){
   V[i]=i*2;
  }
  int *pz;
  pz=V+1;
  int *pw;
  pw=&V[1];
  printf("%d\n", V[1]);
  printf("%d\n",*pz);
  printf("%d\n",*pw);
  printf("%p\n",pz);
  printf("%p\n",pw);
  return 0;
}