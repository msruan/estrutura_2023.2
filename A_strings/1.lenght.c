#include <stdio.h>
char frase[20];

int lenght(char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++){}
    return i;
}
int main(){
    printf("Digite uma string:");
    scanf("%s",frase);
    int len = lenght(frase);
    printf("%d",len);
    
}

