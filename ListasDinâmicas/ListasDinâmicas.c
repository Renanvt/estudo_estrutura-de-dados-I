#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Definindo a estrutura da lista encadeada
typedef struct no{
    int dado;
    struct no *proximo;
}no;

//Definindo variáveis
no* lista;
int op;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(no* lista);
void lista_inserir_2(int x, no *p);
void lista_remover(no* lista);
void lista_remover2(no *p);
void lista_mostrar(no* lista);  
void lista_mostrar_2(no* lista);
void lista_mostrar_3(struct no* lista);
void lista_mostrar_4(no *lista);


//Função Principal
int main(){
    srand(time(NULL));
    op=1;

    int valor = 10;
    no *lista2;
    lista2 = malloc(sizeof(no));
    lista2->proximo=NULL; //Cria uma lista encadeada vazia
    for(int i = 1; i<= 10; i++){
        lista_inserir_2(valor *i, lista2);
    }

    lista_mostrar_4(lista2);
    lista_remover2(lista2);
    lista_mostrar_4(lista2);

    getchar();

    lista = (no*) malloc(sizeof(no));
    lista->dado = 0;
    lista->proximo=NULL;

    while (op != 0){
        system("clear");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    getchar();
    return 0;
}

//Mostra o menu de opções
void menu_mostrar(){
    lista_mostrar_3(lista);
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da lista\n");
    printf("2 - Remover um item da Lista\n");
    printf("0 - Sair\n\n");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            lista_inserir(lista);
        break;
        case 2:
            lista_remover(lista);
        break;
    }
}

//Insere um elemento no final da Lista
void lista_inserir(no* lista){
    while(lista->proximo != NULL){
        lista = lista->proximo;
    }
    lista->proximo = (no*) malloc(sizeof(no));
    lista = lista->proximo;
    lista->dado = rand()%100;
    lista->proximo = NULL;
}

void lista_inserir_2(int x, no *p){
    no *novo;
    novo = malloc(sizeof(no));
    novo->dado = x;
    novo->proximo = p->proximo;
    p->proximo = novo;
}

//Remove um elemento da Lista
void lista_remover(no* lista){
    int dado;
    no* atual;
    atual = (no*) malloc(sizeof(no));
    printf("\n\nEscolha um dos itens:\n");
    scanf("%d", &dado);
    while((lista->dado != dado)){
        if (lista->proximo == NULL){
            break;
        }
        atual = lista;
        lista = lista->proximo;
    }
    if (lista->dado == dado){
        atual->proximo = lista->proximo;
    }
}

void lista_remover2(no *p){
    no *lixo;
    lixo = p->proximo;
    p->proximo = lixo->proximo;
    free(lixo);
}

//Desenha o conteúdo da Lista na tela
void lista_mostrar(no* lista){
    system("clear");
    while(1){
        printf("%d, ", lista->dado);
        if (lista->proximo == NULL){
            break;
        }
        lista = lista->proximo;
    }
}

//Desenha o conteúdo da Lista na tela
void lista_mostrar_2(no* lista){
    system("clear");
    while(lista->proximo != NULL){
        printf("%d, ", lista->dado);
        lista = lista->proximo;
    }
    printf("%d, ", lista->dado);
}

//Desenha o conteúdo da Lista na tela
void lista_mostrar_3(struct no* lista){
    system("clear");
    while(lista != NULL){
        printf("%d ", lista->dado);
        lista = lista->proximo;
    }
}

void lista_mostrar_4(no *lista){
    no *p;
    for(p = lista; p != NULL; p=p->proximo){
        printf("Valor: %d\n", p->dado);
    }
}