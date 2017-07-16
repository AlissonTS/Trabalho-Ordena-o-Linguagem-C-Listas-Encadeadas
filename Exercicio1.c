#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Funcionarios{
		char nome[30];
		float salario;
		struct Funcionarios *prox;
};

typedef struct Funcionarios Funcionarios;

Funcionarios *inserir(Funcionarios *l, int count); // Fun��o Inserir Funcion�rios
Funcionarios *ordenarAlfabetica(Funcionarios *l, int quantidade); // Fun��o ordenar os Funcion�rios por Ordem Alfab�tica
Funcionarios *ordenarSalario(Funcionarios *l, int quantidade); // Fun��o ordenar os Funcion�rios por Sal�rio, forma decrescente
void imprimir(Funcionarios *l, int count); // Imprimir Funcion�rios

main(){
		Funcionarios *l;
		l = NULL;
		
		int i=0, count=0;
		
		do{
			system("cls");
			
			int escolha;
			printf("\tSistema de Gerenciamento de Funcionarios em uma Empresa\n\n");
			printf("- Empresa possui %d Funcionarios no momento - \n\n", count);
			printf("- Opcoes - \n");
			printf("- 1 - Adicionar Funcionario - \n");
			printf("- 2 - Mostrar Lista de Funcionarios - \n");
			printf("- 3 - Ordenar Funcionarios em Ordem Alfabetica - \n");
			printf("- 4 - Ordenar Funcionarios pelo Salario - Decrescente - \n");
			printf("- 5 - Sair do Programa - \n");
			printf("Digite qual opcao voce deseja selecionar: ");
			scanf("%d", &escolha);
			
			switch(escolha){
				case 1:{
					count++;
					printf("\nVoce escolheu adicionar um funcionario a empresa!\n");
					l = inserir(l, count);
					
					getch();
					break;
				}	
				case 2:{
					printf("\nVoce escolheu mostrar a lista de funcionarios da empresa!\n");
					imprimir(l, count);
					
					getch();
					break;
				}
				case 3:{
					printf("\nVoce escolheu ordenar os funcionarios da empresa por ordem alfabetica!\n");
					
					l = ordenarAlfabetica(l, count);
					
					getch();
					break;
				}
				case 4:{
					printf("\nVoce escolheu ordenar os funcionarios da empresa pelo salario!\n");
					
					l = ordenarSalario(l, count);
					
					getch();
					break;
				}
				case 5:{
					printf("\nSaindo do Programa! Muito obrigado :)\n");
					
					i++;
					break;
				}
				default:{
					printf("\nOpcao invalida! Retornando ao menu principal...\n");
					getch();
				}
			}	
			
		}while(i==0);
		
		system("pause");
}

Funcionarios *inserir(Funcionarios *l, int count){ // Fun��o Inserir Funcion�rios
		float sal;
		char nome1[30];
		
		printf("\n\n - Cadastro de Funcionario - \n");			
		if(l==NULL){ // Se for o primeiro Funcion�rio
			printf("\nCadastro do primeiro Funcionario: \n");
			Funcionarios *novo;
			
			novo = (Funcionarios*)malloc(sizeof(Funcionarios));
			
			fflush(stdin);  
			printf("Digite o nome do Funcionario: \n");
			gets(nome1);
			strupr(nome1);
			
			printf("Digite o salario do Funcionario: ");
			scanf("%f", &sal);
			
			strcpy(novo->nome, nome1);
			novo->salario = sal;
			novo->prox = l;
			
			printf("\n\nFuncionario inserido!\n");
			return novo;
		}	
		else{ // Se for os pr�ximos Funcion�rios
			printf("\nCadastro do %d Funcionario: \n", count);
			Funcionarios *novo;
			
			Funcionarios *aux, *aux2;
			
			novo = (Funcionarios*)malloc(sizeof(Funcionarios));
			
			for(aux=l; aux!=NULL; aux=aux->prox){
				if(aux->prox==NULL){
					aux2=aux;
					break;
				}
			}
			
			fflush(stdin);  
			printf("Digite o nome do Funcionario: \n");
			gets(nome1);
			strupr(nome1);
			
			printf("Digite o salario do Funcionario: ");
			scanf("%f", &sal);
			
			strcpy(novo->nome, nome1);
			novo->salario = sal;
			novo->prox = NULL;
			aux2->prox = novo;
			
			printf("\n\nFuncionario inserido!\n");
			return l;
		}		
}

