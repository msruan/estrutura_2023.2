#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = nullptr;
		}
};

class Fila{

	public:
	
		No *inicio;
		No *fim;
		
		Fila(No *inicio = nullptr){
			this->inicio = inicio;
			fim = nullptr;
		}
		
		void append(char n){
			No* novoNo = new No(n);
			if(inicio==nullptr){
				inicio = novoNo;
				return;
			}
			inicio->prox = novoNo;
			fim = novoNo;
		}
		
		char pop(){
			if(inicio == nullptr){
				abort();
			}
			char primeiro = inicio->nome;
			inicio = inicio->prox;
			return primeiro;
		}
		
		bool isEmpty(){
			return (inicio == nullptr);
		}
		//   popAll
	    void clear(){
			
		}

		void empilhaFila(char n){
			Fila f_aux(nullptr);
			f_aux.append(n);

			while(!isEmpty()){
			 	f_aux.append(pop());
		    }

			while(!f_aux.isEmpty()){
				append(f_aux.pop());
			}
		}

		char desempilhaFila(){
			return pop();
		}
	    	
};
int main(){
    Fila f(nullptr);
    f.empilhaFila('a');
    f.empilhaFila('b');
    f.empilhaFila('c');
    cout << f.desempilhaFila();
}