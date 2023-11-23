#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ehImpar(a) (a%2==1)

int busca_binaria(int *array, int size, int buscado){
    
    int inicio = 0,meio = (ehImpar(size) ? ((size -1) / 2)   : size/2 ) + inicio, fim = size -1, iteracoes = 1;
    do{
        printf("\n*********\n\n");
        printf("%da iteracao\n",iteracoes);
        printf("%d é o size\n",size);
        printf("%d é o ínicio\n",inicio);
        printf("%d é o meio\n",meio);
        printf("%d é o final\n",fim);
        printf("*********\n\n");

        if(array[meio] == buscado ){
            return meio;
        }else if(array[meio] < buscado){
            inicio = meio+1;
        }else if(array[meio] > buscado){
            fim = meio -1;
        }
        size = (fim - inicio)+1;
        meio = (ehImpar(size) ? ((size -1) / 2)   : size/2 ) + inicio;
        iteracoes++;
    }while(size>=1);
    return -1;

}

// int busca_binaria(int *array, int inicio, int fim, int buscado){

//         int meio = fim/2;
//         printf("Entrando na busca binária...\n");
//         printf("Valores:\nInicio: %d\nFim: %d\nMeio: %d\n",inicio,fim,meio);
//         printf("\n\n");

//         if (array[meio] == buscado) {
//             printf("ACHAMOS!!!!");
//             printf("Valores:\nInicio: %d\nFim: %d\nMeio: %d\n",inicio,fim,meio);
//             printf("\n\n");

//             return inicio + meio;
//         }
            
//         else if( array[meio] < buscado  ){

//             printf("Ta pra cima...");
//             printf("Valores:\nInicio: %d\nFim: %d\nMeio: %d\n",inicio,fim,meio);
//             printf("\n\n");
//             sleep(1);

//             return busca_binaria(array, meio, fim, buscado);
//         }

//         else if( array[meio] > buscado  ){

//             printf("Ta pra baixo...");
//             printf("Valores:\nInicio: %d\nFim: %d\nMeio: %d\n",inicio,fim,meio);
//             printf("\n\n");
//             return busca_binaria(array, inicio ,fim-meio, buscado);
//         }
// }

int main() {
    int paulo[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    printf("Achamos (OU NAO) o elemento, está na posição %d",busca_binaria(paulo,12,12));
    return 0;
}