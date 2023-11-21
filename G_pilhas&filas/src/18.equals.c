#include "../include/no.h"

#include <stdio.h>
#include <stdbool.h>

bool equals(No noA, No noB) {
    

    if(size(noA) != size(noB))
        return false;
        
    
    for(int _ = 0; _ < size(noA); _++){

        if(noA->item != noB->item)
            return false;
            
        noA=noA->prox;
        noB=noB->prox;
    }
    return true;
    

}

int main() {

    No no = gerarNoP(1,gerarNoP(2,gerarNoP(3,gerarNo(4))));
    No no2 = gerarNoP(1,gerarNoP(3,gerarNoP(2,gerarNo(4))));
    printf("São iguais? %d",equals(no,no2));
    kill(no);
    kill(no2);
}