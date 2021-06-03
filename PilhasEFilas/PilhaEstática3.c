#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 3

typedef struct PILHA{
    int dados[TAM];
    int topo;
}PILHA;

void inicializaPilha(PILHA *p){
    int i;
    for(i=0; i<TAM; i++){
        p->dados[i]=0; //zera a pilha
    }
    p->topo=0;
}

void empilha(int dado, PILHA *p){
    if(p->topo == TAM){
        printf("Pilha cheia.\n");
        return;
    }else{
        p->dados[p->topo] = dado;
        p->topo++;
        return;
    }
}

int desempilha(PILHA *p){
    if(p->topo==0){
        printf("Pilha vazia.\n");
        return;
    }else{
        p->topo--;
        return p->dados[p->topo];
    }
}

void imprimePilha(PILHA *p){
    int i;
    printf("\nImprimindo a pilha:\n");
    for(i=0; i<p->topo; i++){
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    PILHA p1;

    inicializaPilha(&p1);

   
    empilha(10, &p1);
    empilha(20, &p1);
    empilha(30, &p1);
    empilha(40, &p1);

    imprimePilha(&p1);

    printf("\nDesempilhando: %d",desempilha(&p1));
    imprimePilha(&p1);
    printf("\nDesempilhando: %d",desempilha(&p1));
    imprimePilha(&p1);
    printf("\n");
    //system("pause");
    //system("clear");
}