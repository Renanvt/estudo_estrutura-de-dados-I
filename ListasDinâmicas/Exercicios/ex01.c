#include <stdio.h>
#include <stdlib.h>

/*A lista pode ser implementada de forma estática num vetor ou dinamicamente na memória. O que caracteriza a lista dinâmica é o fato
de seus nós possuírem o endereço do próximo elemento, permitindo assim a sua organização independente do índice do vetor*/
//O nó inicial de uma lista simples é sempre aquele que
//O nó final de uma lista simples é sempre aquele que aponta pra NULL

//ListaEncadeada
typedef struct no{
    int dado;
    struct no *proximo;
}no;

//Na lista duplamente encadeada consigo navegar antes e depois na memória
//No primeiro nó da lista o inicio e fim aponta pra null

//ListaDuplamenteEncadeada
typedef struct no{
    int dado;
    struct no *anterior;
    struct no *proximo;
}no;
int main(){

    getchar();
    return 0;
}