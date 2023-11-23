#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ehImpar(a) (a%2==1)

int busca_binaria(int *array, int size, int buscado);

int main() {
    int vetor[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    printf("Achamos (OU NAO) o elemento, está na posição %d",busca_binaria(vetor,12,12));
    return 0;
}

int busca_binaria(int *array, int size, int buscado){
    
    int inicio = 0,meio = (ehImpar(size) ? ((size -1) / 2)   : size/2 ) + inicio, fim = size -1, iteracoes = 1;
    do{
        // printf("\n*********\n\n");
        // printf("%da iteracao\n",iteracoes);
        // printf("%d é o size\n",size);
        // printf("%d é o ínicio\n",inicio);
        // printf("%d é o meio\n",meio);
        // printf("%d é o final\n",fim);
        // printf("*********\n\n");

        if(array[meio] == buscado )
            return meio;
        else if(array[meio] < buscado)
            inicio = meio+1;
        else if(array[meio] > buscado)
            fim = meio -1;

        size = (fim - inicio)+1;
        meio = (ehImpar(size) ? ((size -1) / 2)   : size/2 ) + inicio;
        iteracoes++;

    }while(size>=1);

    return -1;
}

