#ifndef PILHA_DO_LIVRO_H
#define PILHA_DO_LIVRO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha_do_livro.h"

typedef char Itemp; //Itemp

typedef struct pilha{

	int max;
	int topo;
	Itemp *item;

}*Pilha; 

//    pilha
Pilha gerarPilha(int m);

//  vaziap
bool isEmpty(Pilha P);

//  cheiap
bool isFull(Pilha P);

//   empilha
void push(Itemp x, Pilha P);

//    desempilha
Itemp pop(Pilha P);

//   destroip
void kill(Pilha P);

int size(Pilha P);

// Pilha reverse(Pilha P){
// 	Pilha reverse;
// 	while(!isEmpty(P)){
// 		push(pop(P),reverse);
// 	}
// 	return reverse;
// }
#endif