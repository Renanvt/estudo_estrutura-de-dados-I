#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *p;
    int vet[5];
    int i;
    int *j;
  


    p = vet;

    vet[0] = 10;
    vet[1] = 20;
    vet[2] = 30;
    vet[3] = 40;
    vet[4] = 50;

    i = p;

    for(i=0; i<8; i++){
        printf("%d ", p[i]);
    }
    printf("\n");

    
    j  = p + 5;
    while(p < j){
        printf("%d ", *p);
        p = p + 1; //P avança 4 bytes
    }
    printf("\n");

    
  
}