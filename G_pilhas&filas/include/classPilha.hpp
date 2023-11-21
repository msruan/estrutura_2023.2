#ifndef CLASS_PILHA_HPP
#define CLASS_PILHA_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef std::string Item;

class No{

	public:

		Item item;
		No *prox;

		No(Item item, No *prox = nullptr){

			this->item = item;
			this->prox = prox;
		}
};

class Pilha{

	public:

		No *topo;
		
		Pilha(No* no = nullptr){
			topo = no;
		}
		
		void push(Item n){

			No* novoTopo = new No(n);

			if(!isEmpty())
				novoTopo->prox = topo;
			
			topo = novoTopo;
		}

		void push(No* novoTopo){
			
			if(!isEmpty() && novoTopo != nullptr)
				novoTopo->prox = topo;
			
			topo = novoTopo;
		}
		
		Item pop(){
			
			if(!isEmpty()){

				Item itemTopo = topo->item;
				No *proxTopo = topo->prox;
				delete(topo);
				topo = proxTopo;

				return itemTopo;
			}
			return "";//alterar, caso o tipo de Item mude
		}
		
		bool isEmpty(){
			
			return (topo == nullptr);
		}
		//   popAll
		void clear(){
			
			while (!isEmpty())
			{
				No *proxTopo = topo->prox;
				delete(topo);
				topo = topo->prox;
			}
			
		}
};
#endif