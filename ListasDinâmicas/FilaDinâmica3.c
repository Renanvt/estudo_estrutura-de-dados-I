#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Fila
{
    int num;           //conteúdo
    struct Fila *prox; //prox elemento da lista
} no;

int tam; //tamanho da fila

void inicia(no *f)
{
    f->prox = NULL; //primeiro elemento ( cabeça ) inicia com null
    tam = 0;
}

int vazia(no *f)
{
    if (f->prox == NULL)
        return 1; //se é a cabeça, então não tem nenhum valor
    else
        return 0;
}

no *aloca()
{
    no *novo = (no *)malloc(sizeof(no));
    if (!novo)
    { //se não conseguiu alocar
        printf("Sem memória suficiente!\n");
        exit(1);
    }
    else
    {
        printf("Novo elemento: ");
        scanf("%d", &novo->num);
        return novo;
    }
}

void insere(no *f)
{
    no *novo = aloca();
    novo->prox = NULL;

    if (vazia(f))
    {
        f->prox = novo; //armazena o endereço do novo nó em prox
    }
    else
    {
        no *tmp = f->prox;
        //Na fila, insere sempre no final, então faz uma estrutura de repetição para ir até o final da fila
        //Se eu perder o nó cabeça, eu me perco na fila
        while (tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    //Toda vez que insere um novo elemento eu incremento o tam. Com isso eu consigo saber quantos elementos estão dentro da fila
    tam++;
}
void libera(no *f)
{
    free(f);
}

no *retira(no *f)
{
    //Não tem como retirar elementos da fila, se não tem nada na fila, se não da um erro de implosão.
    if (f->prox == NULL)
    {
        //Fila está vazia
        printf("Fila vazia\n");
        return 0;
    }
    else
    {
        //Se tem elementos na fila
        //faz uma estrutura de repetição para ir até o final da fila
        no *tmp = f->prox;   //Pega o último elemento e armazena em um nó temporário
        f->prox = tmp->prox; //faz a troca. Pega o outro elemento e traz pra frente
        tam--;               // decremento o tamanho da fila
        libera(tmp);
        //free(tmp);
        return tmp;
        
    }
}

int exibe(no *f)
{
    if (vazia(f))
    {
        printf("Fila vazia!\n");
        return 1;
    }
    //Exibe os elementos
    no *tmp;
    tmp = f;
    //Código para não exibir a cabeça
    //tmp = tmp->prox;
    printf("Fila: ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n");
    return 1;
}

int main(void)
{
    no *f = (no *)malloc(sizeof(no));
    if (!f)
    {
        printf("Sem memória disponível!\n");
        exit(1);
    }
    else
    {
        inicia(f);
    }
    insere(f);
    insere(f);
    insere(f);
    exibe(f);
    retira(f);
    exibe(f);
}