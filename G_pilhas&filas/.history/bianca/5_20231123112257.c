#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha p = pilha(100);
    empilha(8,p);
    while(getTopo(p)>0){
        empilha(getTopo(p)/2,p);
    }
    while(!emptyp(p)){
        printf("%f\n",desempilha(p));
    }

}