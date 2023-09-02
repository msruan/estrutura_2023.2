#include <stdio.h>
char frase[20] = {"uma frase"};
void prints(char *string){
    for (int i = 0; string[i] != '\0'; i++){
        printf("%c\n",string[i]);
    }
    
}
int main(){
    prints(frase);
    
}

