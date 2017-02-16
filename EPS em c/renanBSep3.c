/********************************************************************/
/**                                                                **/
/**  MAC0115 - Introducao a Computacao - IAG - 1o. sem. 2015       **/
/**  Nome do aluno: Renan Bueno Sanches                            **/
/**  Numero USP:8962102                 Curso:Geofisica            **/
/**  Exercicio-Programa 03                                         **/
/**                                                                **/
/********************************************************************/


#include <stdio.h>
#define EPS 0.0000001
#define A  1277
#define B 1
#define L 131072

double modulo (double x) /*Essa funcao recebe x e devolve -x se x for <0*/
{

	if (x <0)
	{
	x=-x;
	}

	return x;
	}
double raiz_quadrada (double x) /*recebe x e devolve a raiz quadrada dele*/
{
	double r0=x, ri=0, r2=0,r3=1; /*Duas variaveis temporarias para rodar o loop.*/
	while (modulo(r3-r2)>=EPS){
		ri=(r0+(x/r0))/2;
		r3=ri;
		r2=r0;
		r0=ri;
	}
	return r3;
}
double f (double x) /*Funcao que calcula a funcao de x em sqrt(1-x^2)*/
{
	double funcaox=raiz_quadrada(1-x*x);
	if((1-x*x)<=0)
	{
		funcaox=0;
	}
	return funcaox;
}
double metodo_retangulos(double a, double b,int k) /*Primeiro metodo de calculo de pi, metodo dos retangulos*/
{
	double deltax=((b-a)/k);
	int n;
	double area=0.0;
	double pi=0.0;
	for(n=1; n<k;n++)
	{

		area=f(a+n*deltax)*deltax+area; /*Calcula a area dos retangulos com a formula dada no enunciado do programa*/


	}
    pi=4*area; /*Ja calcula o valor de pi multiplicando por 4 o valor da area achada, tendo em vista que eh um semi-circulo*/
	return pi;
}
double metodo_trapezio(double a, double b,int k) /*Funcao que calcula PI pelo metodo do trapezio*/
{
	double deltax=((b-a)/k);
	int n;
	double area=0.0;
	double pi=0.0;
	for(n=0; n<k;n++)
	{

		area=(((f(a+n*deltax)+f(a+(n+1)*deltax))*deltax)/2)+area; /*Formula dada no enunciado do programa*/


	}
    pi=4*area;/* Retorna o valor de pi multiplicando por 4 o valor da area achada , tendo em vista que eh um semi circulo*/
	return pi;
}
void gera_num_aleatorio (int *u) /* Funcao que gera numero aleatorios pro metodo de monte carlo*/
{

    *u=(A**u+B)%L;

}
void gera_ponto(double a, double b,double M, int *u,double *px, double *py) /*Funcao que gera pontos pro metodo de monte carlo*/
{
gera_num_aleatorio(u);
*px=a+(double)*u*(b-a)/(L-1);
gera_num_aleatorio(u);
*py=(double)*u*M/(L-1); /*Formula dada no enunciado do programa*/
}
double metodo_monte_carlo(double a, double b,double M,int n, int*u) /*Funcao que calcula PI pelo metodo de monte carlo*/
{
int i, counter=0;
double P,area;
double *px, *py;
double p_x=0,p_y=0;
px=&p_x;
py=&p_y;

for (i=0;i<n; i++) /*Esse loop calcula a proporcao dos numeros aleatorios que estao dentro da funcao entre todos numeros gerados*/
{
    gera_ponto(a,b,M,u,px,py);
    if (p_x <=f(p_y))
    {
        counter++;
    }
}


P=(double)counter/n;
area=P*(b-a)*M; /*Calcula a area como o fator de proporcao calculado no loop multiplicado pelas constantes dadas*/
return area;



}
int converte( double fx, double M, int fe) /*Calcula o fator de escala da funcao sqrt(1-x^2)*/
{
	int indice;
	indice=(int)((fx*fe)/M+0.5);
	return indice;

}

