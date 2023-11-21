#ifndef FILA_DO_LIVRO_H
#define FILA_DO_LIVRO_H

#include <stdlib.h>
#include <stdio.h>

#define isNull(a) (a==NULL)

typedef char Itemf;
typedef struct fila {

    int max;
    int total;
    int inicio;
    int final;
    Itemf *item;


} *Fila;

Fila gerarFila(int maximo) {

    if(maximo <= 0){
        printf("Dê um valor positivo para o tamanho máximo da fila!");
        fflush(stdout);
        exit(1);
    }

    Fila fila = (Fila)malloc(sizeof(struct fila));
    fila->item = (Itemf *) malloc(sizeof(Itemf) * maximo);
    fila->total = 0;
    fila->max = maximo;
    fila->inicio = 0;
    fila->final = 0;

    return fila;
}

Itemf pop(Fila fila) {

    if(isNull(fila)){
        printf("Tentativa de pop numa fila nula!");
        fflush(stdout);
        exit(1);
    }
    else if(isEmpty(fila)){
        printf("Tentativa de pop numa fila vazia!");
        fflush(stdout);
        exit(1);

    }else{
        Itemf item = fila->item[fila->inicio-1];
        fila->inicio--;
    }

}

int isEmpty(Fila fila){ 

    if(fila == NULL) 
        return -1;
    return (fila->total==0);
}

int isFull(Fila fila){
    
    if(isNull(fila)) 
        return -1;
    return(fila->total == fila->max);
}

int indexOfEnd(int begin, int total, int capacidade){
   //ruan viado 
   //tá mas se for um vetor de 3, e o inicio tiver
   // ____________________
   // 0    |    1  |  2   |
   // cheio|  cheio| vazio|
   // 0    |    1  | 2    |
   // vago | cheio | cheio|
   // 0    |   1   |------|  
   // vago | cheio |
   // 0    |  1    |
   //cheio | vazio |       
   //---------------------- 
    if( begin > 0 && begin + 1 == total){
        return begin + 1;
    }

   // else if(begin )
    //return ((begin + total) - capacidade;
}   

void kill(Fila fila){

    if(isNull(fila))
        return; 

    free(fila->item);
    free(fila);
}
// divide pelo tamanho do bloco, isso corresponde ao numero da pagina virtual,e o resto corresponde ao deslocamento
//politicas de alocaçao de pagina nao vao cair na prova
//pode cair uma tabelinha da questao 23
//27 vai cair de certeza
//lavar roupa todo dia, que agonia....
//na quebrada da soleira, que chovia...
//æté sonhar de madrugda
//uma moça sem mancada
//uma mulher, não deve vacilar
//eu entendo a juventude
//ŧransviada
//e o auxilio luxuoso de um pandeiro
//cada cara representa uma mentira
//nascimento, vida e morte
//quem diria?
//ate sonhar 
#endif