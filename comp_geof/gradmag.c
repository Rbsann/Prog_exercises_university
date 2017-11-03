//Ep13 - GradMag - Calcular o Campo Magnetico para uma Grade//
#include <stdio.h>
#include <math.h>
#include <string.h>

float ci[]={
-9.930508298,
1.664769881,
-0.744295714,
-0.255241128,
-0.019318551,
-0.011764453,
-0.009579100,
0.011203395,
-0.002852682,
-0.001215262,
0.000230976,
-0.000118681,
0.000138764,
0.000350309,
-0.000092585,
0.000041703,
-0.000325057,
0.000109148,
-0.000024326,
0.000005284,
-0.000000293,
0.000004412,
0.000008477,
0.000000253,
0.000001704,
0.000007985,
0.000004631,
0.000001676,
0.000000427,
-0.000004156,
0.000001236,
};
float cd[]={
-14.021375662,
-0.168692826,
-0.728121347,
-0.152403506,
0.009284154,
0.010645054,
0.003762631,
0.006069034,
0.000997887,
0.000660849,
0.000228488,
0.000147266,
0.000138951,
0.000102790,
0.000077382,
0.000033104,
-0.000080797,
0.000081799,
0.000023869,
-0.000003334,
-0.000001624,
-0.000002092,
0.000000783,
-0.000000687,
-0.000000467,
-0.000003224,
0.000001136,
-0.000000597,
-0.000000384,
-0.000000734,
0.000000313,
};
float ct[]={
24227.701493629,
179.249482444,
-35.691302861,
-40.650445499,
3.389231202,
-2.877812250,
1.344553781,
7.868307612,
-1.264195795,
0.139587984,
0.012235070,
-0.081386418,
0.017733076,
-0.129043199,
0.009808419,
0.010965888,
-0.011413932,
-0.050601698,
 0.006210802,
-0.000669293,
0.002824651,
-0.000611097,
-0.001058025,
0.002309666,
-0.000389784,
0.000821961,
-0.000072882,
0.000208254,
0.000650523,
0.000052505,
0.000308015,
};
float CAMPO (float lat, float lg, float epoca, float *c ){
	 
	 int i=0;
    float p1,p2,p3,p4,p5,p6,p7,res;
    printf("%f %f %f\n",lat,lg,epoca);
    for(i=0;i<=30;i++){
    	printf("%.9f\n",c[i]);
	}
    
  p1=c[0]+c[1]*lat+c[2]*lg+c[3]*epoca+c[4]*lg*lg+c[5]*lg*lat+c[6]*lg*epoca+c[7]*lat*lat;
  p2=c[8]*lat*epoca+c[9]*epoca*epoca+c[10]*lg*lg*lg+c[11]*lg*lg*lat+c[12]*lg*lg*epoca;
  p3=c[13]*lg*lat*lat+c[14]*lg*lat*epoca+c[15]*lg*epoca*epoca+c[16]*lat*lat*lat+c[17]*lat*lat*epoca;
  p4=c[18]*lat*epoca*epoca+c[19]*lg*lg*lg*lg+c[20]*lg*lg*lg*lat+c[21]*lg*lg*lg*epoca;
  p5=c[22]*lg*lg*lat*lat+c[23]*lg*lg*lat*epoca+c[24]*lg*lg*epoca*epoca+c[25]*lg*lat*lat*lat;
  p6=c[26]*lg*lat*lat*epoca+c[27]*lat*lat*lat*epoca+c[28]*lg*lat*epoca*epoca;
  p7=c[29]*lat*lat*lat*lat+c[30]*lat*lat*epoca*epoca;
  res=p1+p2+p3+p4+p5+p6+p7;
  printf("%f\n",res);
  
  return res;
  
}
void main (int argc, char *argv[]) {
 
  float c[30];
  float l,p,decl,incl,ints,dia,mes,epoca,lat,lg,ano,x_min,x_max,y_min,y_max,dx,dy,res;
  char m[20];
  int k,z,i,j,bar;
  
 
  
  if(argc<5){
  	fprintf(stdout,"ERRO-Parametros Insuficientes");
  	return -1;
  }else{
   for(i=1;i<argc;i++){
  	 if(argv[i][0]!='-'){
  		 fprintf(stdout,"ERRO-Nao Esta Presente o Negativo no Inicio de Cada Parametro");
  		 return -1;
	 }else{
	    switch(argv[i][1]) {
	   	  case 'R':
	   	  	 bar=0;
		     z=1;
	   	  	 for(j=2;bar<=3;j++){
	   	  	 	if(argv[i][j]=='/' || argv[i][j]=='\0'){
	   	  	 	   m[z-1]='\0';
	   	  	 	   z=1;
	   	  	 	   
	   	  		   //printf("bar=%d\n",bar);		  
	   	  	 	   switch(bar){
	   	  	 	   	  case 0:
	   	  	 	   	  	x_min=atof(m);
	   	  	 	   	  	if(x_min>180 || x_min<-180)
	   	  	 	   	  	 fprintf(stdout,"Erro-Longitude nao Existe");
	   	  	 	   	  //printf("%f\n",x_min);
	   	  	 	   	  	break;
	   	  	 	   	  case 1:
						x_max=atof(m);
						if(x_max>180 || x_max<-180)
	   	  	 	   	  	 fprintf(stdout,"Erro-Longitude nao Existe");
						//printf("%f\n",x_max);
						break;
					  case 2:
					    y_min=atof(m);
					    if(y_min>90 || y_min<-90)
	   	  	 	   	  	  fprintf(stdout,"Erro-Latitude nao Existe");
					    //printf("%f\n",y_min);
					    break;
					  case 3:
					    y_max=atof(m);
					     if(y_max>90 || y_max<-90)
	   	  	 	   	  	   fprintf(stdout,"Erro-Latitude nao Existe");
					    //printf("%f\n",y_max);
						break;				   	
				 }
					 
					 bar++;
			    }else{
			       z++;
	   	  	 	   m[z-2]=argv[i][j];
	   	  	 	   //printf("%c\n",m[z-2]);
	   	  	 	  
	   	  	 	   
                }
	   	  	 	
	   	  	 		
	   	  	 		
				}
	   	  	 		
	   	  	 	
	   	 	
	   	 	 break;
	   	 	
	   	  case 'E':
	   	  	//printf("%c-argv\n",argv[i][2]);
	   	  	if(argv[i][2] == 'i' || argv[i][2] =='d' || argv[i][2]== 'f'){
	   	  
	   	  	switch(argv[i][2]){
	   	  		case 'i':
	   	  			for(k=0;k<=30;k++){
	   	  				c[k]=ci[k];
	   	  				printf("%.9f\n",c[k]);
						 }
					//printf("i\n");	 
	   	  			break;
	   	  		case 'd':
	   	  			for(k=0;k<=30;k++){
	   	  			  c[k]=cd[k];
	   	  			  printf("%.9f\n",c[k]);
				      }
				      //printf("d\n");
					 break;
				case 'f':
					for(k=0;k<=30;k++){
	   	  			  c[k]=ct[k];
	   	  			  printf("%.9f\n",c[k]);
					  }
					  //printf("f\n");
				     break;	
				 }
	   	  			
	   	   }else{
	   	  	 fprintf(stdout,"Erro-Parametro Nao Existe");
	   	  	  return -1;
		    }  
		
			 break;
			
		  case 'D': 
		  	bar=0;
		  	 z=1;
		  	for(j=2;bar<=2;j++){
	            if(argv[i][j]=='/' || argv[i][j]=='\0'){
	              m[z-1]='\0';
	               z=1;

	              switch(bar){
	              	case 0:
	              		dia=atof(m);
	              		
	              		 printf("%f\n",dia);
	              		break;
	              	case 1:
					  	mes=atof(m);
					  	if(mes>12){
					  		fprintf(stdout,"Erro-Mes esta errado");
	   	  	                return -1;
						  }
					  	 printf("%f\n",mes);
					  	break;
					case 2:
					    ano=atof(m);
					     printf("%f\n",ano);
						break;  	
				  }
				  bar++;
	            }else{
	              z++;	
	   	  	 	  m[z-2]=argv[i][j];
	   	  	    }
	   	  	   
		  		
			  }
		 	
		 	 break;
		  case 'I':
		  	bar=0;
		  	 z=1;
		  	for(j=2;bar<=1;j++){
		  		if(argv[i][j]=='/' || argv[i][j]=='\0'){
		  		  m[z-1]='\0';
		  		   z=1;
		  		  switch(bar){
		  			  case 0:
		  				  dx=atof(m);
		  				  //printf("%f\n",dx);
		  				  break;
		  			  case 1:
						  dy=atof(m);
						  //printf("%f\n",dy);
						  break;	  		
				  }
				  bar++;
			    }else{
			       z++;	
	   	  	 	   m[z-2]=argv[i][j];
		  	   
			    }
			   
		    }
		 
		     break;	
	   } 
    }
  }
 }
  ano=ano+(((mes*30.6)+dia)/365);
  epoca=ano-1990;
  printf("%f\n",epoca);
 
  for(l=x_min;l<x_max;l=l+dx){
  	for(p=y_min;p<y_max;p=p+dy){
  		 lg=l;
  		 lat=p;
  		 
  		 lat=lat+15;
         lg=lg+55;
  		res=CAMPO(lat,lg,epoca,c); 
  		printf("%f %f %.7f\n",l,p,res);
  		
  	
	  }
  }
 
  
  

 
}
  
