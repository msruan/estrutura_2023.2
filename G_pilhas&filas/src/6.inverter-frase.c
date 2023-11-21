#include "../include/pilha_do_livro.h"

int main() {

    printf("\n***** INVERTER FRASE ******\n\n");
    int buffer;
    while(true){

        printf("Quantos caracteres tem sua frase? (Não inclua o \'\\0\'!)\n>>> ");
        scanf("%d",&buffer);  

        if(buffer > 0)
            break;
        printf("Você tem que digitar no mínimo um caracte!");
    }

    char c; 
    while ((c = getchar()) != '\n' && c != EOF);//limpar buffer

    char frase[buffer+1];
    printf("\nDigite uma frase: ");
    fgets(frase,buffer,stdin);

    Pilha P = gerarPilha(buffer);
    for(int i = 0; frase[i] != '\0' && frase[i] != '\n'; i++){
        push(frase[i],P);
    }

    printf("A frase invertida é: \"");
    while(!isEmpty(P)){
        printf("%c",pop(P));
    }
    printf("\"");
    
}