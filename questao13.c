#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Crie uma struct com as variáveis nome do livro e preço. Crie uma função para
//alimentar a struct. Crie também uma função para alterar o preço do livro. Considere que
//haverá uma promoção e que o livro terá 5% de desconto. Utilize ponteiros para manipular os
//dados da struct.

struct livraria{
	char nome[30];
	float preco;
}typedef livro;
void alimenta_livraria(livro *plivr)
{
	printf("Informe o nome do livro\n");
	scanf ("%30[^\n]s%*c",&plivr->nome);
	printf("Informe o preco do livro\n");
	scanf("%f",&plivr->preco);
}
void altera_preco(livro *plivr)
{
	printf("O novo preco com desconto eh: %.2f\n",plivr->preco*0.95);
}

int main()
{
	livro livr;
	livro *plivr;
	plivr=&livr;
	alimenta_livraria(plivr);
	altera_preco(plivr);
}
