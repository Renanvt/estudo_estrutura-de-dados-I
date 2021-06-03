#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    char conteudo;
    struct pilha *prox;
} no;

no *pi;

void criarpilha()
{
    pi = malloc(sizeof(no));
    pi->prox = NULL;
}

void empilhar(char x)
{
    no *novo;
    novo = malloc(sizeof(no));
    novo->conteudo = x;
    novo->prox = pi->prox;
    pi->prox = novo;
}

char desempilhar()
{
    no *p;
    p = pi->prox;
    char y = p->conteudo;
    if (p != NULL)
    {
        p->prox = pi->prox;
        free(p);
        //return y;
    }
}

void imprimir()
{
    no *p;
    p = pi;
    p = p->prox;
    for (; p != NULL; p = p->prox)
    {
        printf("%c\t\t%p\n", p->conteudo, &p->conteudo);
    }
}
int main()
{
    criarpilha();
    empilhar('a');
    empilhar('b');
    empilhar('c');
    imprimir();
    printf("%c", desempilhar());
    empilhar('d');
    imprimir();
    getchar();
    return 0;
}