#include <iostream>


struct Aluno {
    int mat;
    std::string nome;
};

const int TAMANHO_MAX = 30;
Aluno chamada[TAMANHO_MAX];
int tamanho = 0;

void inserirNoFinal(Aluno novo){

    if(tamanho = TAMANHO_MAX){
        std::cout << "Operação falhou, a lista já está cheia!";
        return;
    }chamada[tamanho] = novo;

}

void inserirNoInicio(Aluno novo){
    if(tamanho = TAMANHO_MAX){
        std::cout << "Operação falhou, a lista já está cheia!";
        return;
    }

    for(int i = tamanho; i > 0; i--)
        chamada[i] = chamada[i-1];
    chamada[0] = novo;

}

void inverterChamada() {

    Aluno temporaria;
    int j = tamanho -1; 
    
    for(int i = 0; i != j ; i++){

        temporaria = chamada[j];
        chamada[tamanho] = chamada[i];
        chamada[j] = temporaria;

    }
}


int main(){}