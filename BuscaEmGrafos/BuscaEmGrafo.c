//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Número máximo de vértices
#define MAXV 8

//Estrutura de um nó
typedef struct str_no {
    int id;
    struct str_no *proximo;
} str_no;

int op;
//Grafo
struct str_no grafo[MAXV];

void menu_mostrar(){
    printf("\nEscolha uma opção:\n");
    printf("1 - Inserir aresta:\n");
    printf("2- Remover aresta\n");
    printf("0 - Sair\n\n");
    scanf("%d", &op);
}

void buscaEmProfundidade(struct str_no g[], int inicio, int alvo){
    int pilha[MAXV]; //pilha
    bool visitado[MAXV]; //nós visitados
    int indice = 0; //índice do topo da pilha
    bool achou = false; //flag de controle (não visitados)
    int corrente = inicio;
    struct str_no *ptr;
    int i;

    printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
    //Marcando os nós como ‘não visitados’.
    for(i=0; i <  MAXV; i++){ 		
        visitado[i] = false;
    }
    while(true){
    		
        //Nó corrente não visitado? Marque como visitado.
    		
        //Empilhe o nó corrente.
    		
        if(!visitado[corrente]){
            printf("VISITANDO: %d. \n", corrente);
        	if(corrente == alvo)
        	{			
                    printf("Alvo encontrado!\n\n\n");
                    return;
        	}			
                visitado[corrente] = true;
                pilha[indice] = corrente;
                indice++;
    	}	
        //Buscando por nós adjacentes, não visitados.
        achou = false;
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){	
            if(!visitado[ptr->id]){
                achou = true;
                break;
            }
        }	
        if(achou){		
            //Atualizando o nó corrente.
            corrente = ptr->id;
        }
        else{			
            //Não há vértices adjacentes não visitados.	
            //Tentando desempilhar o vértice do topo.        
            indice--;
            if(indice==-1){	
                //Não há mais vértices não visitados.
                printf("Encerrando a busca. \n");
        	    break;
            }		
        corrente = pilha[indice-1];
        }
    }
    return;
}

void buscaEmLargura(struct str_no g[], int inicio, int alvo){
    int fila[ MAXV]; //fila
    bool visitado[MAXV]; //nós visitados
    int indice = 0; //controle da fila
    bool achou = false; //flag (não visitados)
    int corrente = inicio;
    struct str_no *ptr;
    int i;
    printf("=-=-=-= Busca em Largura =-=-=-= \n");

    //Marcando os nós como ‘não visitados’.
    for(i=0; i <  MAXV; i++)
        visitado[i] = false;

    //Partindo do primeiro vértice.
    printf("VISITANDO: %d. \n", corrente);
    visitado[corrente] = true;
    fila[indice] = corrente;
    indice++;

    while(true){
        //Visitar os nós adjacentes ao vértice corrente	
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){	
            //Caso corrente ainda não tenha sido visitado:
            corrente = ptr->id;
            if(!visitado[corrente]){
                //Enfileira e marca como visitado.
                printf("VISITANDO: %d. \n", corrente);
                    if(corrente == alvo)
                    {
                        printf("Alvo encontrado!\n\n\n");
                        return;
                    }
                    visitado[corrente] = true;
                    fila[indice] = corrente;
                    indice++;
             }
        }
        //Caso a fila não esteja vazia:
        if(indice!=0)
        {
            //Atualizando vértice corrente.
            corrente = fila[0];
            //Desenfileirando o primeiro vértice.
            for(i=1;i<indice+1;i++)
                fila[i-1]=fila[i];
            indice--;
        }
        else
        {
            //Não há mais vértices para visitar.
            printf("Encerrando busca.\n");
            break;
        }
    }
    return;
}
int main()
{
    
}