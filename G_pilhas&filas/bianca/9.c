#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char c){
    switch(c){
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1;
}

char *posfixa(char *e){
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for(int i = 0; e[i]; i++){
        if(e[i] == '(') empilha('(',P);
        else if(strchr("+-/*",e[i])){
            while(!emptyp(P) && prio(getTopo(P)) >= prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i],P);
        }
        else if(e[i] == ')'){
            while(getTopo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P);
        }
        
    }
}