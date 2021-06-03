#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *p;
    int x;

    p = &x;
    x = 10;
    printf("Endereço de x: %d\n", &x);
    printf("Endereço para qual p aponta: %d\n", p);
    printf("Conteúdo de x: %d\n", x);
    printf("Conteúdo de p: %d\n", *p);
    printf("\n\n");

    *p = 30;
    printf("Modificando o valor de *p para 30\n");
    printf("Conteúdo de x: %d\n", x);
    printf("Conteúdo de p: %d\n", *p);
}