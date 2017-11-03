#include <stdio.h>
#define MAX 10
void sort(int m, int mes[MAX], int dia[MAX],int ano[MAX],float mag[MAX],float prof[MAX],float lat[MAX],float longitude[MAX]);
int main()
{
int dia,mes,ano;
float mag,prof,lat,longitude;
int maxdia[MAX]={0};
int maxmes[MAX]={0};
int maxano[MAX]={0};
float maxmag[MAX]={0};
float maxprof[MAX]={0};
float maxlat[MAX]={0};
float maxlong[MAX]={0};
int j=0;
while(scanf("%d %d %d %f %f %f %f ", &mes,&dia,&ano,&mag,&prof,&lat,&longitude)==7)
	{
		for (j=0;j<MAX;j++)
				{
					if(mag>maxmag[j])
					{
						maxmag[j]=mag;
						maxdia[j]=dia;
						maxmes[j]=mes;
						maxano[j]=ano;
						maxprof[j]=prof;
						maxlat[j]=lat;
						maxlong[j]=longitude;
						sort(MAX,maxmes,maxdia,maxano,maxmag,maxprof,maxlat,maxlong);
						break;
					}

				}

		


	}	
	printf("\n");

		printf("%d %d %d %.2f %.2f %.2f %.2f \n", maxmes[MAX-1],maxdia[MAX-1],maxano[MAX-1]+1900,maxmag[MAX-1],maxprof[MAX-1],maxlat[MAX-1],maxlong[MAX-1]);

	

return 0;
}
void sort(int m, int mes[MAX], int dia[MAX],int ano[MAX],float mag[MAX],float prof[MAX],float lat[MAX],float longitude[MAX])
{	
	int i,j,t,r,s;
	float k,z,y,x;
	for (i=1;i<=m-1;i++)
		for(j=1;j<=m-i;j++)
			if(mag[j-1]>=mag[j])
				{
					k=mag[j-1];
					mag[j-1]=mag[j];
					mag[j]=k;
					t=mes[j-1];
					mes[j-1]=mes[j];
					mes[j]=t;
					s=ano[j-1];
					ano[j-1]=ano[j];
					ano[j]=s;
					z=prof[j-1];
					prof[j-1]=prof[j];
					prof[j]=z;
					y=lat[j-1];
					lat[j-1]=lat[j];
					lat[j]=y;
					x=longitude[j-1];
					longitude[j-1]=longitude[j];
					longitude[j]=x;
					r=dia[j-1];
					dia[j-1]=dia[j];
					dia[j]=r;

				}
}

