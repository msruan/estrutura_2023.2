#include <stdio.h>
#include <stdbool.h>
char f1[10];
char f2[10];
int lenght(char *string);
bool eh_igual(char *string1, char *string2);

int main(){
    printf("Digite uma string: ");   
    scanf("%s",f1);
    printf("\nDigite outra string: ");
    scanf("%s",f2);
    bool sao_iguais = eh_igual(f1,f2);
    printf("%d",sao_iguais);
}
int lenght(char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++){}
    return i;
}
bool eh_igual(char *string1, char *string2){
    int len1 = lenght(string1);
    if (len1 != lenght(string2))
        return 0;
    for(int i = 0; i != (len1); i++){
        if (string1[i] != string2[i]){
            printf("%c",string1[i]);
            printf("%c",string2[i]);
            return 0;
        }
        printf("%c",string1[i]);
        printf("%c",string2[i]);
    }return 1;
}
