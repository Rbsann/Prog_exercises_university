#include <stdio.h>
int main(void){
  int i=0;
  int V[100];
  for(i=0;i<100;i++){
   V[i]=i*2;
  }
  int *pz;
  pz=V;
  printf("%d\n", V[0]);
  printf("%d\n",*pz);
  return 0;
}