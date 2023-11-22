#include "../include/str_utils.h"

char *inverter(char* string){

    const int lenght = strlen(string)+1;

    Pilha P = gerarPilha(lenght);

    char *reverse = (char*)malloc(sizeof(char)*lenght);

    push('\0',P);

    for(int i = 0; string[i] != '\0' && string[i] != '\n'; i++){
        push(string[i],P);
    }

    for(int i = 0; i < lenght; i++){
        reverse[i] = pop(P);
    }

    kill(P);

    return reverse;
}

char *trim(char carac, char *string){
    
    // "  oi " -> 2 espaços em branco no inicio e 1 no final, o inicio vai ficar em 2...
    int inicio = 0;
    while (string[inicio] != '\0' && string[inicio]==carac)
    {
        inicio++;
    }//inicio = 2;
    int final = strlen(string) - 1;
    bool finalRuim = false;
    while(final > 0 && string[final] == carac){
        final--;
    }//final = 3;
    char *clearedStrUpped = (char *) malloc(sizeof(char) * (strlen(string)+1));
    strncpy(clearedStrUpped, string + inicio, final+1 - inicio);
    char *clearedStrReal = (char *) malloc(sizeof(char)*(strlen(clearedStrUpped+1)));
    strcpy(clearedStrReal,clearedStrUpped);
    free(clearedStrUpped);
    return clearedStrReal;
    

}

int contarOcorrencias(char carac, char *string){

    if(string == NULL) return -1;

    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == carac)
            count++;
    }return count;
}

// char **split(char separador, char* string){


// }