void imprime_grafico(double a, double b,double M, int k, int fe) /*Funcao que imprime o grafico da funcao*/
{
	int counter, counter2;
	double x;
	int indice;
	x=1/((double)k-1); /*Para imprimir os valores de x que serao utlizados pra calcular f(x)*/
	for(counter=0; counter <14;counter++)
	{
		printf(" ");
	}
	printf("0");
		for(counter=0; counter <(fe-1);counter++)
	{
		printf(" ");
	}
	printf("1");
	printf("\n");
	printf("x (linhas)");
		for(counter=0; counter <9;counter++)
	{
		printf(" ");
	}
	for(counter=0;counter<fe;counter++)
	{
	printf(" ");
	}
		for(counter=0; counter <1;counter++)
	{
		printf(" ");
	}
		printf("f (x) (colunas)");
		printf("\n");
			for(counter=0; counter <11;counter++)
	{
		printf(" ");
	}
	printf("--|");
		for(counter=0; counter <=fe;counter++)
	{
		printf("-");
	}
	printf("|-->");
	printf("\n");
				for (counter2=0;counter2<k;counter2++)
					{
		printf(" %.6f", (double)x*counter2); /*Imprime a quantidade de pontos de X*/
		for(counter=0; counter <4;counter++)
	{
		printf(" ");
	}
	printf("|");
	for(counter=0; counter <converte(f(x*counter2),M,fe);counter++)
	{
		printf(" ");

	}
	printf("*"); /*Encaixa '*' no lugar da interseccao do grafico.*/
	indice=converte(f(x*counter2),M,fe);
	for(counter=indice; counter<fe;counter++)
	{
		printf(" ");

	}
	printf("|");
	for(counter=0; counter <5;counter++)
	{
		printf(" ");
	}
	printf("%.10f", f(counter2*x));
	printf("\n");
					}
    for(counter=0;counter<13;counter++)
    {


    printf(" ");
    }
    printf("|");
    for(counter=0;counter<=fe;counter++){
        printf(" ");
    }
    printf("|");
}

