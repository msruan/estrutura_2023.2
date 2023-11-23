#include "../include/fila_do_livro.h"

Fila gerarFila(int maximo) {

    if(maximo <= 0){
        printf("Dê um valor positivo para o tamanho máximo da fila!");
        fflush(stdout);
        exit(1);
    }

    Fila fila = (Fila)malloc(sizeof(struct fila));
    fila->item = (Itemf *) malloc(sizeof(Itemf) * maximo);
    fila->total = 0;
    fila->max = maximo;
    fila->inicio = 0;

    return fila;
}

Itemf pop(Fila fila) {

    if(isNull(fila)){
        printf("Tentativa de pop numa fila nula!");
        fflush(stdout);
        exit(1);
    }
    else if(isEmpty(fila)){
        printf("Tentativa de pop numa fila vazia!");
        fflush(stdout);
        exit(1);

    }else{
        const int lastIndex = fila->max - 1;
        Itemf item = fila->item[fila->inicio];
        // printf("O item q tá cessando é o do index: %d",fila->inicio);

        if(fila->total == 1){
            fila->inicio = 0;

        }else if(fila->inicio == 0){
            fila->inicio++;

        }else if(fila->inicio == lastIndex){
            fila->inicio = 0;
        }

        else if(fila->inicio > 0){
            fila->inicio++;

        }else {
            printf("Situação imprevista ocorreu na função pop!");
            fflush(stdout);
            exit(1);
        }
        fila->total--;
        return item;
    }

}

void getStatus (Fila fila, char *titulo){
    if(isNull(fila)){
        printf("A fila está nula!");

    }else{
        printf("\n***** %s ****\n",titulo);
        printf("|Capacidade máxima: %d\n",fila->max);
        printf("|Total de itens: %d\n",fila->total);
        printf("|Index inicio: %d\n",fila->inicio);
        printf("|Index final: %d\n",getindexOfEnd(fila));
        printf("*****************************\n\n");
        
    }
}

void push(Itemf item, Fila fila){

    if(isFull(fila)){
        printf("A fila já está cheia!");
        fflush(stdout);
    }
    else if(isNull(fila))
        printf("Foi passsada uma fila nula para a função push!");
        
    else {

        const int lastIndex = fila->max - 1;
        
        fila->item[getindexOfEnd(fila)] = item;
        // printf("O index do final que tá vindo é %d: ",getindexOfEnd(fila));
        fila->total++;
        // getStatus(fila,"depois de um push aí...");
        
    }
}

int isEmpty(Fila fila){ 

    if(fila == NULL) 
        return -1;
    return (fila->total==0);
}

int isFull(Fila fila){
    
    if(isNull(fila)) 
        return -1;
    return(fila->total == fila->max);
}


int getindexOfEnd(Fila fila){ 
    int begin = fila->inicio, total = fila->total, capacidade = fila->max;
    const int lastIndex = capacidade - 1;
   //ruan viado 

    if(total == 0)
        return 0;

    if(total == 1 && begin < lastIndex)
        return begin + 1;
        // 0    |  1    |
        //cheio | vazio | 

    else if(total == 1 && begin == lastIndex)
        return 0;
        // 0    |  1    |
        //vazio | cheio | 


    else if(begin > 0 && begin + total == capacidade)
        return 0;
        //0 | 1 | 2 | 3
        //v | v | c | c


    else if(begin > 0 && begin + total < capacidade){
        return begin + total;
        // 0    |    1  | 2    |    3   
        // vago | cheio | cheio| vazio |
    }
    
    else if(begin > 0 && begin + total > capacidade){
        return (begin + total) - capacidade;
        // 0    |    1  | 2    |    3  | 4      | 5
        // cheio| cheio | vazio| cheio | cheio  | cheio
        // 0    |    1  | 2    |    3  | 4
        // cheio| vazio | cheio| cheio | cheio 
        // 0 |  1  | 2 | 3
        // c |  c  | v | c
   //---------------------- 
    }else if(begin == 0 && total > 1){
        return total;
    }

    else{
        printf("Erro imprevisto na função getIndexOfEnde!");
        fflush(stdout);
        exit(1);
    }
}   



void kill(Fila fila){

    if(isNull(fila))
        return; 

    free(fila->item);
    free(fila);
}
// divide pelo tamanho do bloco, isso corresponde ao numero da pagina virtual,e o resto corresponde ao deslocamento
//politicas de alocaçao de pagina nao vao cair na prova
//pode cair uma tabelinha da questao 23
//27 vai cair de certeza