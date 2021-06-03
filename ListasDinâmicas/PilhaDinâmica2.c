#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Definindo a estrutura da pilha
typedef struct no
{
    int dado;
    struct no *proximo;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

//Definindo variáveis
int op;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op, pilha *p);
//push
void pilha_inserir(pilha *p);
//pop
void pilha_remover(pilha *p);
void pilha_mostrar(pilha *p);
void inicializaPilha(pilha *p)
{
    p->topo = NULL;
}
// void inicializaPilha(pilha *p){
//}

//Função Principal
int main()
{
    srand(time(NULL));
    pilha *p1 = (pilha *)malloc(sizeof(pilha));
    //no *novo = (no *)malloc(sizeof(no));
    //novo->dado = 0;
    //p1->topo = NULL;
    
    if (p1 == NULL)
    {
        printf("Erro de alocação da pilha. \n");
        exit(0);
    }
    else
    {
        inicializaPilha(p1);
        op = 1;
        while (op != 0)
        {
            system("clear");
            pilha_mostrar(p1);
            menu_mostrar(p1);
            scanf("%d", &op);
            menu_selecionar(op, p1);
        }
    }
    getchar();
    return 0;
}

//Mostra o menu de opções
void menu_mostrar()
{
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da pilha\n");
    printf("2 - Remover um item da pilha\n");
    printf("0 - Sair\n\n");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op, pilha *p)
{
    switch (op)
    {
    case 1:
        pilha_inserir(p);
        break;
    case 2:
        pilha_remover(p);
        break;
    }
}

//Insere um elemento no topo da pilha
void pilha_inserir(pilha *p)
{
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL)
    {
        printf("\nErro de alocação de nó .\n");
        return;
    }
    else
    {
        novo->dado = rand() % 100;
        novo->proximo = p->topo;
        p->topo = novo;
    }
}

//Remove um elemento da pilha
void pilha_remover(pilha *p)
{
    no *ptr = p->topo;
    int dado;
    if (ptr == NULL)
    {
        printf("\nPilha Vazia!!");
    }
    else
    {
        p->topo = ptr->proximo;
        ptr->proximo = NULL;
        dado = ptr->dado;
        free(ptr);
        // printf("\n\n%d removido!", dado);
    }
}

//Desenha o conteúdo da pilha na tela
void pilha_mostrar(pilha *p)
{
    no *ptr = p->topo;
    system("clear");
    if (ptr == NULL)
    {
        printf("\nPilha Vazia!!");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->dado);
            ptr = ptr->proximo;
        }
        printf("\n");
    }
}
