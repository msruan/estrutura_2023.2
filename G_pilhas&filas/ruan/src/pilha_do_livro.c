#include "../include/pilha_do_livro.h"

//    pilha
Pilha gerarPilha(int m){

	Pilha P = (Pilha)malloc(sizeof(struct pilha));
	P->max = m;
	P->topo = -1;
	P->item = (Itemp*)malloc(m*sizeof(Itemp));
	return P;
}

//  vaziap
bool isEmpty(Pilha P){

	return (size(P)==0);
}

//  cheiap
bool isFull(Pilha P){
	
	return (size(P) == P->max);
}

//   empilha
void push(Itemp x, Pilha P){

	if( P!=NULL && !isFull(P) ){
		P->item[size(P)] = x;
		P->topo++;
	}
	
}

Pilha copy(Pilha p){
	Pilha copia = gerarPilha(p->max);
	int topo = p->topo;
	while(topo>-1){
		push(p->item[topo],copia);
		topo--;
	}return copia;
}

//    desempilha
Itemp pop(Pilha P){
	
	if( P!=NULL && !isEmpty(P) ){

		P->topo--;
		return P->item[size(P)];
	}
	abort(); //return '\0';
}

//   destroip
void clear(Pilha P){

	if(P!=NULL && !isEmpty(P)){

		free(P->item);
	}
}

int size(Pilha P){
	return P->topo+1;
}

// Pilha reverse(Pilha P){
// 	Pilha reverse;
// 	while(!isEmpty(P)){
// 		push(pop(P),reverse);
// 	}
// 	return reverse;
// }