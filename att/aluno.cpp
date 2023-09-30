#include <iostream>
using namespace std;

const int MAX_ALUNOS = 30;
const int SAIR = 0;

struct Aluno {
    int mat;
    string nome;
};

Aluno lista[MAX_ALUNOS];
int tamanho = 0;  // Vari�vel para controlar o tamanho atual da lista

Aluno novoAluno(int mat, string nome){
    Aluno novo;
    novo.mat = mat;
    novo.nome = nome;
    return novo;
}
Aluno novoAluno(){
    Aluno novo;
    cout << "Digite o número de matrícula do aluno: ";
    cin >> novo.mat;
    cout << "Digite o nome do aluno: ";
    cin.ignore();  // Limpar o buffer de entrada
    getline(cin, novo.nome);
    return novo;
}
void limparConsole(){
    cout << "\033[H\033[2J";
}
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

void bubble_sort() 
{
	bool houve_trocas;
	do
	{
		for (int j = 0; j < (vetor.size()-1);j++)
		{
			houve_trocas = 0;
			if (reverse)
			{
				if (vetor[j] > vetor[j+1])
				{
					troca(vetor[j],vetor[j+1]);
					houve_trocas = 1;
				}
			}
			else
			{
				if (vetor[j] < vetor[j+1])
				{
					troca(vetor[j],vetor[j+1]);
					houve_trocas = 1;
				}
			}
		}	
	}while(houve_trocas);
	return vetor;
}

void ordenar(){
    for()
}

void incluirOrdenado(Aluno e){

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
    int pos = procura(mat);

    if(pos==-1) return;

    int j = pos;
    while(j < tamanho-1){
        lista[j] = lista[j+1];
        j++;
    }tamanho--;
}
void opcao1(){}
int main() {
    int escolha = -1;
    while (escolha != SAIR) {
        cout << "\n1 - Incluir Aluno";
        cout << "\n2 - Mostrar Aluno por Matr�cula";
        cout << "\n3 - Mostrar Todos os Alunos";
        cout << "\n4 - Remover Aluno por Matr�cula";
        cout << "\n5 - Sair";
        cout << "\nDigite a opcaoo desejada: ";

        cin >> escolha;
        int matricula;
        int matRemover;

        if (escolha == 1){
            incluirDesordenado(novoAluno());
        }
        else if (escolha == 2){
            cout << "Digite a matricula do aluno a ser mostrado: ";
            cin >> matricula;
            mostrar(procura(matricula));
        }
        else if (escolha ==  3){
            mostra();
        }

        else if (escolha == 4){                
            cout << "Digite a matricula do aluno a ser removido: ";
            cin >> matRemover;
            remover01(matRemover);
        }
        else
            cout << "Opcao invalida! Tente novamente." << endl;
    limparConsole();
        }
    cout << "Saindo do programa." << endl;
    return 0;
}