Funcionarios *ordenarAlfabetica(Funcionarios *l, int quantidade){ // Ordenar Funcion�rios por Ordem alfab�tica
		Funcionarios *aux; // Ponteiro Auxiliar que recebe o endere�o do primeiro elemento da lista e vai atualizando ao longo das compara��es
		Funcionarios *aux2; // Ponteiro do La�o que procura o elemento da ordem alfabetica para compara��o 
		Funcionarios *p; // Ponteiro que recebe o endere�o pr�ximo elemento em rela��o ao aux
		Funcionarios *aux3; // Ponteiro do La�o que procura o elemento anterior ao elemento da ordem alfabetica da compara��o
		Funcionarios *menor; // Ponteiro que recebe o endere�o  do elemento da ordem alfabetica da compara��o feita
		Funcionarios *menorProx; // Ponteiro que recebe o endere�o do pr�ximo elemento da ordem alfabetica da compara��o, se tiver
		Funcionarios *menorAnt; // Ponteiro que recebe o endere�o do anterior elemento da ordem alfabetica da compara��o, se tiver
		Funcionarios *auxAnt; // Ponteiro que recebe o endere�o do anterior elemento ao aux, que � o que percorre a lista
		Funcionarios *auxProx; // Ponteiro que recebe o endere�o do proximo elemento ao aux, que � o que percorre a lista
		int i, contador=0, verific=0;
		
		char min[30];
		
		aux = l;
		auxAnt = NULL;
		auxProx = aux->prox;
		p = aux->prox;
		
		for(i=0; i<(quantidade-1); i++){ // La�o definido pela quantidade de elementos menos 1
			
			strcpy(min, aux->nome); // Vari�vel de compara��o com os pr�ximos elementos
			
			for(aux2=p; aux2!=NULL; aux2=aux2->prox){ // La�o para achar o elemento da ordem alfabetica � variavel
				
				int k=0;
				
				k = strcmp(aux2->nome, min);
				
				if(k<0){
					
					strcpy(min, aux2->nome); // Elemento da ordem alfabetica elemento achado
					menor = aux2; // Endere�o do elemento da ordem alfabetica
					
					contador++; // Contador que � incrementado para mostrar que foi achado o elemento da ordem alfabetica		
				}
			}
			
			if(contador>0){ // Se foi achado um elemento da ordem alfabetica ao que est� sendo comparado
			
				if(menor->prox==NULL){ 
					menorProx = NULL; // Se ap�s o elemento da ordem alfabetica n�o tiver elementos
				}
				else
					menorProx = menor->prox; // Ponteiro para o pr�ximo elemento ao elemento da ordem alfabetica
				if(aux->prox==menor){ // Elemento da ordem alfabetica � vizinho
					menorAnt = NULL; 
				}
				else{
					for(aux3=l; aux3!=NULL; aux3=aux3->prox){
						if(aux3->prox==menor){
							menorAnt = aux3; // Elemento da ordem alfabetica possui anterior
						}
					}
				}
				
				if(aux==l){ // Se o elemento comparado � o primeiro da lista
					if(menorAnt==NULL){ // Se o elemento da ordem alfabetica � vizinho
						aux->prox=menor->prox;
						menor->prox = aux;
						l = menor; // Atualiza��o do ponteiro l 
						aux = menor->prox;	
						verific++;
					}	
					else{ // Se o elemento da ordem alfabetica n�o � vizinho
						menorAnt->prox = aux;  
						menor->prox = aux->prox; // Reapontamento
						aux->prox = menorProx; 
						l = menor; // Atualiza��o do ponteiro l
						aux = menor->prox;
						verific++;
					}
					auxAnt = l; // Anterior ao aux novo � o primeiro elemento
					auxProx = aux->prox; // Pr�ximo ao auxiliar que ser� comparado
					p = aux->prox;
				}
				else{ // Se o elemento comparado n�o � o primeiro elemento da lista
					if(menorAnt==NULL){ // Se o elemento da ordem alfabetica � vizinho
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para o elemento da ordem alfabetica
						menor->prox = aux; // Elemento da ordem alfabetica apontar� para o auxiliar
						aux->prox = menorProx; // Pr�ximo ao auxiliar apontar� para o pr�ximo ao elemento da ordem alfabetica, havendo assim a troca de posi��es
						
						p = aux->prox; // Atualiza��o do P
						auxAnt = menor; // Ponteiro auxiliar anterios � o elemento da ordem alfabetica
						auxProx = aux->prox;
						verific++;
					}
					else{ // Se o elemento da ordem alfabetica n�o � vizinho
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para o elemento da ordem alfabetica
						menor->prox = auxProx; // Elemento da ordem alfabetica apontar� pr�ximo para o pr�ximo ao auxiliar
						menorAnt->prox = aux; // Antecessor apontar� para o auxiliar que ser� trocado de posi��o
						aux->prox = menorProx; // Auxiliar agora em sua nova posi��o apontar� para o pr�ximo elemento da ordem alfabetica antigo
						
						aux = menor->prox; // Atualiza��o do P
						auxAnt = menor; // Ponteiro auxiliar anterios � o elemento da ordem alfabetica
						auxProx = aux->prox;
						p = aux->prox;
						verific++;
					}
				}
				contador=0;	
				min[0]='\0';
			}
			else{ // Se n�o foi achado um elemento da ordem alfabetica ao elemento comparado, segue o rumo normal da lista, sem fazer novos apontamentos
				auxAnt = aux; // Auxiliar anterior recebe o aux
				aux = aux->prox; // Aux deslocar� para o pr�ximo
				auxProx = aux->prox; // Auxiliar pr�ximo recebe o Aux pr�ximo
				p = aux->prox; // P recebe o Aux pr�ximo
			}
			menorProx = NULL;
			menorAnt = NULL;
		}
		
		if(verific>0)
			printf("\nSua Lista de Funcionarios foi ordenada com sucesso!\n");
		else
			printf("\nSua Lista de Funcionarios ja estava ordenada!\n");	
		
		return l;
}	

