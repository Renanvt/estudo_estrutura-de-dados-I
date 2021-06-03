/*Faça um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max. 100 caracteres) e armazeá-la num vetor. Imprimir a frase lida trocando as vogais, isto é, trocar 'a' pelo 'u', 'e' pelo 'o', 'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'. Usar uma função void (procedimento) para realizar a troca e uma função para realizar a impressão da frase trocada. A função deve ter como parâmetro um ponteiro char referente ao vetor. Dica: Use a função gets() da biblioteca string.h para realizar a leitura da frase. use o switch para realizar as trocas. Só considere as letras minúsculas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void troca(char *vet)
{
    int i, tam;
    printf("%d\n",vet);
    tam = strlen(vet);
    for (i = 0; i < tam; i++)
    {
    printf("%d\n",vet);
        switch (*vet)
        {
        case 'a':
            *vet = 'u';
            break;
        case 'e':
            *vet = 'o';
            break;
        case 'i':
            *vet = 'u';
            break;
        case 'o':
            *vet = 'a';
            break;
        case 'u':
            *vet = 'e';
            break;
        }
    vet++;
    }
}
void imprime(char *vet)
{
        int i;
        char *ptr;
        ptr = vet;
        printf("\n\n");
        for(i=0; i< strlen(vet); i++){
            printf("%c", *ptr);
            ptr++;
        }
}
int main()
{
    char vet[100];
    printf("\n\nDigite uma frase: ");
    gets(vet);
    troca(vet);
    imprime(vet);
    getchar();

    return 0;
}