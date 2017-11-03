
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float calcular( float y,float x,float *c[],float t);


int main(int argc,char *argv[])
{
char temp [500];
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
int j;
int k;
float alpha;
float beta;
int contbarra;
float xmin;
float xmax;
float ymin;
float ymax;
float dx;
float dy;
char tipo [100];
if (argc <5)
{
fprintf(stdout,"Erro,parametros insuficientes");
return -1;
}
for (i=1;i<argc;i++)
{
	if(argv[i][0]!='-')
	{
		fprintf(stdout,"Falta hifen, favor incluir");
	}
	else
	{
		switch (argv[i][1])
	{
			
				case 'R':
					while(1)			
						{
							contbarra=0;
							k=1;
							j=2;
							if(contbarra==0)
							{
								
								while(argv[i][k]!='/'/*||argv[i][j]!='\0'*/)
								{
									temp[k-1]=argv[i][j];
									k++;
									j++;
								}
							temp[k-1]='\0';
							xmin=atof(temp);
							if(xmin>180 || xmin<-180)
							{
	   	  	 	   	  		 fprintf(stdout,"Erro, valor inexistente de longitude");
	   	  	 	   	  		 return -1;
	   	  	 	   	  		}

							contbarra++;
							k=1;
							}
							if (contbarra==1)
								{
									
									while(argv[i][j]!='/'/*||argv[i][j]!='\0'*/)
										{
											temp[k-1]=argv[i][j];
											k++;
											j++;
										}
							temp[k-1]='\0';
							xmax=atof(temp);
							if(xmax>180 || xmax<-180)
							{
	   	  	 	   	  		 fprintf(stdout,"Erro, valor inexistente de longitude");
	   	  	 	   	  		 return -1;
	   	  	 	   	  		}

									contbarra++;
									k=1;
								}
							if (contbarra==2)
								{
									
									while(argv[i][j]!='/'/*||argv[i][j]!='\0'*/)
									{
										temp[k-1]=argv[i][j];
										k++;
										j++;
									}
							temp[k-1]='\0';
							ymin=atof(temp);
							if(ymin>90 || ymin<-90)
							{
	   	  	 	   	  		 fprintf(stdout,"Erro, valor inexistente de latitude");
	   	  	 	   	  		 return -1;
	   	  	 	   	  		}

									contbarra++;
									k=1;
								}
							if (contbarra==3)
								{
									
									while(argv[i][j]!='\0')
										{
											temp[k-1]=argv[i][j];
											j++;
											k++;
										}
							temp[k-1]='\0';
							ymax=atof(temp);
							if(ymax>90 || xmax<-90)
							{
	   	  	 	   	  		 fprintf(stdout,"Erro, valor inexistente de latitude");
	   	  	 	   	  		 return -1;
	   	  	 	   	  		}
								contbarra++;
								}
							if (contbarra!=4)
								{
									fprintf(stdout,"Numero insuficiente de parametros de localizacao");
									return -1;
									break;
								}			
					else if (contbarra==4)
					{
						break;
					} 
							
						}
			
			
			


	break;
	case 'E':
		if (argv[i][2] !='i'||argv[i][2]!='d'||argv[i][2]!='f')
		{
			fprintf(stdout,"Entre com tipo de calculo adequado");
			return -1;

		}
		else
		{
			tipo[0]=argv[i][2];
		}
	break;
	case 'D':
			while(1)	
			{		
							contbarra=0;
							k=1;
							j=2;
							if(contbarra==0)
							{
								
								while(argv[i][k]!='/'/*||argv[i][j]!='\0'*/)
								{
									temp[k-1]=argv[i][j];
									k++;
									j++;
								}
							temp[k-1]='\0';
							dia=atof(temp);
							contbarra++;
							k=1;
							}
							if (contbarra==1)
								{
									
									while(argv[i][j]!='/'/*||argv[i][j]!='\0'*/)
										{
											temp[k-1]=argv[i][j];
											k++;
											j++;
										}
							temp[k-1]='\0';
							mes=atof(temp);
							contbarra++;
							k=1;
								}
							if (contbarra==2)
								{
									
									while(argv[i][j]!='\0')
									{
										temp[k-1]=argv[i][j];
										k++;
										j++;
									}
							temp[k-1]='\0';
							ano=atof(temp);
							contbarra++;
							k=1;
								}
							if (contbarra!=3)
								{
									fprintf(stdout,"Numero insuficiente de parametros de data");
									return -1;
									break;
								}			
					else if (contbarra==3)
					{
						break;
					} 
							
						}
			
			//*checar valores das datas
		break;

		case 'I':
		while(1)			
			{		
							contbarra=0;
							k=1;
							j=2;
							if(contbarra==0)
							{
								
								while(argv[i][k]!='/'/*||argv[i][j]!='\0'*/)
								{
									temp[k-1]=argv[i][j];
									k++;
									j++;
								}
							temp[k-1]='\0';
							dx=atof(temp);
							contbarra++;
							k=1;
							}
							if (contbarra==1)
								{
									
									while(/*argv[i][j]!='/'||*/argv[i][j]!='\0')
										{
											temp[k-1]=argv[i][j];
											k++;
											j++;
										}
							temp[k-1]='\0';
							dy=atof(temp);
							contbarra++;
							k=1;
								}
							if (contbarra!=2)
								{
									fprintf(stdout,"Numero insuficiente de parametros de passo");
									return -1;
									break;
								}			
					else if (contbarra==2)
					{
						break;
					} 
							
						}

			
			break;
			default:
			fprintf(stdout,"Parametro nao reconhecido")	;
			return -1;

}
}
}
		 
/**Checar valores de dx e dy**/			
float cof_D[]={-14.021375662
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
float cof_F[]={24227.701493629
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
float cof_I[]={-9.931508298
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
temp_ajust=((((mes*31.6)+dia)/365)+ano)-1990.0;
if (tipo[0]=='d')
{
for(alpha=xmin;alpha<=xmax;alpha=alpha+dx){
	for(beta=ymin;beta<=ymax;beta=beta+dy){
lat_ajust=j+15.0;
longitude_ajust=i+55.0;
declinacao=calcular(lat_ajust,longitude_ajust,cof_D,temp_ajust);
}
}
}
else if(tipo[0]=='f')
{
for(alpha=xmin;alpha<=xmax;alpha=alpha+dx){
	for(beta=ymin;beta<=ymax;beta=beta+dy){
lat_ajust=j+15.0;
longitude_ajust=i+55.0;
intensidade=calcular(lat_ajust,longitude_ajust,cof_F,temp_ajust);
}
}
}
else if (tipo[0]=='i')
{
for(alpha=xmin;alpha<=xmax;alpha=alpha+dx){
for(beta=ymin;beta<=ymax;beta=beta+dy){
lat_ajust=j+15.0;
longitude_ajust=i+55.0;
inclinacao=calcular(lat_ajust,longitude_ajust,cof_I,temp_ajust);
}
}
}
}

		
	
	
	





float calcular(float y,float x,float *c[],float t)
{
float p1,p2,p3,p4,p5,p6,p7=0.0;
float total=0.0;
p1=c[0]+c[1]*y+c[2]*x+c[3]*t+c[4]*x*x+c[5]*x*y+c[6]*x*t+c[7]*y*y;
p2=c[8]*y*t+c[9]*t*t+c[10]*x*x*x+c[11]*x*x*y+c[12]*x*x*t;
p3=c[13]*x*y*y+c[14]*x*y*t+c[15]*x*t*t+c[16]*y*y*y+c[17]*y*y*t;
p4=c[18]*y*t*t+c[19]*x*x*x*x+c[20]*x*x*x*y+c[21]*x*x*x*t;
p5=c[22]*x*x*y*y+c[23]*x*x*y*t+c[24]*x*x*t*t+c[25]*x*y*y*y;
p6=c[26]*x*y*y*t+c[27]*y*y*y*t+c[28]*x*y*t*t;
p7=c[29]*y*y*y*y+c[30]*y*y*t*t;
total=p1+p2+p3+p4+p5+p6+p7;
return total;
}


