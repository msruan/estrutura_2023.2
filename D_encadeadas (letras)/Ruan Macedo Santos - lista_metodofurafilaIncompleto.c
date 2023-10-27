#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Letra{
	char letra;
    struct Letra *prox;
}Letra;

Letra *inicio = NULL;
Letra *fim = NULL;
Letra *atual;
Letra*anterior;
Letra *novaLetra

void inserirLetra(char letra);
void furaFila(int pos);
void mostrar();

void mostrarMenu(){
	printf("\n\n1 - Inserir Letra ");
	printf("\n2 - Furar a fila ");
	printf("\n3 - Mostrar letras ");
	printf("\n5 - Sair ");
	printf("\nDigite a Opcao Desejada: ");
}

int main(){
	const int SAIDA = 0;
	const int INSERCAO = 1;
	const int FURAR = 2;
	const int PRINT = 3;
	int opcao;
	char l;
   	do {
		mostrarMenu();
      	scanf("%d",&opcao);
		fflush(stdin);

        switch(opcao) {
			case FURAR:
				int pos;
			 	scanf("%d",&pos);

         	case INSERCAO:
			 	printf("Digite uma letra: ");
				l = getchar();			 	
			 	printf("A letra digitada foi '%c'\n",l);
			 	inserirLetra(l); 
				if(opcao==FURAR){
					furaFila(,int pos);
				}		
				break;

         	case PRINT:
				mostrar(); 
				break;

         	default: 
				printf("Opcao invalida! tente de novo! ");
        }
        
        
      }while (opcao != SAIDA);		
		
}

Letra* novaLetra(char letra){
	Letra *novo = (Letra*)malloc(sizeof(Letra));
	novo->letra=letra;
	novo->prox=0;
}

void inserirLetraFinal(Letra *letra, Letra *final){
	if(final==NULL) 
		return;
	final->prox = letra;
}

void vInserirLetraInicio(Letra *letra, Letra **inicio){
	if(*inicio==NULL)
		*inicio = letra;
	else{
		letra->prox = *inicio;
		*inicio = letra;
	}
}

void sInserirLetraInicio(Letra *letra, Letra *inicio){
	if(inicio==NULL)
		return letra;
	letra->prox = inicio;
	return letra;
}

void inserirLetraMeio(Letra **inicio, Letra *nova, int pos){

	if(nova == NULL) return;

	if (*inicio = NULL) *inicio = nova;

	if(pos == 0){
		vInserirLetraInicio(nova, inicio);
		return;
	}
 
	Letra *atual = *inicio;
	int i = 0;

	while (i+1 < pos){
		atual = atual->prox;
	}
	nova = atual->prox;
	atual->prox = nova; 

}


void furaFila(int pos){
	
	
	
}

void mostrar(){
	atual = inicio;
	
	while(atual != NULL){
		printf("%c", atual->letra);
        atual = atual->prox;
	}
	

	
}
