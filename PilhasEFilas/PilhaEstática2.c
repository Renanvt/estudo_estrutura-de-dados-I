/*
Quando um livro é devolvido na Biblio-teca do Unicesumar, o funcionário responsável  pelo  recebimento  coloca  o  livro em cima de uma pilha de livros na mesa  ao  lado  da  recepção.  O  auxiliar  de  bibliotecário  pega  o  livro  do  topo  da pilha, verifica o seu código e leva-o para o seu devido local no acervo.No atual sistema de informação, é possível verificar se o livro está disponível ou  se  está  emprestado.  Entretanto  o  livro que acabou de ser devolvido ainda  não  se  encontra  na  prateleira,  pois  existe  um  intervalo  de  tempo  entre  a  devolução  do  mesmo  e  o  momento  em que ele é guardado na estante.A sugestão do departamento de TI é de criar um programa que faça o controle na  pilha,  assim,  pode-se  verificar  se  o  livro  ainda  não  foi  guardado  e  qual  a  sua  posição  dentro  da  pilha  de  livros  que aguardam ao lado da recepção.

a) Crie uma estrutura para a pilha de livros. Lembre-se de que ela tem que ter um  vetor  para  armazenar  os  dados  (código,  nome  do  livro  e  autor)  e  dois  números inteiros, um para controlar o início e outro o final da pilha.
b)  Defina a variável que será um vetor do tipo pilha de livros.
c) Faça  uma  função  de  empilhamento,  lembrando-se  de  verificar  se  a  pilha  atingiu o tamanho máximo de livros (a mesa não aguenta muito peso).
d) Crie uma função para desempilhamento de livros. Não se esqueça de que é necessário verificar se ainda existem livros para ser guardados.
e) Elabore uma função que apresente na tela a lista de todos os livros que se encontram empilhados ao lado da recepção.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 5

//Estrutura do livro
typedef struct
{
    int cod;
    char nome[50];
    char autor[50];
} tlivro;

//Estrutura da pilha
struct tpilha
{
    tlivro dados[tam];
    int ini;
    int fim;
};

//Variáveis globais
struct tpilha pilha;
int op;

void stack_up();
void unstack();
void show_books();
void show_options();

int main()
{
    op=1;
    while (op>0 && op<4)
    {
        show_options();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            stack_up();
            break;
        case 2:
            unstack();
            break;
        case 3:
            show_books();
            getchar();
            break;
        default:
            break;
        }
    }
    getchar();
    return 0;
}

//Adicionar um elemento no final da pilha
void stack_up()
{
    if (pilha.fim == tam)
    {
        printf("\nImpossível empilhar, pois a pilha já está cheia");
    }
    else
    {
        printf("\nDigite o código do livro: ");
        scanf("%d", &pilha.dados[pilha.fim].cod);
        printf("\nDigite o nome do livro: ");
        scanf("%s", &pilha.dados[pilha.fim].nome);
        printf("\nDigite o autor do livro: ");
        scanf("%s", &pilha.dados[pilha.fim].autor);
        pilha.fim++;
    }
}
//Retirar o último elemento da Pilha
void unstack()
{
    if (pilha.fim == pilha.ini)
    {
        printf("\nImpossível desempilhar, pois a pilha já esta vazia");
        system("pause");
    }
    else
    {
        pilha.dados[pilha.fim - 1].cod = 0;
        strcpy(pilha.dados[pilha.fim - 1].nome, "");
        strcpy(pilha.dados[pilha.fim - 1].autor, "");
        pilha.fim--;
    }
}

//Mostrar o conteúdo da Pilha
void show_books()
{
    int i;
    printf("[ ");
    for (i = 0; i < tam; i++)
    {
        printf("%d - ", pilha.dados[i].cod);
    }
    printf(" ]\n\n");
    getchar();
}

void show_options()
{
    system("clear");
    printf("Bem vindo a estante de livros");
    printf("\nEscolha uma opção:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("3 - Mostrar códigos de livros\n");
    printf("0 - Sair\n");
}
