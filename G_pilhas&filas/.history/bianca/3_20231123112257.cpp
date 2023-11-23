#include "filaEncadeada.hpp"

void push(Fila *f,char n){
    Fila *f_aux = new Fila();
    f_aux->append(n);

    while(!f->isEmpty()){
        f_aux->append(f->pop());
    }

    while(!f_aux->isEmpty()){
        f->append(f_aux->pop());
    }

}

char pop2(Fila *f){
    return f->pop();
}

int main(){
    Fila *f = new Fila();
    push(f,'a');
    push(f,'b');
    cout << pop2(f);
}