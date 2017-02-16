/********************************************************************/
/**                                                                **/
/**  MAC0115 - Introducao a Computacao - IAG - 1o. sem. 2015       **/
/**  Nome do aluno: Renan Bueno Sanches                            **/
/**  Numero USP:8962102                 Curso:Geofisica            **/
/**  Exercicio-Programa 01                                         **/
/**                                                                **/
/********************************************************************/








#include <stdio.h>
int main(){
    /*A variavel numero2 preserva a variavel numero na hora do output do programa,
    a variavel counter guarda a quantia de pipetagens*/

    int numero,numero2, counter,

    /*Essas variaveis guardam a quantia de cada pipeta*/

	vol_50, vol_25, vol_10, vol_5, vol_1;
    printf("Digite um inteiro positivo representando um volume em mililitros:");
    scanf("%d", &numero);
    printf("\n");
    while(numero!=0){
        numero2=numero;
        counter=0, vol_50=0, vol_25=0, vol_10=0, vol_5=0, vol_1=0;

        /*Essa sequencia de while's dividem o numero entrado pelo usuario entre as pipetas*/

        while(numero>=50){
            vol_50=numero/50;
            numero=numero%50;
        }
        while(numero>=25&&numero<=50){
            vol_25=numero/25;
            numero=numero%25;
        }
        while(numero>=10&&numero<=25){
            vol_10=numero/10;
            numero=numero%10;
        }
        while(numero>=5&&numero<=10){
            vol_5=numero/5;
            numero=numero%5;
        }
        while(numero>=1&&numero<=5){
            vol_1=numero/1;
            numero=numero*-1;
        }
        counter=vol_50+vol_25+vol_10+vol_5+vol_1;

        /*Esse sequencia de if's da o output do programa de acordo com a quantia de pipetas, respeitando o singular e plural*/

		if(counter==1){
			printf("O volume de %d ml pode ser obtido com\n", numero2);
		}
		else if(counter>1){
			printf(" O volume de %d ml pode ser obtido com um minimo de %d pipetagens,\ndistribuidas da seguinte forma:\n",numero2, counter);
		}
        if(vol_50!=0&&vol_50==1){
            printf("    %d pipetagem  de 50 ml\n", vol_50);
        }
		 else if(vol_50!=0&&vol_50>1){
            printf("    %d pipetagens de 50 ml\n", vol_50);
        }
        if(vol_25!=0&&vol_25==1){
            printf("    %d pipetagem  de 25 ml\n", vol_25);
        }
		 else if(vol_25!=0&&vol_25>1){
            printf("    %d pipetagens de 25 ml\n", vol_25);
        }
        if(vol_10!=0&&vol_10==1){
            printf("    %d pipetagem  de 10 ml\n", vol_10);
        }
		 else if(vol_10!=0&&vol_10>1){
            printf("    %d pipetagens de 10 ml\n", vol_10);
        }
        if(vol_5!=0&&vol_5==1){
            printf("    %d pipetagem  de  5 ml\n", vol_5);
        }
		 else if(vol_5!=0&&vol_5>1){
            printf("    %d pipetagens de 5 ml\n", vol_5);
        }
        if(vol_1!=0&&vol_1==1){
            printf("    %d pipetagem  de  1 ml\n", vol_1);
        }
         else if(vol_1!=0&&vol_1>1){
            printf("    %d pipetagens de  1 ml\n", vol_1);
        }
        /*Essa sequencia de comandos permite que o programa continue rodando ateh que um zero seja entrado pelo usuario*/

        printf("\n\n");
		printf("Digite um inteiro positivo representando um volume em mililitros,\nou um zero para finalizar:");
        scanf("%d", &numero);
        printf("\n");
    }


return 0;}
