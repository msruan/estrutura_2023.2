#include "../include/pilha_do_livro.h"
#include <string.h>
#include "colors.h"
#define ehImpar(n) (n%2==1)
#define isOpener(a) (a=='(' || a=='[' || a=='{')
#define isCloser(b) (b==')' || b==']' || b=='}')

int lenght(char *str);
bool match(char open, char close);
bool expressionMatch(char *expressao);
 
int main () {
    
    int buffer;
    printf(BLUE_BOLD);
    printf("\n**** EXPRESSOES ****\n");
    printf(RESET);
    printf("\n\nQuantos caracteres a cadeia conterá? (Não inclua o \'\\0\'!)\n>>> ");
    scanf("%d",&buffer);
    char c;
    while ((c = getchar()) != '\n' && c != EOF);

    if(ehImpar(buffer)){
        printf("Não tem como dar match se o número de caracteres for ímpar...");
        exit(0);
    }

    buffer++;//pra caber o '\0'
    char expressao[buffer];

    printf("\nDigite sua expressão: \n>>>");
    fgets(expressao,buffer,stdin);

    printf("Expressão está bem construída?");
    if(expressionMatch(expressao))
        printf(GREEN_BOLD_BRIGHT); 
        printf("SIM!!!\n\n"),
        printf(RESET); : "nao..."))
    printf("\n\n********************\n\n");
    
}

bool match(char open, char close){

    char par[] = {open, close, '\0'};

    return (!strcmp(par,"()") || !strcmp(par,"[]") || !strcmp(par,"{}"));
}

bool expressionMatch(char *expressao){

    int len = lenght(expressao);
    
    if(ehImpar(len))
        return false;
    
    Pilha openers = gerarPilha(len/2);
    
    for(int i = 0; i < len; i++){

        if(isOpener(expressao[i])){

            if(isFull(openers)){
                kill(openers);
                return false;
            }
            
            push(expressao[i],openers);
        }

        else if(isCloser(expressao[i])){   

            if(! match(pop(openers),expressao[i])){
                kill(openers);
                return false;
            }
        }    
    }
    kill(openers);
    return isEmpty(openers);
}

int lenght(char *str){

    if(str == NULL) return -1;
    int i;
    for(i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    ;
    return i;
}