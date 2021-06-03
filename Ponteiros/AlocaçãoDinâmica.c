/*Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com o tamanho lido e outro com o dobro desse tamanho. Preencha esses vetores respectivamente com potências de 2 e potências de 3.*/

/* Precisa incluir o comando no terminal: gcc ex05.c -o ex05 -lm */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int tamanho;
int *vetor1, *vetor2;
int main()
{
    int i;
    double aux;
    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tamanho);
    vetor1 = (int *)malloc(sizeof(int) * tamanho);
    vetor2 = (int *)malloc(sizeof(int) * (tamanho * 2));
    printf("\nVetor1: \n");
    for (i = 0; i < tamanho; i++)
    {
        vetor1[i] = (int) pow(2, i);
        printf("Posicao %d: %d\n", i, vetor1[i]);
    }
    printf("\nVetor2: \n");
    for (i = 0; i < tamanho * 2; i++)
    {
        vetor2[i] = pow(3, i);
        printf("Posicao %d: %d\n", i, vetor2[i]);
    }
    system("Pause");
    return (0);
}