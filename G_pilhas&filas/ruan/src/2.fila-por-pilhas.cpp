#include "../include/classPilha.hpp"

class Fila {

    Pilha pilha;
    Pilha fila;
 
    public:

        Fila(No *no){

            pilha.push(no);
        }

        void append (Item item) { 
            
            pilha.push(item);
        }

        void append (No* no) {

            pilha.push(no);
        }

        Item pop () {

            while(!pilha.isEmpty()){

                fila.push(pilha.pop());
            }

            Item saida = fila.pop();

            while(!fila.isEmpty()){

                pilha.push(fila.pop());
            }

            return saida;
        }

        bool isEmpty() {
            return pilha.isEmpty();
        }

        void clear () {
            pilha.clear();
        }
};

int main() {

    Fila chamada(new No("Ana"));
    chamada.append(new No("Beatriz"));
    chamada.append(new No("Carla"));
    std::cout << "\nAtenção para a chamada!\n";
    while(!chamada.isEmpty()){
        std::cout << chamada.pop() << "?\n";
    }
}