Funcionarios *ordenarSalario(Funcionarios *l, int quantidade){ // Fun��o Ordenar Funcion�rios Pelo Salario
		Funcionarios *aux; // Ponteiro Auxiliar que recebe o endere�o do primeiro Funcionario da lista e vai atualizando ao longo das compara��es
		Funcionarios *aux2; // Ponteiro do La�o que procura o maior elemento para compara��o 
		Funcionarios *p; // Ponteiro que recebe o endere�o pr�ximo elemento em rela��o ao aux
		Funcionarios *aux3; // Ponteiro do La�o que procura o elemento anterior ao elemento de maior sal�rio da compara��o
		Funcionarios *maior; // Ponteiro que recebe o endere�o  do elemento de maior salario da compara��o feita
		Funcionarios *maiorProx; // Ponteiro que recebe o endere�o do pr�ximo elemento ao maior salario da compara��o, se tiver
		Funcionarios *maiorAnt; // Ponteiro que recebe o endere�o do anterior elemento ao maior salario da compara��o, se tiver
		Funcionarios *auxAnt; // Ponteiro que recebe o endere�o do anterior elemento ao aux, que � o que percorre a lista
		Funcionarios *auxProx; // Ponteiro que recebe o endere�o do proximo elemento ao aux, que � o que percorre a lista
		int i, contador=0, verific=0;
		float min=0;
		
		aux = l;
		auxAnt = NULL;
		auxProx = aux->prox;
		p = aux->prox;
		
		for(i=0; i<(quantidade-1); i++){ // La�o definido pela quantidade de elementos menos 1
			
			min = aux->salario; // Vari�vel de compara��o com os pr�ximos elementos
			
			for(aux2=p; aux2!=NULL; aux2=aux2->prox){ // La�o para achar o elemento maior salario � variavel
				if(aux2->salario>min){
					
					min = aux2->salario; // Maior elemento achado
					maior = aux2; // Endere�o do maior elemento
					
					contador++; // Contador que � incrementado para mostrar que foi achado o elemento maior		
				}
			}
			
			if(contador>0){ // Se foi achado um elemento maior ao que est� sendo comparado
			
				if(maior->prox==NULL){ 
					maiorProx = NULL; // Se ap�s o maior n�o tiver elementos
				}
				else
					maiorProx = maior->prox; // Ponteiro para o pr�ximo elemento ao maior
				if(aux->prox==maior){ // Elemento maior � vizinho
					maiorAnt = NULL; 
				}
				else{
					for(aux3=l; aux3!=NULL; aux3=aux3->prox){
						if(aux3->prox==maior){
							maiorAnt = aux3; // Elemento maior possui anterior
						}
					}
				}
				
				if(aux==l){ // Se o elemento comparado � o primeiro da lista
					if(maiorAnt==NULL){ // Se o maior � vizinho
						aux->prox=maior->prox;
						maior->prox = aux;
						l = maior; // Atualiza��o do ponteiro l 
						aux = maior->prox;	
					}	
					else{ // Se o maior n�o � vizinho
						maiorAnt->prox = aux;  
						maior->prox = aux->prox; // Reapontamento
						aux->prox = maiorProx; 
						l = maior; // Atualiza��o do ponteiro l
						aux = maior->prox;
					}
					auxAnt = l; // Anterior ao aux novo � o primeiro elemento
					auxProx = aux->prox; // Pr�ximo ao auxiliar que ser� comparado
					p = aux->prox;
				}
				else{ // Se o elemento comparado n�o � o primeiro elemento da lista
					if(maiorAnt==NULL){ // Se o maior � vizinho
						auxAnt->prox = maior; // Anterior ao auxiliar aponta para o maior
						maior->prox = aux; // Maior apontar� para o auxiliar
						aux->prox = maiorProx; // Pr�ximo ao auxiliar apontar� para o pr�ximo ao maior, havendo assim a troca de posi��es
						
						p = aux->prox; // Atualiza��o do P
						auxAnt = maior; // Ponteiro auxiliar anterios � o maior
						auxProx = aux->prox;
					}
					else{ // Se o menor n�o � vizinho
						auxAnt->prox = maior; // Anterior ao auxiliar aponta para o maior
						maior->prox = auxProx; // Maior apontar� pr�ximo para o pr�ximo ao auxiliar
						maiorAnt->prox = aux; // Antecessor apontar� para o auxiliar que ser� trocado de posi��o
						aux->prox = maiorProx; // Auxiliar agora em sua nova posi��o apontar� para o pr�ximo maior antigo
						
						aux = maior->prox; // Atualiza��o do P
						auxAnt = maior; // Ponteiro auxiliar anterios � o maior
						auxProx = aux->prox;
						p = aux->prox;
					}
				}
				contador=0;	
				min=0;
			}
			else{ // Se n�o foi achado um elemento maior ao elemento comparado, segue o rumo normal da lista, sem fazer novos apontamentos
				auxAnt = aux; // Auxiliar anterior recebe o aux
				aux = aux->prox; // Aux deslocar� para o pr�ximo
				auxProx = aux->prox; // Auxiliar pr�ximo recebe o Aux pr�ximo
				p = aux->prox; // P recebe o Aux pr�ximo
			}
			maiorProx = NULL;
			maiorAnt = NULL;
		}
		
		return l;
}

void imprimir(Funcionarios *l, int count){ // Imprimir Funcion�rios
		if(l==NULL){
			printf("\nA lista de Funcionarios da Empresa esta vazia!\n");
		}
		else{
			Funcionarios *aux;
			
			printf("\n\n- Lista de Funcionarios da Empresa - \n");
			printf("- Empresa possui %d Funcionarios no momento - \n\n", count);
			for(aux=l; aux!=NULL; aux=aux->prox){
				printf("- Funcionario: ");
				puts(aux->nome);
				printf(" - Salario: R$ %.2f. \n", aux->salario);
				printf("- - - - - - - - - - - - - - - - - - - -\n\n");
			}
		}
		getch();
}

