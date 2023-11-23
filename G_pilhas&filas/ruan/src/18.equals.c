#include <stdio.h>
#include <stdbool.h>

#include "../include/no.h"

bool equals(No noA, No noB);

int main() {

    No no = gerarNoP(1,gerarNoP(2,gerarNoP(3,gerarNo(4))));
    No no2 = gerarNoP(1,gerarNoP(3,gerarNoP(2,gerarNo(4))));

    printf("São iguais? %d",equals(no,no2));

    killNo(no);
    killNo(no2);
}

bool equals(No noA, No noB) {
    

    if(sizeNo(noA) != sizeNo(noB))
        return false;
        
    
    for(int _ = 0; _ < sizeNo(noA); _++){

        if(noA->item != noB->item)
            return false;
            
        noA=noA->prox;
        noB=noB->prox;
    }
    return true;
}

