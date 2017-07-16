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

Funcionarios *inserir(Funcionarios *l, int count); // Função Inserir Funcionários
Funcionarios *ordenarAlfabetica(Funcionarios *l, int quantidade); // Função ordenar os Funcionários por Ordem Alfabética
Funcionarios *ordenarSalario(Funcionarios *l, int quantidade); // Função ordenar os Funcionários por Salário, forma decrescente
void imprimir(Funcionarios *l, int count); // Imprimir Funcionários

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

Funcionarios *inserir(Funcionarios *l, int count){ // Função Inserir Funcionários
		float sal;
		char nome1[30];
		
		printf("\n\n - Cadastro de Funcionario - \n");			
		if(l==NULL){ // Se for o primeiro Funcionário
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
		else{ // Se for os próximos Funcionários
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

Funcionarios *ordenarAlfabetica(Funcionarios *l, int quantidade){ // Ordenar Funcionários por Ordem alfabética
		Funcionarios *aux; // Ponteiro Auxiliar que recebe o endereço do primeiro elemento da lista e vai atualizando ao longo das comparações
		Funcionarios *aux2; // Ponteiro do Laço que procura o elemento da ordem alfabetica para comparação 
		Funcionarios *p; // Ponteiro que recebe o endereço próximo elemento em relação ao aux
		Funcionarios *aux3; // Ponteiro do Laço que procura o elemento anterior ao elemento da ordem alfabetica da comparação
		Funcionarios *menor; // Ponteiro que recebe o endereço  do elemento da ordem alfabetica da comparação feita
		Funcionarios *menorProx; // Ponteiro que recebe o endereço do próximo elemento da ordem alfabetica da comparação, se tiver
		Funcionarios *menorAnt; // Ponteiro que recebe o endereço do anterior elemento da ordem alfabetica da comparação, se tiver
		Funcionarios *auxAnt; // Ponteiro que recebe o endereço do anterior elemento ao aux, que é o que percorre a lista
		Funcionarios *auxProx; // Ponteiro que recebe o endereço do proximo elemento ao aux, que é o que percorre a lista
		int i, contador=0, verific=0;
		
		char min[30];
		
		aux = l;
		auxAnt = NULL;
		auxProx = aux->prox;
		p = aux->prox;
		
		for(i=0; i<(quantidade-1); i++){ // Laço definido pela quantidade de elementos menos 1
			
			strcpy(min, aux->nome); // Variável de comparação com os próximos elementos
			
			for(aux2=p; aux2!=NULL; aux2=aux2->prox){ // Laço para achar o elemento da ordem alfabetica à variavel
				
				int k=0;
				
				k = strcmp(aux2->nome, min);
				
				if(k<0){
					
					strcpy(min, aux2->nome); // Elemento da ordem alfabetica elemento achado
					menor = aux2; // Endereço do elemento da ordem alfabetica
					
					contador++; // Contador que é incrementado para mostrar que foi achado o elemento da ordem alfabetica		
				}
			}
			
			if(contador>0){ // Se foi achado um elemento da ordem alfabetica ao que está sendo comparado
			
				if(menor->prox==NULL){ 
					menorProx = NULL; // Se após o elemento da ordem alfabetica não tiver elementos
				}
				else
					menorProx = menor->prox; // Ponteiro para o próximo elemento ao elemento da ordem alfabetica
				if(aux->prox==menor){ // Elemento da ordem alfabetica é vizinho
					menorAnt = NULL; 
				}
				else{
					for(aux3=l; aux3!=NULL; aux3=aux3->prox){
						if(aux3->prox==menor){
							menorAnt = aux3; // Elemento da ordem alfabetica possui anterior
						}
					}
				}
				
				if(aux==l){ // Se o elemento comparado é o primeiro da lista
					if(menorAnt==NULL){ // Se o elemento da ordem alfabetica é vizinho
						aux->prox=menor->prox;
						menor->prox = aux;
						l = menor; // Atualização do ponteiro l 
						aux = menor->prox;	
						verific++;
					}	
					else{ // Se o elemento da ordem alfabetica não é vizinho
						menorAnt->prox = aux;  
						menor->prox = aux->prox; // Reapontamento
						aux->prox = menorProx; 
						l = menor; // Atualização do ponteiro l
						aux = menor->prox;
						verific++;
					}
					auxAnt = l; // Anterior ao aux novo é o primeiro elemento
					auxProx = aux->prox; // Próximo ao auxiliar que será comparado
					p = aux->prox;
				}
				else{ // Se o elemento comparado não é o primeiro elemento da lista
					if(menorAnt==NULL){ // Se o elemento da ordem alfabetica é vizinho
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para o elemento da ordem alfabetica
						menor->prox = aux; // Elemento da ordem alfabetica apontará para o auxiliar
						aux->prox = menorProx; // Próximo ao auxiliar apontará para o próximo ao elemento da ordem alfabetica, havendo assim a troca de posições
						
						p = aux->prox; // Atualização do P
						auxAnt = menor; // Ponteiro auxiliar anterios é o elemento da ordem alfabetica
						auxProx = aux->prox;
						verific++;
					}
					else{ // Se o elemento da ordem alfabetica não é vizinho
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para o elemento da ordem alfabetica
						menor->prox = auxProx; // Elemento da ordem alfabetica apontará próximo para o próximo ao auxiliar
						menorAnt->prox = aux; // Antecessor apontará para o auxiliar que será trocado de posição
						aux->prox = menorProx; // Auxiliar agora em sua nova posição apontará para o próximo elemento da ordem alfabetica antigo
						
						aux = menor->prox; // Atualização do P
						auxAnt = menor; // Ponteiro auxiliar anterios é o elemento da ordem alfabetica
						auxProx = aux->prox;
						p = aux->prox;
						verific++;
					}
				}
				contador=0;	
				min[0]='\0';
			}
			else{ // Se não foi achado um elemento da ordem alfabetica ao elemento comparado, segue o rumo normal da lista, sem fazer novos apontamentos
				auxAnt = aux; // Auxiliar anterior recebe o aux
				aux = aux->prox; // Aux deslocará para o próximo
				auxProx = aux->prox; // Auxiliar próximo recebe o Aux próximo
				p = aux->prox; // P recebe o Aux próximo
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

Funcionarios *ordenarSalario(Funcionarios *l, int quantidade){ // Função Ordenar Funcionários Pelo Salario
		Funcionarios *aux; // Ponteiro Auxiliar que recebe o endereço do primeiro Funcionario da lista e vai atualizando ao longo das comparações
		Funcionarios *aux2; // Ponteiro do Laço que procura o maior elemento para comparação 
		Funcionarios *p; // Ponteiro que recebe o endereço próximo elemento em relação ao aux
		Funcionarios *aux3; // Ponteiro do Laço que procura o elemento anterior ao elemento de maior salário da comparação
		Funcionarios *maior; // Ponteiro que recebe o endereço  do elemento de maior salario da comparação feita
		Funcionarios *maiorProx; // Ponteiro que recebe o endereço do próximo elemento ao maior salario da comparação, se tiver
		Funcionarios *maiorAnt; // Ponteiro que recebe o endereço do anterior elemento ao maior salario da comparação, se tiver
		Funcionarios *auxAnt; // Ponteiro que recebe o endereço do anterior elemento ao aux, que é o que percorre a lista
		Funcionarios *auxProx; // Ponteiro que recebe o endereço do proximo elemento ao aux, que é o que percorre a lista
		int i, contador=0, verific=0;
		float min=0;
		
		aux = l;
		auxAnt = NULL;
		auxProx = aux->prox;
		p = aux->prox;
		
		for(i=0; i<(quantidade-1); i++){ // Laço definido pela quantidade de elementos menos 1
			
			min = aux->salario; // Variável de comparação com os próximos elementos
			
			for(aux2=p; aux2!=NULL; aux2=aux2->prox){ // Laço para achar o elemento maior salario à variavel
				if(aux2->salario>min){
					
					min = aux2->salario; // Maior elemento achado
					maior = aux2; // Endereço do maior elemento
					
					contador++; // Contador que é incrementado para mostrar que foi achado o elemento maior		
				}
			}
			
			if(contador>0){ // Se foi achado um elemento maior ao que está sendo comparado
			
				if(maior->prox==NULL){ 
					maiorProx = NULL; // Se após o maior não tiver elementos
				}
				else
					maiorProx = maior->prox; // Ponteiro para o próximo elemento ao maior
				if(aux->prox==maior){ // Elemento maior é vizinho
					maiorAnt = NULL; 
				}
				else{
					for(aux3=l; aux3!=NULL; aux3=aux3->prox){
						if(aux3->prox==maior){
							maiorAnt = aux3; // Elemento maior possui anterior
						}
					}
				}
				
				if(aux==l){ // Se o elemento comparado é o primeiro da lista
					if(maiorAnt==NULL){ // Se o maior é vizinho
						aux->prox=maior->prox;
						maior->prox = aux;
						l = maior; // Atualização do ponteiro l 
						aux = maior->prox;	
					}	
					else{ // Se o maior não é vizinho
						maiorAnt->prox = aux;  
						maior->prox = aux->prox; // Reapontamento
						aux->prox = maiorProx; 
						l = maior; // Atualização do ponteiro l
						aux = maior->prox;
					}
					auxAnt = l; // Anterior ao aux novo é o primeiro elemento
					auxProx = aux->prox; // Próximo ao auxiliar que será comparado
					p = aux->prox;
				}
				else{ // Se o elemento comparado não é o primeiro elemento da lista
					if(maiorAnt==NULL){ // Se o maior é vizinho
						auxAnt->prox = maior; // Anterior ao auxiliar aponta para o maior
						maior->prox = aux; // Maior apontará para o auxiliar
						aux->prox = maiorProx; // Próximo ao auxiliar apontará para o próximo ao maior, havendo assim a troca de posições
						
						p = aux->prox; // Atualização do P
						auxAnt = maior; // Ponteiro auxiliar anterios é o maior
						auxProx = aux->prox;
					}
					else{ // Se o menor não é vizinho
						auxAnt->prox = maior; // Anterior ao auxiliar aponta para o maior
						maior->prox = auxProx; // Maior apontará próximo para o próximo ao auxiliar
						maiorAnt->prox = aux; // Antecessor apontará para o auxiliar que será trocado de posição
						aux->prox = maiorProx; // Auxiliar agora em sua nova posição apontará para o próximo maior antigo
						
						aux = maior->prox; // Atualização do P
						auxAnt = maior; // Ponteiro auxiliar anterios é o maior
						auxProx = aux->prox;
						p = aux->prox;
					}
				}
				contador=0;	
				min=0;
			}
			else{ // Se não foi achado um elemento maior ao elemento comparado, segue o rumo normal da lista, sem fazer novos apontamentos
				auxAnt = aux; // Auxiliar anterior recebe o aux
				aux = aux->prox; // Aux deslocará para o próximo
				auxProx = aux->prox; // Auxiliar próximo recebe o Aux próximo
				p = aux->prox; // P recebe o Aux próximo
			}
			maiorProx = NULL;
			maiorAnt = NULL;
		}
		
		return l;
}

void imprimir(Funcionarios *l, int count){ // Imprimir Funcionários
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

