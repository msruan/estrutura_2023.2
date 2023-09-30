#include <iostream>
using namespace std;

const int MAX_ALUNOS = 30;

struct Aluno {
    int mat;
    string nome;
};

Aluno lista[MAX_ALUNOS];
int tamanho = 0;  // Variável para controlar o tamanho atual da lista

// Função para incluir um aluno desordenado na lista
void incluirDesordenado(Aluno e) {
    if (tamanho < MAX_ALUNOS) {
        lista[tamanho] = e;
        tamanho++;
        cout << "Aluno incluído com sucesso!" << endl;
    } else {
        cout << "A lista está cheia. Não é possível incluir mais alunos." << endl;
    }
}

// Função para procurar um aluno pelo número de matrícula e retornar sua posição
int procura(int mat) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i].mat == mat) {
            return i;  // Retorna a posição do aluno
        }
    }
    return -1;  // Retorna -1 se o aluno não for encontrado
}

// Função para mostrar os dados de um aluno na tela
void mostrar(int pos) {
    if (pos >= 0 && pos < tamanho) {
        cout << "Matrícula: " << lista[pos].mat << ", Nome: " << lista[pos].nome << endl;
    } else {
        cout << "Posição inválida." << endl;
    }
}

// Função para mostrar todos os alunos da lista
void mostra() {
    cout << "Lista de Alunos:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "Matrícula: " << lista[i].mat << ", Nome: " << lista[i].nome << endl;
    }
}

// Estratégia 1: Remover um aluno substituindo-o pelo último aluno da lista
void remover00(int mat) {
    int pos = procura(mat);
    if (pos != -1) {
        lista[pos] = lista[tamanho - 1];  // Substitui o aluno pelo último da lista
        tamanho--;
        cout << "Aluno removido com sucesso!" << endl;
    } else {
        cout << "Aluno não encontrado." << endl;
    }
}

void remover01(int mat){


}

int main() {
    int escolha;
    while (true) {
        cout << "\n1 - Incluir Aluno";
        cout << "\n2 - Mostrar Aluno por Matrícula";
        cout << "\n3 - Mostrar Todos os Alunos";
        cout << "\n4 - Remover Aluno por Matrícula";
        cout << "\n5 - Sair";
        cout << "\nDigite a opção desejada: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                Aluno novoAluno;
                cout << "Digite o número de matrícula do aluno: ";
                cin >> novoAluno.mat;
                cout << "Digite o nome do aluno: ";
                cin.ignore();  // Limpar o buffer de entrada
                getline(cin, novoAluno.nome);
                incluirDesordenado(novoAluno);
                break;
            case 2:
                int matricula;
                cout << "Digite a matrícula do aluno a ser mostrado: ";
                cin >> matricula;
                mostrar(procura(matricula));
                break;
            case 3:
                mostra();
                break;
            case 4:
                int matRemover;
                cout << "Digite a matrícula do aluno a ser removido: ";
                cin >> matRemover;
                remover00(matRemover);
                break;
            case 5:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
    }

    return 0;
}