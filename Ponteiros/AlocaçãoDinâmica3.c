#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct NO{
    int cod;
    char nome[10];
}NO;

int main(){
    setlocale(LC_ALL, "Portuguese");

    NO *p; //Dinâmica

    //NO p; //Estática
    //p.cod=10;
    p = (NO*) malloc(sizeof(NO));

    if(p == NULL){
        printf("Erro de alocação de memória.\n");
        getchar();
        exit(0);
    }else{
        //Condição de alocação OK!
        printf("Insira o código:\n");
        scanf("%d", &p->cod);
        fflush(stdin);

         //Condição de alocação OK!
        printf("Insira o nome:\n");
        scanf("%s", &p->nome);
        fflush(stdin);

        getchar();
        system("clear");

        printf("Código: %d - Nome: %s\n", p->cod, p->nome);
    }
}
