#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

//implementar depois com lista duplamente encadeada
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
		
		Fila(){
			inicio = nullptr;
			fim = nullptr;
		}
		
		void append(char n){
			
		}
		
		char pop(){
			
		}
		
		bool isEmpty(){
			return (inicio == nullptr);
		}
		//   popAll
	    void clear(){
	    	
	    	
		}

};

int main(){
	
	
    
	

	
}
