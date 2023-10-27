#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void limparConsole(){
    printf("\033[H\033[2J");
}

typedef struct aluno{
	int mat;
	char* nome;	
}Aluno; 

Aluno *chamada[30];
int tamanho = 0;

Aluno *novoAluno(char *nome, int mat){
	Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
	aluno->nome = nome;
	aluno->mat = mat;
}

void matricularDesordenado(Aluno *e){

	if(tamanho < 30){
		chamada[tamanho] = e;
		tamanho++;
	}
	else
		printf("A chamada já está cheia! Tente remover algum aluno primeiro.\n");
}

//retorna a posicao do elemento procurado
int procura(int mat){

	for(int i = 0; i < tamanho; i++){
		if(chamada[i]->mat == mat){
			return i;
		}
	}return -1;

}

//recebe a posicao e imprime o elemento na tela
void mostrarAluno(int pos){

	if(pos >= 0 && pos < 30){
		printf("Aluno: %s\n",chamada[pos]->nome);
		printf("Matricula: %d\n\n",chamada[pos]->mat);
	}else
		printf("Digite uma posição válida!");

}

//mostra TODOS os elementos da lista
void mostrarAlunos(){	
	if(tamanho == 0){
		printf("Não há alunos matriculados ainda!");
		return;
	}
	for(int i = 0; i < tamanho; i++){
		mostrarAluno(i);
	}

}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(int mat){

	int pos = procura(mat);
	if(pos!=-1){
		printf("%s foi removido(a) com sucesso!\n\n",chamada[pos]->nome);
		chamada[pos] = chamada[tamanho];
		tamanho--;
	}else
		printf("Aluno não encontrado!\n");
}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(int mat){
	int pos = procura(mat);
	if(pos!=-1){
		printf("%s foi removido(a) com sucesso!\n\n",chamada[pos]->nome);
		for(int i = pos; i < tamanho-1; i++){
			chamada[i] = chamada[i+1];  
		}tamanho--;
	}else
		printf("Aluno não encontrado!\n");
	
}

int main(){
	const int SAIDA = 0;
	const int MATRICULA = 1;
	const int MOSTRA_ALUNO = 2;
	const int MOSTRA_TODOS = 3;
	const int REMOCAO = 4;

	int escolha = -1;
    while (escolha != SAIDA) {
       puts("\n1 - Incluir Aluno");
       puts("\n2 - Mostrar Aluno por Matr�cula");
       puts("\n3 - Mostrar Todos os Alunos");
       puts("\n4 - Remover Aluno por Matr�cula");
       puts("\n0 - Sair");
       puts("\nDigite a opcaoo desejada: ");

		char input_opcao[2], *retorno_opcao;
		fgets(input_opcao,2,stdin);
		fflush(stdin);

       	errno = 0;
		escolha = strtol(input_opcao,&retorno_opcao,10);

		if(input_opcao  == retorno_opcao || errno == ERANGE || errno == EINVAL){
			printf("Erro durante a leitura dos dados");
		}


        if (escolha == MATRICULA){

			char nome[40], input_mat[11], *retorno;
			int mat;
			
			printf("Qual o nome do aluno?");
			if (getchar()==EOF)
				return -1;
			fgets(nome,40,stdin);
			fflush(stdin);

			printf("Qual a matricula  do aluno?");
			fgets(input_mat,11,stdin);
			fflush(stdin);

			errno = 0;
			mat = strtol(input_mat,&retorno,10);
			fflush(stdin);
			if(input_mat == retorno || errno == ERANGE || errno == EINVAL){
				printf("Erro durante a leitura dos dados");
			}

            matricularDesordenado(novoAluno(nome,mat));

        }

        else if (escolha == MOSTRA_ALUNO){
            char input_mat[11], *retorno;
			int mat;
			
			printf("Qual a matricula  do aluno?");
			fgets(input_mat,11,stdin);
			fflush(stdin);

			errno = 0;
			mat = strtol(input_mat,&retorno,10);
			fflush(stdin);
			if(input_mat == retorno || errno == ERANGE || errno == EINVAL){
				printf("Erro durante a leitura dos dados");
			}else{
            	mostrarAluno(procura(mat));
			}
        }

        else if (escolha ==  MOSTRA_TODOS){
            mostrarAlunos();
        }

        else if (escolha == REMOCAO){    

            char input_mat[11], *retorno;
			int mat;
			
			printf("Qual a matricula  do aluno?");
			fgets(input_mat,11,stdin);
			fflush(stdin);

			errno = 0;
			mat = strtol(input_mat,&retorno,10);
			fflush(stdin);
			if(input_mat == retorno || errno == ERANGE || errno == EINVAL){
				printf("Erro durante a leitura dos dados");
			}else{
            	remover00(mat);
			}
        }

        else
            printf("Opcao invalida! Tente novamente.\n");

    	limparConsole();
	}
    printf("Saindo do programa...\n");
    return 0;	
}
	
