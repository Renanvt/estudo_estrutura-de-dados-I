#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/*Na lista simples, os nós possuem apenas o endereço do próximo elemento. Dessa forma, podemos navegar do primeiro ao último
nó em um único sentido

Sò é possível saber onde começa uma lista dinâmica se tivermos uma variável do tipo ponteiro que aponte para o início da lista.
Sabemos se um nó é o último de uma lista se o atributo que aponta para o próximo elemento estiver com o valor nulo (null);
*/

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

/*Na lista duplamente encadeada, os nós possuem o endereço do elemento anterior e do elemento posterior. Dessa forma, podemos fazer a navegação
em ambos os sentidos, tanto do início para o final como do final para o início

O primeiro nó de uma lista duplamente encadeada tem dois ponteiros, assim como todos os demais nós. O ponteiro criado para apontar para o elemento anterior estará apontando para nulo, já que como é o primeiro nó, não há um nó anterior. O outro ponteiro estará apontando para o próximo nó. Se
por acaso só haja um nó nessa lista duplamente encadeada, ambos os ponteiros estarão apontando para nulo.
*/


typedef struct elemento Elemento;
//Lista duplamente encadeada
struct elemento{
    int valor;
    Elemento *proximo;
    Elemento *anterior;
};

//Criar 2 variáveis globais.
Elemento *inicio;
Elemento *fim;
int tamanho;

// Criando prototipos de função
void criaLista();
Elemento *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void inserePosicao(int valor, int posicao);
void removeInicio();
void removeFim();
void imprimeLista();
void imprimeListaContrario();

//Cria 2 elementos nulos na lista.
void criaLista(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

//Alocar um dado, e como funciona o esquema da lista duplamente encadeada:

Elemento *aloca(int valor){
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void removeInicio(){
    Elemento *atual = inicio;
    inicio = atual->proximo;
    inicio->anterior = NULL;
    tamanho--;
}

void removeFim(){
    Elemento *atual = fim;
    fim = atual->anterior;
    fim->proximo = NULL;
    tamanho--;
}

//Inserir no início da lista
void insereInicio(int valor){
   Elemento *novo = aloca(valor); //Cria novo elemento

   //Verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
   if(inicio == NULL){
       inicio = novo;
       fim = novo;
   }

   //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
   else{
       Elemento *atual; //Cria novo elemento caso tenha dado no inicio da lista
       atual = inicio;
       novo->proximo = atual;
       atual->anterior = novo;
       inicio = novo;
   }
   tamanho++;
}

//Inserir no fim da lista:
void insereFim(int valor) {
    Elemento *novo = aloca(valor); //cria novo elemento

    //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }
    	//Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
    else{
        Elemento *atual;
        atual = fim;
        novo->anterior = atual;
        atual->proximo = novo;
        fim = novo;
    }
    tamanho++;
}

//Inserir no inicio da lista:
void inserePosicao(int valor, int posicao){
    posicao = posicao-1;
	Elemento *novo = aloca(valor);   //criar novo elemento

	//verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	//Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.

	}else{
		Elemento *atual; //criar novo elemento caso tenha dado no inicio da lista.
		Elemento *tmp;
		int i;

		// Decidindo o ponto de incio
		if (posicao < (tamanho/2)) {
			atual = inicio;
			i = 0;
		} else {
			atual = fim;
			i = tamanho;
		}

		// Percorrer para encontrar a posição
		while ((i != posicao) && (i >= 0) && (i <= tamanho)) {
			if (i < posicao) {
				i++;
				atual = atual->proximo;
			} else if (i > posicao) {
				i--;
				atual = atual->anterior;
			}

			if (posicao == i) {
				// novo->anterior = 
				// novo->proximo =
				// atual = novo;
				printf("Valor antecessor ao quero inserir %d\n", atual->anterior->valor);
				printf("Valor proximo ao quero inserir %d\n", atual->proximo->valor);
			}
		}



	}
	// tamanho++;

}

//Função para imprimir a lista:
void imprimeLista(){
    Elemento *atual;
    atual = inicio;
    while(atual){
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
    printf("\n\n");
    getchar();
}

//Função para imprimir a lista:
void imprimeListaContrario(){
    Elemento *atual;
    atual = fim;
    while(atual){
        printf("%d\n", atual->valor);
        atual = atual->anterior;
    }
    printf("\n\n");
    getchar();
}


void menu(){
    printf("1 - Para inserir no início da lista;\n");
    printf("2 - Para inserir no fim da lista;\n");
    printf("3 - Para remover no início da lista;\n");
    printf("4 - Para remover no fim da lista;\n");
    printf("5 - Para imprimir o conteúdo da lista;\n");
    printf("6 - Para imprimir o conteúdo da lista ao contrário;\n");
    printf("0 - Para encerrar;\n\n");

}
int main(){
    setlocale(LC_ALL, "Portuguese");

    int op, dado;

    criaLista();

    do{
        system("clear");
        menu();
        scanf("%d", &op);
        fflush(stdin);
        system("clear");
        switch (op)
        {
        case 0:
            break;
        case 1:
            printf("Informe o dado do início:\n");
            scanf("%d", &dado);
            fflush(stdin);
            insereInicio(dado);
            getchar();
            break;
        case 2:
            printf("Informe o dado do final:\n");
            scanf("%d", &dado);
            fflush(stdin);
            insereFim(dado);
            getchar();
            break;
        case 3:
            removeInicio();
            break;
         case 4:
            removeFim();
            break;
         case 5:
            imprimeLista();
            getchar();
            break;
        case 6:
            imprimeListaContrario();
            getchar();
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    }while(op != 0);
}