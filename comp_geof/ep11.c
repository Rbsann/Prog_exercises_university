#include <stdio.h>
float calcular( float y,float x,float c[31],float t);

int main()
{
float lat=0;
float longitude=0;
float lat_ajust=0;
float longitude_ajust=0;
float temp_ajust=0;
float dia=0;
float mes=0;
float ano=0;
float declinacao=0.0;
float inclinacao=0.0;
float intensidade=0.0;
int i;
float cof_D[31]={-14.021375662
,-0.168692826
,-0.728121347
,-0.152403506
,0.009284154
,0.010645054
,0.003762631
,0.006069034
,0.000997887
,0.000660849
,0.000228488
,0.000147266
,0.000138951
,0.000102790
,0.000077382
,0.000033104
,-0.000080797
,0.000081799
,0.000023869
,-0.000003334
,-0.000001624
,-0.000002092
,0.000000783
,-0.000000687
, -0.000000467
,-0.000003224
,0.000001136
,-0.000000597
,-0.000000384
,-0.000000734
,0.000000313};
float cof_F[31]={24227.701493629
,179.249482444
,-35.691312861
,-40.650445499
,3.389231202
,-2.877812250
,1.344553781
,7.868317612
,-1.264195795
,0.139587984
,0.012235070
,-0.081386418
,0.017733176
,-0.129043199
,0.009808419
,0.010965888
,-0.011413932
,-0.050601698
,0.006210802
,-0.000669293
,0.002824651
,-0.000611097
,-0.001058025
,0.002319666
,-0.000389784
,0.000821961
,-0.000072882
,0.000208254
,0.000650523
,0.000052505
,0.000318015};
float cof_I[31]={-9.931508298
,  1.664769881
, -0.744295714
, -0.255241128
, -0.019318551
, -0.011764453
, -0.009579100
,  0.011203395
, -0.002852682
, -0.001215262
,  0.000231976
, -0.000118681
,  0.000138764
,  0.000350319
, -0.000092585
,  0.000041703
, -0.000325057
,  0.000109148
, -0.000024326
,  0.000005284
, -0.000000293
,  0.000004412
,  0.000008477
,  0.000000253
,  0.000001704
,  0.000007985
,  0.000004631
,  0.000001676
,  0.000000427
, -0.000004156
,  0.000001236};
printf("Entre com valor do dia\n");
scanf("%f", &dia);
printf("Entre com valor do mes\n");
scanf("%f",&mes);
printf("Entre com valor do ano\n");
scanf("%f",&ano);
printf("Entre com valor de lat\n");
scanf("%f",&lat);
printf("Entre com valor de long\n");
scanf("%f",&longitude);
temp_ajust=((((mes*31.6)+dia)/365)+ano)-1990.0;
lat_ajust=lat+15.0;
longitude_ajust=longitude+55.0;
declinacao=calcular(lat_ajust,longitude_ajust,cof_D,temp_ajust);
inclinacao=calcular(lat_ajust,longitude_ajust,cof_F,temp_ajust);
intensidade=calcular(lat_ajust,longitude_ajust,cof_I,temp_ajust);
printf("%f %f %f %f %f", dia,mes,ano,lat,longitude);
printf("Declinacao= %f Inclinacao=%f Intensidade=%f \n ", declinacao, inclinacao, intensidade);
return 0;
}
float calcular(float y,float x,float c[31],float t){
float p1,p2,p3,p4,p5,p6,p7=0.0;
float total=0.0;
p1=c[1]+c[2]*y+c[3]*x+c[4]*t+c[5]*x*x+c[6]*x*y+c[7]*x*t+c[8]*y*y;
p2=c[9]*y*t+c[10]*t*t+c[11]*x*x*x+c[12]*x*x*y+c[13]*x*x*t;
p3=c[14]*x*y*y+c[15]*x*y*t+c[16]*x*t*t+c[17]*y*y*y+c[18]*y*y*t;
p4=c[19]*y*t*t+c[20]*x*x*x*x+c[21]*x*x*x*y+c[22]*x*x*x*t;
p5=c[23]*x*x*y*y+c[24]*x*x*y*t+c[25]*x*x*t*t+c[26]*x*y*y*y;
p6=c[27]*x*y*y*t+c[28]*y*y*y*t+c[29]*x*y*t*t;
p7=c[30]*y*y*y*y+c[31]*y*y*t*t;
total=p1+p2+p3+p4+p5+p6+p7;
return total;
}


