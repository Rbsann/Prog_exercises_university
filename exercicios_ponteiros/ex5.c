#include <stdio.h>

int maiorvalor (int *a, int*b){
  int temp=0;
  int z;
  if (*a>*b){
    temp=*b;
    *b=*a;
    *a=temp;
}
  if (*a>*b){
    z=*a;
    return z;
    ;
  }
  else{
    z=*b;
    return z;
  }

}

int main(){
  int m=0;
  int n=0;
  printf("Entre com primeiro valor\n");
  scanf("%d", &m);
  printf("Entre com segundo valor\n");
  scanf("%d",&n);
  maiorvalor(&m, &n);
  printf("%d\n",m);
  printf("%d\n\n",n);
  printf("Entre com primeiro valor\n");
  scanf("%d",&m);
  printf("Entre com segundo valor\n");
  scanf("%d",&n);
  int *pm;
  int *pn;
  pm=&m;
  pn=&n;
  maiorvalor(pm,pn);
  printf("%d\n",m);
  printf("%d\n",n);
  return 0;
}

