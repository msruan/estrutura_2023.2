#include "../include/pilha_do_livro.h"
#include "../include/str_utils.h"
#include "../include/array_utils.h"
char *inverterPalavra(char *frase){
    
    Pilha pilha = gerarPilha(strlen(frase));
    for(int i = 0; i < strlen(frase); i++){
        push(frase[i],pilha);
    }
    char *inversa = (char *)malloc(sizeof(char) * strlen(frase) + 1);
    for(int j = 0; j < strlen(frase); j++){
        inversa [j]= pop(pilha);
    }inversa[strlen(frase) + 1]= '\0';
    return inversa;
}

char **inverterFrase(char *frase){
    return mapearc(inverterPalavra, split(' ', frase));
}

int main() {

    printf("\n***** INVERTER FRASE ******\n\n");
    int buffer;
    while(true){

        printf("Quantos caracteres tem sua frase? (Inclua o \'\\0\'!)\n>>> ");
        scanf("%d",&buffer);  

        if(buffer > 0)
            break;
        printf("Você tem que digitar no mínimo um caracte!");
    }

    char c; 
    while ((c = getchar()) != '\n' && c != EOF);//limpar buffer

    char frase[buffer+5];
    printf("\nDigite uma frase: ");
    fgets(frase,buffer,stdin);
   
    char **invertida =inverterFrase(frase);
    printf("A frase invertida é: \"");
    mostrarString(invertida);
    printf("\"");
    killString(invertida);
    free(invertida);
  
}
//gerar uma pilha para cada palavra
//gerar uma pilha para essas pilhas
//inverter a pilha de pilhas