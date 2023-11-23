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

char **split(char separador, char* string){

    if(string == NULL) return NULL;

    

    // char *comTrim = trim(separador,string);
    char comTrim[strlen(string)+3];
    strcpy(comTrim,string);
    strcat(comTrim," ");
    printf("Depois do appendizinho qual é o tamanho?: [%d]",(int)strlen(comTrim));

    int palavras = contarOcorrencias(separador,string) + 1;//nao ta contando o do append... 
    printf("Número de ocorrências: %d",palavras);

    char **saida = (char**)malloc(sizeof(char *) * (palavras+1));
    saida[0] = NULL;
    saida[palavras] = NULL;

    int iteraPalavras = 0;
    
    int inicio = 0, iterador = 0, fim;

    while(comTrim[iterador]!='\0'){
        // printf("Entrou no while, oh yeah!");

        if(comTrim[iterador] == separador){
            printf("\nSeparador, oh delicia!");
            fim = iterador;
            saida[iteraPalavras] = (char *)malloc(sizeof(char)*(fim-inicio+1));
            strncpy(saida[iteraPalavras],comTrim + inicio, fim);
            saida[iteraPalavras][fim - inicio] = '\0'; 
            printf("\nValores de inicio e fim: %d, %d",inicio,fim);
            printf("\nO que mandei: %s",saida[iteraPalavras]);
            inicio = iterador+1;
            iteraPalavras++;
        }
        iterador++;
    }return saida;
}

int sizezinho(char **array){
    if(array == NULL) return -1;
    int size = 0, i = 0;
    while(array[i]!= NULL)
        size++;
    return size;
}

char *join (char separador, char **array){//vai deixar um espaco de memoria alocado a toa, mas no probles

    printf("join fudeu tudo");
    int lenght = 0;
    int sizeArr = sizezinho(array);
    No saida = NULL;
    for(int i = 0; i < sizeArr; i++){
        for(int j = 0; array[i][j]!='\0'; j++){
            saida = gerarNoP(array[i][j],saida);
        }saida = gerarNoP(separador,saida);
    }
    char *string = (char *) malloc(sizeof(char)*sizeNo(saida));
    saida = inverterNo(NULL, saida);
    int i = 0;
    while(saida!= NULL){
        string[i] = saida->item;
        saida = saida->prox;
        i++;
    }killNo(saida);
    return string;
}