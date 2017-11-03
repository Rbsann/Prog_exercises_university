#include <stdio.h>
int main(){
  double x=(double)1/3;
  double y=(double)1/5;
  double *pd;
  printf("%lf\n",x);
  printf("%lf\n",y);
  pd=&x;
  printf("%lf\n",*pd);
  printf("%p\n",pd);
  printf("%p\n",&pd);
  return 0;
}