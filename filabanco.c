/*
 * filabanco.c
 *
 *  Created on: 05/11/2014
 *      Author: gardenia
 */
# include <stdio.h>
# include <stdlib.h>
struct nodo
{
       int num;
       int flag; //1 - Prefencial 2 - Comum.
       struct nodo *prox;
}typedef no;

void inicia(no *LISTA)
{
     LISTA->prox = NULL;
}
int listaVazia(no *LISTA)
{
    if(LISTA->prox==NULL)
       return 1;
    else
       return 0;
}

void gerarSenhaComum(no *LISTA,int senha)//a senha vem do i do main
{
     no *novo=(no *) malloc (sizeof(no));
     novo->num=senha;
     novo->flag=2;
     novo->prox=NULL;

     if(listaVazia(LISTA))
     {
           LISTA->prox=novo;
     }
     else
     {
          no *tmp = LISTA->prox;
          while(tmp->prox != NULL)
          {
                tmp = tmp->prox;//a flexa substitui o (*tmp).prox
          }
          tmp->prox = novo;
      }
}
void insereInicio(no *LISTA,int senha)
{                                //pessoa com necessidades entra
     no *novo = (no *) malloc (sizeof(no));
     novo->num=senha;
     novo->flag=1;
     novo->prox=NULL;
     if(listaVazia(LISTA))
     {
        LISTA->prox = novo;
     }
     else
     {
         no *inicio = LISTA->prox;
         LISTA->prox = novo;
         novo->prox = inicio;
     }
}
int verificaPrioridade(no *LISTA)
{
     int posicao;
	 if(listaVazia(LISTA))
	    printf("Lista Vazia!\n\n");
	    else
	    {
	        no *temp;
	        temp = LISTA->prox;
	        while(temp != NULL)
	        {
	        	 if(temp->flag==1)
	        	 {
	        		posicao++;
	        	 }
	        	 else
	        		 if(temp->flag==2)
	        		 {
	        		    break;
	        		 }
	        	     temp=temp->prox;
	        }
	  }
	  printf("Posicao eh %d\n",posicao);
      return posicao;
}

void gerarSenhaPrioridade(no *LISTA,int senha)// a senha vem do i do main
{
	  int posicao=0;
      posicao=verificaPrioridade(LISTA);
      if(listaVazia(LISTA))
      {
    	  no *novo=(no *) malloc(sizeof(no));
    	  novo->num=senha;
    	  novo->flag=1;
    	  novo->prox=NULL;
          LISTA ->prox=novo;
      }
      else
    	  if(posicao>0)
    	  {
    		  insereMeio(LISTA,senha,posicao);
    	  }
    	  else
    	  {
              insereInicio(LISTA,senha);
          }
 }

void ClienteAtendido (no *LISTA)
{
     if (!listaVazia(LISTA))
     {
          no *priNodo = LISTA->prox;
          LISTA->prox = priNodo->prox;
          free(priNodo);
      }
}
 void mostraLista(no *LISTA)
 {
     if(listaVazia(LISTA))
        printf("Lista Vazia!\n\n");
     else
     {
          no *temp;
          temp = LISTA->prox;
          while(temp != NULL)
          {
        	  	if(temp->flag==2)
        	  	{
        	  	     printf("%d\n", temp->num);
        	  	}
        	  	     else
        	  	    	 if(temp->flag==1)
        	  	    	 {
        	  	            printf("P%d\n", temp->num);}
                            temp = temp->prox;
                         }
           }
}
 void insereMeio(no *LISTA,int senha,int posicao)//nao consegui fazer funcionar o meio
 {
       int cont=0;
       no *novo = (no *) malloc(sizeof(no));
       novo->num=senha;
       novo->flag=1;

       if(listaVazia(LISTA))
       {
             LISTA->prox=novo;
       }
       else
       {
            no *antNodo, *atual;
            atual = LISTA->prox;
            while (atual->prox != NULL )
            {
                  antNodo = atual;//antnodo= anterior
                  atual = atual->prox;
                  cont++;
                  if(posicao==cont)
                  {
                          antNodo->prox = novo;
                          novo->prox = atual;
                  }
             }
      }
}

int main (int argc, char *argv[])
{
    int i,escolha;
    no *LISTA = (no *) malloc(sizeof(no));
    inicia(LISTA);
    // as senhas do codigo abaixo é o valor de i, entao elas saíram salteadas como exemplo: 1,P2,P3,4,5,P6
    for(i=1;i<=8;i++)
    {
      	printf("Escolha entre:\n 1 - Gerar Senha - Inserir Fim,\n 2 - GerarSenhaPrioridade - Inserir Inicio,\n 3 - Cliente Atendido - removerInicio\n 4-Mostrar Lista");
        scanf("%d",&escolha);
        if (escolha==1)
        {
            printf("Sua senha eh: %d\n",i);
            gerarSenhaComum(LISTA,i);
            mostraLista(LISTA);
        }
        else
            if(escolha==2)
            {
               printf("Sua senha eh: P%d\n",i);
               gerarSenhaPrioridade(LISTA,i);
               mostraLista(LISTA);
            }
            else
                if(escolha==3)
                {
                   ClienteAtendido(LISTA);
                   mostraLista(LISTA);
                }
                else
                    if(escolha==4)
                    {
                       mostraLista(LISTA);
                    }
      }
      printf("Sua fila eh: \n");
      mostraLista(LISTA);
      free(LISTA);
}


