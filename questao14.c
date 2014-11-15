/*
 * questao14.c
 *
 *  Created on: 29/10/2014
 *      Author: gardenia
 */
//Crie uma struct com as variáveis nome do usuário e saldo. Crie uma função para
//alimentar a struct, outra para executar operação de saque e uma terceira para operação de
//depósito. Utilize ponteiros para manipular os dados da struct.
#include <stdio.h>
#include <stdlib.h>
struct banco{
	char nome[30];
	float saldo;
	float deposito;
	float saque;
}typedef operacoes;
void alimenta(operacoes *pop)
{
	printf("Informe o nome do usuário\n");
	scanf ("%30[^\n]s%*c",&pop->nome);
	printf("Informe o valor do saldo\n");
	scanf("%f",&pop->saldo);
}
void saldo(operacoes *pop)
{
	printf("Informe valor de deposito\n");
	scanf("%f",&pop->deposito);
	printf("O valor do deposito realizado eh de %.2f\n",pop->deposito);
	printf("O valor do seu saldo atual eh de %.2f\n",(pop->deposito + pop->saldo));
}
void saque(operacoes *pop)
{
	printf("Informe valor que vc deseja sacar\n");
	scanf("%f",&pop->saque);
	printf("Saque realizado\n");
	printf("Seu saldo atual eh de %.2f\n",((pop->deposito + pop->saldo)-pop->saque));
}
int main()
{
	operacoes op;
	operacoes *pop;
	pop=&op;
	alimenta(pop);
	saldo(pop);
	saque(pop);
}
