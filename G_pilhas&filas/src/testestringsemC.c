// strncpy(dest, src + beginIndex, endIndex - beginIndex);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/str_utils.h"
int main(){
    // = malloc(sizeof(char)*(strlen(bianca)+1));
    char *bianca = "dddddd   o idddd";
    char *substr = trim('d', bianca);
    printf("Teu sobrenome é %s?",substr);
    printf("O tamanho é %d?",(int)strlen(bianca));
    free(substr);

}