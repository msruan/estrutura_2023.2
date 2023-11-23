#include <iostream>
#include "lista_encadeada.hpp"
using namespace std;

void substitui(int x, int y, Node *inicio){
   if(inicio == NULL){
      return;
   }

   if(inicio->valor == x){
      inicio->valor = y;
   }

   substitui(x,y,inicio->proximo);
}

int main(){
   Node *inicio = gerarNo(10);
   inicio = insereInicio(inicio,10);
   inicio = insereInicio(inicio,20);
   substitui(10,200,inicio);
   exibe(inicio);
   kill(inicio);
}