#include <stdlib.h>
#include <stdlib.h>
//Constantes
#define maximo 10

//Variáveis
int tamanho = 0;
int grafo[maximo];

//Arestas
int ma[maximo][maximo];

int op=1;

//Define o número de vértices do Grafo
int grafo_tamanho()
{
    int tamanho;
    printf("Escolha a quantidade de vértices do grafo: ");
    scanf("%d", &tamanho);
    return tamanho;
}

//Inserir aresta
void grafo_inserir()
{
    int num1, num2;
    system("clear");
    printf("Escolha o vértice de origem entre 0 e %d: ", tamanho - 1);
    scanf("%d", &num1);
    printf("Escolha o vértice de destino entre 0 e %d: ", tamanho - 1);
    scanf("%d", &num2);
    if (num1 > tamanho - 1 || num2 > tamanho - 1 || num1 < 0 || num2 < 0)
    {
        printf("\nOs valores precisam estar entre 0 e %d\n\n", tamanho);
        getchar();
    }
    else
    {
        ma[num1][num2] = 1;
        ma[num2][num2] = 1;
    }
}

//Remover aresta
void grafo_remover()
{
    int num1, num2;
    system("clear");
    printf("Escolha o vértice de origem entre 0 e %d: ", tamanho - 1);
    scanf("%d", &num1);
    printf("Escolha o vértice de destino entre 0 e %d: ", tamanho - 1);
    scanf("%d", &num2);
    if (num1 > tamanho - 1 || num2 > tamanho - 1 || num1 < 0 || num2 < 0)
    {
        printf("\nOs valores precisam estar entre 0 e %d\n\n", tamanho);
        getchar();
    }
    else
    {
        ma[num1][num2] = 0;
        ma[num2][num1] = 0;
    }
}

//Função para desenhar o vetor de vértices
void grafo_desenhar()
{
    //Desenhando lista de vértices
    printf("Lista de vértices\n[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", grafo[i]);
    }
    printf("]\n\n");
}

//Função para desenhar a matriz de arestas
void grafo_desenhar_ma(){
    //Desenhando matriz de adjacências
    printf("Matriz de adjacencias\n[\n");
    for (int i = 0; i < tamanho; i++){
        for( int j = 0; j < tamanho; j++){
            printf("    %d", ma[i][j]);
        }
        printf("\n");
    }
    printf("]\n\n");
    getchar();
}

void menu_mostrar(){
    printf("\nEscolha uma opção:\n");
    printf("1 - Inserir aresta:\n");
    printf("2- Remover aresta\n");
    printf("0 - Sair\n\n");
    scanf("%d", &op);
}
int main()
{
    while ( tamanho <=0 || tamanho > maximo){
        tamanho = grafo_tamanho();
        if(tamanho <= 0 || tamanho > maximo){
            system("clear");
            printf("Escolha um valor entre 1 e %d!\n\n", maximo);
        }
        else{
            for(int i=0; i<tamanho; i++){
                grafo[i]=i;
            }
        }
    }
    while (op != 0){
        system("clear");
        grafo_desenhar();
        grafo_desenhar_ma();
        menu_mostrar();
        switch (op)
        {
        case 1:
            grafo_inserir();
            break;
        case 2:
            grafo_remover();
            break;
        }
    }
    getchar();
    return 0;
}