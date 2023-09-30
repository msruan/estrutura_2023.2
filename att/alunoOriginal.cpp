#include <iostream>
using namespace std;

const int MAX_ALUNOS = 30;

struct Aluno {
    int mat;
    string nome;
};

Aluno lista[MAX_ALUNOS];
int tamanho = 0;  // Vari�vel para controlar o tamanho atual da lista

// Fun��o para incluir um aluno desordenado na lista
void incluirDesordenado(Aluno e) {
    if (tamanho < MAX_ALUNOS) {
        lista[tamanho] = e;
        tamanho++;
        cout << "Aluno inclu�do com sucesso!" << endl;
    } else {
        cout << "A lista est� cheia. N�o � poss�vel incluir mais alunos." << endl;
    }
}

// Fun��o para procurar um aluno pelo n�mero de matr�cula e retornar sua posi��o
int procura(int mat) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i].mat == mat) {
            return i;  // Retorna a posi��o do aluno
        }
    }
    return -1;  // Retorna -1 se o aluno n�o for encontrado
}

// Fun��o para mostrar os dados de um aluno na tela
void mostrar(int pos) {
    if (pos >= 0 && pos < tamanho) {
        cout << "Matr�cula: " << lista[pos].mat << ", Nome: " << lista[pos].nome << endl;
    } else {
        cout << "Posi��o inv�lida." << endl;
    }
}

// Fun��o para mostrar todos os alunos da lista
void mostra() {
    cout << "Lista de Alunos:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "Matr�cula: " << lista[i].mat << ", Nome: " << lista[i].nome << endl;
    }
}

// Estrat�gia 1: Remover um aluno substituindo-o pelo �ltimo aluno da lista
void remover00(int mat) {
    int pos = procura(mat);
    if (pos != -1) {
        lista[pos] = lista[tamanho - 1];  // Substitui o aluno pelo �ltimo da lista
        tamanho--;
        cout << "Aluno removido com sucesso!" << endl;
    } else {
        cout << "Aluno n�o encontrado." << endl;
    }
}

void remover01(int mat){
	
	
}

int main() {
    int escolha;
    while (true) {
        cout << "\n1 - Incluir Aluno";
        cout << "\n2 - Mostrar Aluno por Matr�cula";
        cout << "\n3 - Mostrar Todos os Alunos";
        cout << "\n4 - Remover Aluno por Matr�cula";
        cout << "\n5 - Sair";
        cout << "\nDigite a op��o desejada: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                Aluno novoAluno;
                cout << "Digite o n�mero de matr�cula do aluno: ";
                cin >> novoAluno.mat;
                cout << "Digite o nome do aluno: ";
                cin.ignore();  // Limpar o buffer de entrada
                getline(cin, novoAluno.nome);
                incluirDesordenado(novoAluno);
                break;
            case 2:
                int matricula;
                cout << "Digite a matr�cula do aluno a ser mostrado: ";
                cin >> matricula;
                mostrar(procura(matricula));
                break;
            case 3:
                mostra();
                break;
            case 4:
                int matRemover;
                cout << "Digite a matr�cula do aluno a ser removido: ";
                cin >> matRemover;
                remover00(matRemover);
                break;
            case 5:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Op��o inv�lida! Tente novamente." << endl;
        }
    }

    return 0;
}
