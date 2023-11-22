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

Fila gerarFila(int maximo); 

Itemf pop(Fila fila);
   
void push(Itemf item, Fila fila);

int isEmpty(Fila fila);

int isFull(Fila fila);

int getindexOfEnd(Fila fila);

void getStatus (Fila fila, char *titulo);


void kill(Fila fila);// divide pelo tamanho do bloco, isso corresponde ao numero da pagina virtual,e o resto corresponde ao deslocamento
//politicas de alocaçao de pagina nao vao cair na prova
//pode cair uma tabelinha da questao 23
//27 vai cair de certeza

#endif