#include <stdio.h>

typedef struct aluno{
    int mat;
    string nome;
    aluno *prox;
}*Aluno;

Aluno no(int mat,string nome){
    Aluno novo = new Aluno();
    novo->mat = mat;
    novo->nome = nome;
    novo->prox = NULL;
    return novo;
}
Aluno *inicio = NULL;
Aluno *fim = NULL;
void incluirNoFinal(Aluno *n,Aluno *final){
    final->prox= n;
    final = n;
}
//inclui o elemento no inicio da lista
Aluno *incluirNoInicio(Aluno *novo_primeiro, Aluno *inicio){
    novo_primeiro->prox = inicio;
    return novo_primeiro;
}

//retorna o elemento se encontrado
//senao encontrado retorna NULL
Aluno *procura(int mat, Aluno *inicio){
    Aluno *atual = inicio;
    Aluno *encontrado = NULL;
    while(atual->prox!=NULL){
        if(atual->mat==mat){
            return atual;
        }atual = atual->prox;
    }return NULL;
}
//mostra TODOS os elementos da lista
void mostra(Aluno* inicio){
    for(Aluno *i = inicio; i!=NULL; i = i->prox)
        cout << "\nMatrícula: "<<i->mat<<"\nNome: "<<i->nome<<endl<<endl;
}
main(){
    Aluno *novo1 = no(2,"maria"), *inicio = novo1, *final = novo1;
    incluirNoFinal(novo1,final);

    Aluno *novo2 = no(3,"katia");
    incluirNoFinal(novo2,final);
    mostra(inicio);

    Aluno *novo3 = no(1,"bianca");
    inicio = incluirNoInicio(novo3,inicio);
    cout << "NOMEEEE\n"<<inicio->nome;
    mostra(inicio);
}