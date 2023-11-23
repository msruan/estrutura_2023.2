
#include <iostream>
#include "lista_encadeada.hpp"
using namespace std;

int enesimo(int num,Node * inicio){
   if (inicio == NULL || num < 1) {
      cout << "Indice fora dos limites" << endl;
      return 0;
   }
   if(num == 1){
      return inicio->valor;
   }
   return enesimo(num - 1,inicio->proximo);
   
}

int main(){
   Node * inicio = gerarNo(10);
   inicio = insereInicio(inicio,10);
   inicio = insereInicio(inicio,20);
   inicio = insereInicio(inicio,30);
   cout << enesimo(1,inicio);
   kill(inicio);
   //exibe(inicio);
}