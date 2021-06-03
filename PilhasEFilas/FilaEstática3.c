#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 3

typedef struct T_FILA{
    int dados[TAM];
    int fim;
}T_FILA;

void inicializaFila(T_FILA *f){
    int i;
    for(i=0;i<TAM;i++){
        f->dados[i] = 0;
    }
    f->fim = 0;
}

void enfileira(int dado, T_FILA *f){
    if(f->fim == TAM){
        printf("Fila está cheia. \n");
        return;
    }else{
        f->dados[f->fim] = dado;
        f->fim++;
    }
}

//O elemento que sai é sempre o elemento do início
int desenfileira(T_FILA *f){
    int dado, i;
    if(f->fim == 0){
        printf("Fila está vazia. \n");
        return;
    }else{
        dado = f->dados[0];
        for(i=0;i<f->fim;i++){
            f->dados[i] = f->dados[i+1];
        }
        f->fim--;
        return dado;
    }
}

void imprimeFila(T_FILA *f){
    int i;
    printf("Imprimindo a fila:\nINÍCIO-> ");
    for(i=0;i<f->fim;i++){
        printf("%d ", f->dados[i]);
    }
    printf(" <-FIM\n\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    T_FILA f1;
    inicializaFila(&f1);

    enfileira(10, &f1);
    enfileira(20, &f1);
    enfileira(30, &f1);
    enfileira(40, &f1);

    imprimeFila(&f1);
    desenfileira(&f1);
    imprimeFila(&f1);
    enfileira(40, &f1);
    imprimeFila(&f1);

    desenfileira(&f1);
    desenfileira(&f1);
    desenfileira(&f1);
    desenfileira(&f1);
    imprimeFila(&f1);




}