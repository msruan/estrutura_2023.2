#include <iostream>
#include <unordered_map>
#include <string>
#include "pilha.h"
using namespace std;

bool ehValido(string nome){
    unordered_map<char,char> pares;
    pares[')'] = '(';
    pares['}'] = '{';
    pares[']'] = '[';

    Pilha p = pilha(100);

    for(char c: nome){
        if (pares.count(c) == 0 && c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']') {//se nao achar e for diferentes dos limitadores, ignora
            continue;
        }
        if(pares.count(c) != 0){ //se o caracter for de fechamento
            if(emptyp(p) || getTopo(p) != pares[c]){//se tiver vazia (ou seja, nao fecha) OU nao fecha par com o ultimo que acharam, é invalido
                return false;
            }
            desempilha(p);//quer dizer que achou um par, entao desenpilha;
        }else{//se nao achou de fechamento, é porque é de abertura
            empilha(c,p);
        }
    }
    return emptyp(p);//se for 1, ta vazia e é valida. caso tenha algum elemento, significa que nao casou e apenas abriu, nao fechou
}

int main(){
    string nome;
    cout << "Digite uma expressao: ";
    getline(cin, nome);
    if(ehValido(nome)){
        cout << "eh valido";
    }else{
        cout <<"eh invalido";
    }
    return 0;
}