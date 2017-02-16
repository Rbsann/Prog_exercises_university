/********************************************************************/
/**                                                                **/
/**  MAC0115 - Introducao a Computacao - IAG - 1o. sem. 2015       **/
/**  Nome do aluno: Renan Bueno Sanches                            **/
/**  Numero USP:8962102                 Curso:Geofisica            **/
/**  Exercicio-Programa 02                                         **/
/**                                                                **/
/********************************************************************/



#include <stdio.h>
int main()
{

	int qtd_ref=0,preco_ref=0;  /*variaveis que guardam a quantidade inicial da maquina e o preco dos refrigerantes*/
	int qtd_100=0,qtd_50=0,qtd_10=0,qtd_5=0,qtd_1=0;  /*variaveis que guardam a quantidade de cada moeda inicialmente*/
	int valor_maq=0;    /*Variavel que guarda o valor total inicial da maquina*/
	int qtd_pedida=0;    /*Variavel que guarda a quantidade de refrigerantes pedidos*/
	int preco_total=0; /*preco do refrigerante x quantidade de refrigerantes*/
	int valor_inserido=1; /*variavel pra guardar as moedas inseridas pelo usuario, essa variavel eh inicializada em 1 para o loop funcionar*/
	int qtd_ins_100=0,qtd_ins_50=0,qtd_ins_10=0,qtd_ins_5=0,qtd_ins_1=0; /*variaveis pra guardar cada moeda guardada pelo usuario*/
	int valor_pago=0; /*Variavel que guarda o valor real inserido, convertido das moedas para um soh valor*/
	int total_100=0,total_50=0,total_10=0,total_5=0,total_1=0; /*Variaveis que guardam a quantidade de moedas de cada valor apos o usuario inserir moedas*/
	int troco=0; /*Variavel pra guardar o valor do troco*/
	int troco_100=0,troco_50=0,troco_10=0,troco_5=0,troco_1=0; /*Guarda o valor exato de cada moeda de troco*/
	int valor_final=0; /*Valor final restante na maquina*/
	int valor_final_100=0,valor_final_50=0,valor_final_10=0,valor_final_5=0,valor_final_1=0; /*Valor final de cada moeda*/

	printf(" Situacao inicial da maquina: \n\n");
	printf(" Quantidade de refrigerantes para venda: ");
	scanf("%d", &qtd_ref);
    printf("\n");
	printf(" Preco de um refrigerante em centavos: ");
	scanf("%d", &preco_ref); /*Usuario entra com valor do refrigerante e qtde de refrigerantes*/
    printf("\n");
	printf(" Quantidade de moedas, de cada valor, no caixa da maquina:"); /*Usuario entra com a qtde de cada moeda presente*/
    printf("\n");
	printf("     1 real     : ");
	scanf("%d", &qtd_100);
	printf("    50 centavos : ");
	scanf("%d", &qtd_50);
	printf("    10 centavos : ");
	scanf("%d", &qtd_10);
	printf("     5 centavos : ");
	scanf("%d", &qtd_5);
	printf("      1 centavo : ");
	scanf("%d", &qtd_1);
	printf("\n");
	valor_maq=qtd_100*100+qtd_50*50+qtd_10*10+qtd_5*5+qtd_1; /*Calculo do valor total da maquina*/
	printf(" Valor total da maquina: %d centavos (%d reais e %d centavos).\n",valor_maq,valor_maq/100,valor_maq%100);
	printf("\n");
	/*Primeira parte do programa finalizada (situacao inicial), comeco da segunda parte*/
	printf(" ===========================================================================\n");
	printf("\n");
	printf(" Um pedido de compra:\n");
	printf("\n");
	printf(" Quantos refrigerantes deseja comprar (1 a 9)? "); /*Usuario entra com qtos refrigerantes quer comprar*/
	scanf("%d", &qtd_pedida);
	preco_total=qtd_pedida*preco_ref; /*Calculo do valor total do pedido*/
	printf("\n");
	if(qtd_pedida>qtd_ref) /*Se a quantidade de refrigerantes pedida for maior a compra nao pode ser realizada*/
	{
		printf(" ;( - Pedido de compra nao realizado: existem apenas %d refrigerantes.\n", qtd_ref);
		printf("\n");
	}
	else /*Caso contrario o programa informa ao usuario o quanto ele devera pagar e qto recebera de troco, caso exista troco*/
	{
		printf(" Voce deve pagar %d centavos (%d reais e %d centavos).\n", preco_total, preco_total/100, preco_total%100);
		printf("\n");
		printf(" Valores (em centavos) das moedas que voce inseriu (seguidas por um zero):\n");

		while(valor_inserido!=0) /*Esse loop guarda todas as moedas inseridas pelo usuario */
		{
			scanf( "%d", &valor_inserido);
			if(valor_inserido==100){
				qtd_ins_100++;
			}
			if(valor_inserido==50){
				qtd_ins_50++;
			}
			if(valor_inserido==10){
				qtd_ins_10++;
			}
			if(valor_inserido==5){
				qtd_ins_5++;
			}
			if(valor_inserido==1){
				qtd_ins_1++;
			}

		}
		printf("\n");
		printf(" Quantidade de moedas, de cada valor, que voce inseriu:"); /*Informa ao usuario as moedas inseridas*/
		printf("\n");
		printf("    %d moeda(s) de 1 real\n", qtd_ins_100);
		printf("    %d moeda(s) de 50 centavos\n", qtd_ins_50);
		printf("    %d moeda(s) de 10 centavos\n", qtd_ins_10);
		printf("    %d moeda(s) de 5 centavos\n", qtd_ins_5);
		printf("    %d moeda(s) de 1 centavo\n", qtd_ins_1);
		printf("\n");
		valor_pago=qtd_ins_100*100+qtd_ins_50*50+qtd_ins_10*10+qtd_ins_5*5+qtd_ins_1; /*Calculo do valor inserido total,
		convertido pra soh um numero*/
		total_100=qtd_ins_100+qtd_100; /*Calculo do total de cada moeda na maquina*/
		total_50=qtd_ins_50+qtd_50;
		total_10=qtd_ins_10+qtd_10;
		total_5=qtd_ins_5+qtd_5;
		total_1=qtd_ins_1+qtd_1;
		printf(" Valor total pago: %d centavos (%d reais e %d centavos).\n", valor_pago, valor_pago/100, valor_pago%100);
		printf("\n");
		if(valor_pago<preco_total) /*Caso o valor pago seja menor que o preco total dos refrigerantes,
            a maquina nao executa a compra*/
		{
			printf(" ;( - Pedido de compra cancelado: voce pagou a menos.\n");
			printf("      As moedas que voce inseriu serao devolvidas.\n");
			printf("\n");

		}
		else if(valor_pago>=preco_total) /*Se o valor pago eh maior que o preco total ha um troco*/
		{
	troco=valor_pago-preco_total; /*Troco eh definido pela subtracao do valor pago do preco total*/
	printf("\n");
	if(troco==0) /*Se o valor do troco eh inicialmente 0 nada eh devolvido ao usuario, a compra eh bem sucedida */
	{
		printf(" Nao tem troco: pagou valor exato.\n");
		printf("\n");
		printf(" :) - Pedido de compra bem sucedido!\n");
		printf("\n");
	}
	else if(troco>0) /*Se o troco eh inicialmente maior que 0,
        comeca-se os calculos do valor de cada moeda que sera devoldida ao usuario*/
	{
		printf(" Existe um troco de %d centavos.\n", troco);
		printf("\n");
		if(troco>=100&&total_100>0) /*Calcula o troco de moedas de 1 real, se possivel*/
		{
			while(troco>=100&&total_100>0){
				total_100=total_100-troco_100;
				troco=troco-100;
				troco_100++;


			}
		}
		if(troco>=50&&total_50>0) /*Calcula o troco de moedas de 50 centavos, se possivel*/
		{
			while(troco>=50&&total_50>0){
				total_50=total_50-troco_50;
				troco=troco-50;
                troco_50++;
			}
		}
		if(troco>=10&&total_10>0) /*Calcula o troco de moedas de 10 centavos, se possivel*/
		{
			while(troco>=10&&total_10>0){
				total_10=total_10-troco_10;
				troco=troco-10;
				troco_10++;



			}
		}
		if(troco>=5&&total_5>0) /*Calcula o troco de moedas de 5 centavos, se possivel*/
		{
			while(troco>=5&&total_5>0){
				total_5=total_5-troco_5;
				troco=troco-5;
				troco_5++;


			}
		}
		if(troco>=1&&total_1>0) /*Calcula o troco de moedas de 1 centavo, se possivel*/
		{
			while(troco>=1&&total_1>0){
				total_1=total_1-troco_1;
				troco=troco-1;
				troco_1++;


			}
		}
		if (troco>0) /*Como a variavel inicial troco vai sendo subtraida a cada iteracao do calculo do troco de cada moeda,
		se esse valor for maior que 0 nao ha moedas especificas o suficiente para que o usuario receba seu valor devido,
		e, portanto a compra eh mal sucedida*/
		{
			printf(" ;( - Pedido de compra cancelado: a maquina nao pode fornecer o troco.\n");
			printf("      As moedas que voce inseriu serao devolvidas.\n");
			printf("\n");

		}
		else if(troco==0) /*Se o valor da variavel troco resulta em zero ha moedas suficiente para retornar ao usuario o excedente*/
		{
			printf(" A maquina fornece o troco da seguinte forma:\n");
			/*Output especifico do troco de cada moeda*/
			if (troco_100>0)
			{
				printf("    %d moeda(s) de 1 real\n",troco_100);
			}
			if (troco_50>0)
			{
				printf("    %d moeda(s) de 50 centavos\n",troco_50);
			}
			if (troco_10>0)
			{
				printf("    %d moeda(s) de 10 centavos\n",troco_10);
			}
			if (troco_5>0)
			{
				printf("    %d moeda(s) de 5 centavos\n",troco_5);
			}
			if (troco_1>0)
			{
				printf("    %d moeda(s) de 1 centavo\n",troco_1);
			}
			printf("\n");
			printf(" :) - Pedido de compra bem sucedido!\n");
			printf("\n");
			}

		}
		}

	}
	/*Final da segunda parte do programa (pedido de compra), comeco da terceira parte*/
printf(" ===========================================================================\n");
if(qtd_pedida>qtd_ref) /*Se a quantidade pedida for maior do que a quantidade presente de refrigerante
o programa nao imprime nada na terceira parte do programa, de acordo com o exemplo disponivel no enunciado do EP*/
{
    printf("\n");
}
else if(qtd_pedida<=qtd_ref) /*Caso a quantia pedida seja menor ou igual que a quantidade disponivel o programa da um output na terceira parte do programa*/
{
if(troco>0||valor_pago<preco_total) /*Se a compra foi mal sucedida por falta de troco ou por pagamento errado,
a situacao final da maquina eh igual a inicial*/
{
printf("\n");
printf(" Situacao final da maquina:\n");
printf("\n");
printf(" Quantidade final de moedas, de cada valor, no caixa da maquina:\n");
printf("     1 real     :  %d moeda(s)\n", qtd_100);
printf("    50 centavos :  %d moeda(s)\n",qtd_50);
printf("    10 centavos :  %d moeda(s)\n",qtd_10);
printf("     5 centavos :  %d moeda(s)\n",qtd_5);
printf("     1 centavo  :  %d moeda(s)\n",qtd_1);
printf("\n");
printf(" Valor total na maquina: %d centavos (%d reais e %d centavos).\n", valor_maq, valor_maq/100,valor_maq%100);
printf("\n");
printf(" Restam %d refrigerantes para venda.", qtd_ref);
printf("\n");


}
else if(troco==0)/*Caso a compra tenha sido bem sucedida o programa calcula a situacao final das moedas na maquina*/
{
valor_final_100=(qtd_ins_100+qtd_100)-troco_100; /*Calculo de quantas moedas de cada valor ainda restam na maquina*/
valor_final_50=(qtd_ins_50+qtd_50)-troco_50;
valor_final_10=(qtd_ins_10+qtd_10)-troco_10;
valor_final_5=(qtd_ins_5+qtd_5)-troco_5;
valor_final_1=(qtd_ins_1+qtd_1)-troco_1;
valor_final=valor_final_100*100+valor_final_50*50+valor_final_10*10+valor_final_5*5+valor_final_1; /*Calculo do valor final das moedas*/
printf("\n");
printf(" Situacao final da maquina:\n");
printf("\n");
printf(" Quantidade final de moedas, de cada valor, no caixa da maquina:\n");
printf("     1 real     :  %d moeda(s)\n", valor_final_100);
printf("    50 centavos :  %d moeda(s)\n",valor_final_50);
printf("    10 centavos :  %d moeda(s)\n",valor_final_10);
printf("     5 centavos :  %d moeda(s)\n",valor_final_5);
printf("     1 centavo  :  %d moeda(s)\n",valor_final_1);
printf("\n");
printf(" Valor total na maquina: %d centavos (%d reais e %d centavos).\n", valor_final, valor_final/100,valor_final%100);
printf("\n");
printf(" Restam %d refrigerantes para venda.", qtd_ref-qtd_pedida);
printf("\n");

}
}
return 0;
}
