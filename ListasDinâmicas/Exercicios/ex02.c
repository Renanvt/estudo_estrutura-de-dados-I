#include <stdio.h>
#include <stdlib.h>

#define tam 10
struct pilha{
    int dados[tam];
    int primeiro;
    int ultimo;
};

struct pilha p;

void pop(){
    p.dados[p.ultimo-1]=0;
    p.ultimo--;
}

int main(){

    pop();
    pop();
    pop();

    getchar();
    return 0;
}