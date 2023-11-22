#ifndef STR_UTILS_H
#define STR_UTILS_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pilha_do_livro.h"

char *inverter(char* string);

char *trim(char carac, char *string);

int contarOcorrencias(char carac, char *string);

char **split(char separador, char* string);

#endif