int main()
{
double a=0.0, b=1.0, M=1.0; /*Constantes dadas*/
int qtd_retangulos;/*Variavel pra guardar a quantidade de retangulos que serao utilizados no metodo dos retangulos*/
int qtd_trapezios;/*Idem para trapezios*/
int qtd_grafico;/*Variavel para guardar o ponto que serao utilizados para plotar o grafico*/
double deltax=0;
int contador=0;
int *semente, u,pontos=0,n_repeticoes=0;/*Variaveis para o metodo de monte carlo*/
double area=0;
int fe;/*Variavel pra guardar fator de escala que sera utilizado no grafico*/
char tarefa;/*Variavel para acessar cada tarefa*/
printf("Esse programa foi projetado para a resolucao de 4 tarefas.\n\n");/*Apresentacao do programa*/
printf("As tres primeiras tarefas calculam o valor de PI por metodos diferentes\n\n");
printf("O primeiro metodo eh o metodo dos retangulos.\n");
printf("Nele o programa calcula a area de x retangulos sob o grafico\nda funcao sqrt(1-x^2)\n");
printf("Para acessar esse metodo digite 'r' como codigo da tarefa \ne entre com o numero de retangulos que serao usados\n\n");
printf("O segundo metodo eh o metodo dos trapezios.\n");
printf("Nele o programa calcula a area de x trapezios sob a area da mesma funcao\n");
printf("Entre com 't' para acessar esse metodo e digite o numero de trapezios\nque serao utilizados para o calculo da area\n\n");
printf("O terceiro metodo eh o metodo de Monte Carlo.\nAcesse-o com 'm' e entre ");
printf("com uma semente para gerar numeros pseudo-aleatorios,\na quantidade de vezes que esse metodo sera repetido ");
printf("e\nquantos pontos serao gerados.\n\n");
printf("A quarta tarefa consiste em imprimir o grafico da funcao sqrt(1-x^2).\n");
printf("Acesse esse metodo com 'g' e entre com numero de pontos para o grafico\ne o fator de escala que sera utilizado\n\n");
printf("Para finalizar o programa entre com '-'\n\n\n\n");
printf("\n");
printf("\n");
printf("\n");
printf("Digite o codigo de uma tarefa ('r', 't', 'm', 'g') : ");
scanf(" %c", &tarefa);
printf("\n");

if (tarefa== 'r')
{
printf("Entre com numero de retangulos : ");
scanf ("%d", &qtd_retangulos);
deltax=((b-a)/qtd_retangulos);
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Valor aproximado de pi pelo metodo dos retangulos\n");
printf("\n");
printf("Numero de retangulos = %d\n",qtd_retangulos);
printf("Deltax = %.6f\n", deltax);
printf("PI = %.10f\n", metodo_retangulos (a,b,qtd_retangulos));
printf("\n");
printf("================================================================================\n");
printf("\n");

}
else if (tarefa== 't')
{
printf("Entre com numero de trapezios : ");
scanf ("%d", &qtd_trapezios);
deltax=((b-a)/qtd_trapezios);
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Valor aproximado de pi pelo metodo dos trapezios\n");
printf("\n");
printf("Numero de trapezios = %d\n",qtd_trapezios);
printf("Deltax = %.6f\n", deltax);
printf("PI = %.10f\n", metodo_trapezio (a,b,qtd_trapezios));
printf("\n");
printf("================================================================================\n");
printf("\n");
}
 else if (tarefa== 'm')
{
area=0;
printf("Digite uma semente para o gerador de nos. aleatorios : ");
scanf ("%d", &u);
semente=&u;
printf("Digite o numero de repeticoes do calculo da area : ");
scanf("%d", &n_repeticoes);
printf("Digite o numero de pontos a serem gerados : ");
scanf("%d", &pontos);
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Valor aproximado de pi pelo metodo de Monte Carlo\n");
printf("\n");
printf("Semente = %d", u);
for(contador=0;contador<n_repeticoes;contador ++)/*Loop para repetir metodo de monte carlo*/
	{
      area=metodo_monte_carlo(a,b,M,pontos,semente)+area;
	}
printf("\n");
printf("Numero de repeticoes = %d", n_repeticoes);
printf("\n");
printf("Numero de pontos = %d", pontos);
printf("\n");
printf("PI = %.10f\n",4*(area/(double)n_repeticoes));
printf("\n");
printf("================================================================================\n");
printf("\n");



}
 else if (tarefa== 'g')
{
printf("Digite o numero de pontos para o grafico : ");
scanf("%d", &qtd_grafico);
printf("Digite um fator de escala (int. entre 20 e 60) : ");
scanf("%d", &fe);
printf("\n");
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Grafico da funcao raiz quadrada de (1-x*x) no intervalo [0.0, 1.0]");
printf("\n");
printf("\n");
printf("Numero de pontos = %d\n", qtd_grafico);
printf("Fator de escala = %d", fe);
printf("\n");
printf("\n");
printf("\n");
printf("\n");
imprime_grafico(a,b,M,qtd_grafico, fe);
printf("\n");
printf("\n");
printf("================================================================================\n");
printf("\n");

}
tarefa='0';

while(tarefa!= '-')
{
printf("Digite o codigo de uma tarefa ('r', 't', 'm', 'g', '-') : ");
scanf(" %c", &tarefa);
printf("\n");

if (tarefa== 'r')
{
printf("Entre com numero de retangulos : ");
scanf ("%d", &qtd_retangulos);
deltax=((b-a)/qtd_retangulos);
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Valor aproximado de pi pelo metodo dos retangulos\n");
printf("\n");
printf("Numero de retangulos = %d\n",qtd_retangulos);
printf("Deltax = %.6f\n", deltax);
printf("PI = %.10f\n", metodo_retangulos (a,b,qtd_retangulos));
printf("\n");
printf("================================================================================\n");
printf("\n");

}
 else if (tarefa== 't')
{
printf("Entre com numero de trapezios : ");
scanf ("%d", &qtd_trapezios);
deltax=((b-a)/qtd_trapezios);
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Valor aproximado de pi pelo metodo dos trapezios\n");
printf("\n");
printf("Numero de trapezios = %d\n",qtd_trapezios);
printf("Deltax = %.6f\n", deltax);
printf("PI = %.10f\n", metodo_trapezio (a,b,qtd_trapezios));
printf("\n");
printf("================================================================================\n");
printf("\n");
}
 else if (tarefa== 'm')
{
area=0;
printf("Digite uma semente para o gerador de nos. aleatorios : ");
scanf ("%d", &u);
semente=&u;
printf("Digite o numero de repeticoes do calculo da area : ");
scanf("%d", &n_repeticoes);
printf("Digite o numero de pontos a serem gerados : ");
scanf("%d", &pontos);
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Valor aproximado de pi pelo metodo de Monte Carlo\n");
printf("\n");
printf("Semente = %d", u);
for(contador=0;contador<n_repeticoes;contador ++){
      area=metodo_monte_carlo(a,b,M,pontos,semente)+area;
	}
printf("\n");
printf("Numero de repeticoes = %d", n_repeticoes);
printf("\n");
printf("Numero de pontos = %d", pontos);
printf("\n");
printf("PI = %.10f\n",4*(area/(double)n_repeticoes));
printf("\n");
printf("================================================================================\n");
printf("\n");



}
 else if (tarefa== 'g')
{
printf("Digite o numero de pontos para o grafico : ");
scanf("%d", &qtd_grafico);
printf("Digite um fator de escala (int. entre 20 e 60) :");
scanf("%d", &fe);
printf("\n");
printf("\n");
printf("--------------------------------------------------------------------------------");
printf("Tarefa : Grafico da funcao raiz quadrada de (1-x*x) no intervalo [0.0, 1.0]");
printf("\n");
printf("\n");
printf("Numero de pontos = %d\n", qtd_grafico);
printf("Fator de escala = %d", fe);
printf("\n");
printf("\n");
printf("\n");
printf("\n");
imprime_grafico(a,b,M,qtd_grafico, fe);
printf("\n");
printf("\n");
printf("================================================================================\n");
printf("\n");

}
}

printf("\n");
printf("================================================================================\n");
printf("\n");
return 0;
}

