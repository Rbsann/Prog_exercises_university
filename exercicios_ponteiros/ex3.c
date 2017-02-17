#include <stdio.h>
int main(){
  double x=(double)1/3;
  double y=(double)1/5;
  double *pd;
  double z=0;
  printf("%lf\n",x);
  printf("%lf\n",y);
  pd=&y;
  printf("%lf\n",*pd);
  printf("%p\n",pd);
  printf("%p\n",&pd);
  z=*pd*x;
  pd=&z;
  printf("%lf\n",x);
  printf("%lf\n",y);
  printf("%lf\n",*pd);
  printf("%p\n",pd);
  printf("%p\n",&pd);
  return 0;
}