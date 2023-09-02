#include <iostream>
#include <string>
using namespace std;
int main(){
    typedef struct Pix{
        string nome;
        Pix *prox;
    } Pix;
    Pix *ryan = new Pix();
    ryan->nome = "Faustino";
    ryan->prox = nullptr;
    Pix *bianca = new Pix();
    bianca->nome = "Bezerra";
    bianca->prox = nullptr;
    ryan->prox = bianca;
    cout << ryan->prox->nome;
    Pix *inicio= ryan, *atual = inicio;
    while(atual->prox!=nullptr){
        cout << atual->nome;
        atual = atual->prox;
    }Pix *fim = atual;
    int *po;
}

//Para inserir um elemento numa lista encadeada numa posição especifica: caso s

//estudar alocaçao de memoria para tipos primitivos em C++ dps...
//OBS: acho q existe uns ponteiros intelginetes que talvez de pra acessar o enedereçeo do inci