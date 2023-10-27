//1. Complete o código:
#include <stdio.h>
#include <string.h>
// prova 1
typedef struct livro {
    int cod;
    char nome[40];
}Tlivro;


Tlivro livros[5];
int tamanho = 0;

void inserirNoFinal(Tlivro novo);
void inserirOrd(Tlivro novo){


    if(tamanho > 4){
        printf("Operacao invalida! A biblioteca já está lotada.\n");
        return; 
    }
    else if(tamanho == 0){
        inserirNoFinal(novo);
        return;
    }
 
    else{

        int i = 0, pos;
        for( ; i < tamanho; i++){
            if(livros[i].cod >= novo.cod){
                break;
            }
        }
        printf("%d",i);

        pos = i;
        for(int j = tamanho; j > pos; j--){
          livros[j] = livros[j-1];
        }livros[pos] = novo;
        tamanho++;

        // Inserir o elemento de maneira ordenada
        // Complete aqui
    }
}

// inserir o novo elemento no final da lista
void inserirNoFinal(Tlivro novo){

    if (tamanho > 4){
        printf("\nBiblioteca lotada!!!");
        return;
    }   
    livros[tamanho] = novo;
    tamanho++;
}

void mostra(){

    for(int i = 0; i < tamanho; i++){
        printf("Código do livro: %d",livros[i].cod);
        printf("\nNome do livro: %s\n\n",livros[i].nome);

    }
    //MINISTÉRIO DA EDUCAÇÃO
    //INSTITUTO FEDERAL DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DO
    //PIAUÍ
    //CURSO : Analise e desenvolvimento de sistemas
    //DISCIPLINA : Estrutura de Dados
    //PROFESSORA: ELANNE
}

int main(){
    Tlivro a = {8,"Aprendendo a programar em C"};
   puts("passou da primeira linha");
    // Cadastre os elementos na lista de forma ordenada pelo codigo:
   inserirOrd(a);
Tlivro b = {10,"Aprendendo a Programar em Python"};
 inserirOrd(b);
 Tlivro c = {12,"Estrutura de Dados 2"};
 inserirOrd(c);
    mostra();
//     //Cadastre os elementos no final da lista:
   //inserirOrd();
//    inserirOrd({13,"Matematica aplicada"});
//    // Mostre os elementos da lista
//       mostra();
}