#include <stdio.h>
int main(void){
  int i=0;
  int V[100];
  for(i=0;i<100;i++){
   V[i]=i*2;
  }
  int *pz;
  pz=V;
  printf("%d\n", V[1]);
  printf("%d\n",*pz+1);
  printf("%d\n",*(pz+1));
  return 0;
}