#include "../include/array_utils.h"
#include <stdio.h>

char **mapearc(char*(*funcao_transformadora)(char *string),char **array){

    for(int i = 0; array[i] != NULL; i++){
        printf("mapeado um...");
        char *temp = array[i];
        array[i] = funcao_transformadora(array[i]);
        free(temp);
    }

    return array;
}