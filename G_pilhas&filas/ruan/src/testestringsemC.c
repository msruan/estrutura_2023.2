// strncpy(dest, src + beginIndex, endIndex - beginIndex);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/str_utils.h"
void mostrarstr(char *string){
    if(string == NULL) {
        printf("Você tentou passar uma string nula para o mostrastr...");
        fflush(stdout);
        exit(1);
    }
    for(int i = 0; string[i]!='\0';i++){
        printf("%c",string[i]);
    }
}
int main(){
    printf("Do you hate me?");
    // = malloc(sizeof(char)*(strlen(bianca)+1));
    char *bianca = "Bianca Bezerra Nunes Oliveira";
    char **nomes = split(' ',bianca);
    for(int i = 0; nomes[i] != NULL; i++){
        printf("Nome: {%s}\n",nomes[i]);
        free(nomes[i]);
    }
    free(nomes);

}