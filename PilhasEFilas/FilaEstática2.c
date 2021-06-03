/*
Uma  agência  bancária  quer  inovar  seu  atendimento,  criando  mais  conforto  para  seus  clientes.  Para  isso,  foram  colocadas  diversas  cadeiras  na  recepção  do banco. Quando um cliente chega, o atendente lança no computador o seu nome  e  o  horário  que  chegou.  Assim  que  um  caixa  fica  livre,  a  recepcionista  olha no sistema e chama o primeiro cliente da fila. Dessa forma, é possível que os  clientes  esperem  confortavelmente  sentados  pelo  seu  atendimento,  não  importando o local onde se encontrem dentro da agência bancária. 

a) Faça  uma  estrutura  para  o  controle  da  fila.  Você  precisa  guardar  o  nome  e  a hora que o cliente chegou. Use um vetor para armazenar os dados e dois números inteiros, um para controlar o início e outro o final da fila.

b)  Defina a variável que será um vetor do tipo fila de clientes.

c) Crie  uma  função  enfileirar,  lembrando  que  é  preciso  verificar  se  há  espaço  na fila (o número de cadeiras na recepção é limitado).

d) Elabore  a  função  desenfileirar  cliente,  não  se  esqueça  de  que  é  necessário  verificar se ainda existem clientes para serem atendidos.

e) Faça uma função que apresente na tela a lista de todos os clientes que estão aguardando atendimento na recepção.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 5

typedef struct{
    char nome[20];
    int hr;
}tcliente;

struct tfila{
    tcliente dados[tam];
    int fim;
    int ini;
};

struct tfila fila;
int op;
//Inserir
void push_back();
//Remover
void pop();
void show_queue();
void show_options();

int main(){
    op=1;
    while (op>0 && op<4)
    {
        show_options();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            push_back();
            break;
        case 2:
            pop();
            break;
        case 3:
            show_queue();
            getchar();
            break;
        default:
            break;
        }
    }
    getchar();
    return 0;
}

void push_back(){
    if(fila.fim == tam){
        printf("Fila cheia, impossível enfileirar");
    }
    else{
        printf("\nDigite o nome do cliente: ");
        scanf("%s", &fila.dados[fila.fim].nome);
        printf("\nDigite a hora de chegada do cliente (Digite em formato de número): ");
        scanf("%d", &fila.dados[fila.fim].hr);
        fila.fim++;
    }
}

void pop(){
    if(fila.fim == fila.ini){
        printf("Fila vazia, impossível desenfileirar");
    }
    else{
        int i;
        for(i=0;i<tam;i++){
            //Pega a próxima posição e coloca na posição do interior
            fila.dados[i] = fila.dados[i+1];
        }
        fila.dados[fila.fim].hr = 0;
        strcpy(fila.dados[fila.fim].nome,"");
        fila.fim--;
        
    }
}

void show_queue(){
    int i;
    printf("\n[ ");
    for(i=0;i<tam;i++){
        printf("%s - ",fila.dados[i].nome);
    }
    printf("\n");
     for(i=0;i<tam;i++){
        printf(" %d -",fila.dados[i].hr);
    }
    printf("]\n\n");
    getchar();

}

void show_options()
{
    system("clear");
    printf("\nEscolha uma opção:\n");
    printf("1 - Enfileirar\n");
    printf("2 - Desenfileirar\n");
    printf("3 - Mostrar relatório de clientes\n");
    printf("0 - Sair\n");
}