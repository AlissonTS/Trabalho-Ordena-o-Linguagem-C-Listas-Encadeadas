#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Baralho{
		int valor;
		char naipe[7];
		struct Baralho *prox;
};

typedef struct Baralho baralho;

baralho *insere(baralho *b, int valor1, char *naipe1); // Função para Inserir cada carta
baralho *inserir(baralho *b); // Função que chama o insere
baralho *organizar(baralho *l, int quantidade); // Ordenar Baralho
baralho *verificar(baralho *b1, baralho *b2); // Verificar quais cartas trocar de lugar na ordenação
void imprimir(baralho *b); // Imprimir Baralho

main(){
		baralho *l, *aux;
		
		l = NULL;
		
		int menu=0, escolha, quantidade=0, cont=0;
		
		l = inserir(l);
		
		for(aux=l; aux=aux->prox; aux!=NULL){
			quantidade++;	
		}
		quantidade++;
		
		do{
			system("cls");
			printf("\tAlgoritmo de Ordenacao de Baralho - 4 Naipes %d - Cartas\n\n", quantidade);
			printf("Criterio para a Ordenacao do Baralho pelo Desenvolvedor:\n");	
			printf("- Primeiro cartas de ESPADA!\n");
			printf("- Segundo cartas de BASTO!\n");	
			printf("- Terceiro cartas de OURO!\n");
			printf("- Quarto cartas de COPA!\n\n");
			printf("- Insercao Automatica (definida no codigo em .c) - \n");
			printf("- Opcoes - \n");
			printf("- 1 - Mostrar Baralho - \n");
			printf("- 2 - Organizar Baralho - \n");
			printf("- 3 - Sair do Programa - \n");
			printf("Escolha qual opcao voce deseja: ");
			scanf("%d", &escolha);
			
			switch(escolha){
				case 1:{
					printf("\nVoce escolheu a opcao de imprimir as cartas do Baralho!\n");
					if(cont==0){
						printf("BARALHO DESORDENADO!\n");
						cont++;
					}
					else{
						printf("\nBARALHO ORDENADO!\n\n");	
					}
						
					imprimir(l);
					
					getch();
					break;
				}
				case 2:{
					printf("\nVoce escolheu a opcao de organizar as cartas do Baralho!\n");
					l = organizar(l, quantidade);					
					
					getch();
					break;
				}
				case 3:{
					printf("\nVoce escolheu sair do Programa!\n");
					printf("Saindo do Programa...\n");
					
					menu++;
										
					break;
				}
				default:{
					printf("\nOpcao Invalida, retornando ao menu principal...\n");
				}
			}
			
		}while(menu==0);
		
		system("pause");
}

baralho *inserir(baralho *b){ // Chama o insere para Inserir cada carta
		printf("\nInserindo cartas do baralho...\n");
		
		b = insere(b, 3, "copa");
	    b = insere(b, 11, "ouro");
	    b = insere(b, 5, "copa");
	    b = insere(b, 7, "copa");
	    b = insere(b, 8, "copa");
	    b = insere(b, 12, "copa");
	    b = insere(b, 12, "basto");
	    b = insere(b, 13, "ouro");
	    b = insere(b, 1, "basto");
	    b = insere(b, 8, "ouro");
	    b = insere(b, 8, "espada");
	    b = insere(b, 2, "ouro");
	    b = insere(b, 1, "copa");
	    b = insere(b, 11, "copa");
	    b = insere(b, 11, "basto");
	    b = insere(b, 2, "espada");
	    b = insere(b, 4, "copa");
	    b = insere(b, 6, "copa");
	    b = insere(b, 3, "espada");
	    b = insere(b, 6, "basto");
	    b = insere(b, 10, "espada");
	    b = insere(b, 12, "ouro");
	    b = insere(b, 1, "ouro");
	    b = insere(b, 11, "espada");
	    b = insere(b, 7, "basto");
	    b = insere(b, 6, "ouro");
	    b = insere(b, 6, "espada");
	    b = insere(b, 2, "basto");
	    b = insere(b, 4, "ouro");
	    b = insere(b, 7, "espada");
	    b = insere(b, 10, "basto");
	    b = insere(b, 2, "copa");
	    b = insere(b, 9, "espada");
	    b = insere(b, 7, "ouro");
	    b = insere(b, 1, "espada");
	    b = insere(b, 8, "basto");
	    b = insere(b, 9, "ouro");
	    b = insere(b, 13, "basto");
	    b = insere(b, 4, "espada");
	    b = insere(b, 9, "basto");
	    b = insere(b, 5, "espada");
	    b = insere(b, 5, "ouro");
	    b = insere(b, 10, "ouro");
	    b = insere(b, 9, "copa");
	    b = insere(b, 3, "ouro");
	    b = insere(b, 3, "basto");
	    b = insere(b, 13, "copa");
	    b = insere(b, 4, "basto");
	    b = insere(b, 12, "espada");
	    b = insere(b, 5, "basto");
	    b = insere(b, 13, "espada");
	    b = insere(b, 10, "copa");
		
		return b;
}

baralho *insere(baralho *b, int valor1, char *naipe1){ // Insercao de cada carta
		
		baralho *novo;
	
		if(b==NULL){ // Se for a primeira carta do Baralho
			novo = (baralho*)malloc(sizeof(baralho));
						
			strcpy(novo->naipe, naipe1);
			novo->valor = valor1;
			strupr(novo->naipe);
			novo->prox = b;	
			
			
			return novo;
		}
		else{ // Se for as próximas cartas do Baralho
			novo = (baralho*)malloc(sizeof(baralho));
			
			baralho *aux, *aux2;
			for(aux=b; aux!=NULL; aux=aux->prox){
				if(aux->prox==NULL){
					aux2 = aux;
					break;
				}
			}
			
			aux2->prox = novo;
			
			strcpy(novo->naipe, naipe1);
			strupr(novo->naipe);			
			novo->valor = valor1;
			novo->prox = NULL;
			
			return b;
		}
}

baralho *organizar(baralho *l, int quantidade){ // Organizar o Baralho
		baralho *aux; // Ponteiro Auxiliar que recebe o endereço do primeiro elemento da lista e vai atualizando ao longo das comparações
		baralho *aux2; // Ponteiro do Laço que procura a carta a partir do criterio de organizacao do baralho feito pelo desenvolvedor para comparação 
		baralho *p; // Ponteiro que recebe o endereço próximo elemento em relação ao aux
		baralho *aux3; // Ponteiro do Laço que procura o elemento anterior a carta da comparação
		baralho *menor; // Ponteiro que recebe o endereço  da a carta da comparação feita
		baralho *menorProx; // Ponteiro que recebe o endereço do próximo elemento a a carta da comparação, se tiver
		baralho *menorAnt; // Ponteiro que recebe o endereço do anterior elemento a a carta da comparação, se tiver
		baralho *auxAnt; // Ponteiro que recebe o endereço do anterior elemento ao aux, que é o que percorre a lista
		baralho *auxProx; // Ponteiro que recebe o endereço do proximo elemento ao aux, que é o que percorre a lista
		
		baralho *min, *min2;
		
		int i, contador=0, verific=0;
		
		aux = l;
		auxAnt = NULL;
		auxProx = aux->prox;
		p = aux->prox;
		
		for(i=0; i<(quantidade-1); i++){ // Laço definido pela quantidade de elementos menos 1
			
			min = aux;
			min2 = min;
			
			for(aux2=p; aux2!=NULL; aux2=aux2->prox){ // Laço para achar a carta a ser comparada a partir do requisito
			
				min = verificar(min, aux2);
				
				if(min!=min2){
					
					menor = min; // Endereço da carta
					
					contador++; // Contador que é incrementado para mostrar que foi achada a carta		
				}
			}
			
			if(contador>0){ // Se foi achada a carta a que está sendo comparada
			
				if(menor->prox==NULL){ 
					menorProx = NULL; // Se após a carta não tiver elementos
				}
				else
					menorProx = menor->prox; // Ponteiro para o próximo elemento a carta
				if(aux->prox==menor){ // A carta é vizinha
					menorAnt = NULL; 
				}
				else{
					for(aux3=l; aux3!=NULL; aux3=aux3->prox){
						if(aux3->prox==menor){
							menorAnt = aux3; // A carta possui anterior
						}
					}
				}
				
				if(aux==l){ // Se o elemento comparado é o primeiro da lista
					if(menorAnt==NULL){ // Se a carta é vizinha
						aux->prox=menor->prox;
						menor->prox = aux;
						l = menor; // Atualização do ponteiro l 
						aux = menor->prox;	
						verific++;
					}	
					else{ // Se a carta não é vizinha
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
					if(menorAnt==NULL){ // Se a carta é vizinha
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para a carta
						menor->prox = aux; // A carta apontará para o auxiliar
						aux->prox = menorProx; // Próximo ao auxiliar apontará para o próximo a carta, havendo assim a troca de posições
						
						p = aux->prox; // Atualização do P
						auxAnt = menor; // Ponteiro auxiliar anterior é a carta
						auxProx = aux->prox;
						verific++;
					}
					else{ // Se a carta não é vizinha
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para a carta
						menor->prox = auxProx; // A carta apontará próximo para o próximo ao auxiliar
						menorAnt->prox = aux; // Antecessor apontará para o auxiliar que será trocado de posição
						aux->prox = menorProx; // Auxiliar agora em sua nova posição apontará para o próximo a carta antiga
						
						aux = menor->prox; // Atualização do P
						auxAnt = menor; // Ponteiro auxiliar anterios é a carta
						auxProx = aux->prox;
						p = aux->prox;
						verific++;
					}
				}
				contador=0;	
				min=NULL;
			}
			else{ // Se não foi achado uma carta ao elemento comparado, segue o rumo normal da lista, sem fazer novos apontamentos
				auxAnt = aux; // Auxiliar anterior recebe o aux
				aux = aux->prox; // Aux deslocará para o próximo
				auxProx = aux->prox; // Auxiliar próximo recebe o Aux próximo
				p = aux->prox; // P recebe o Aux próximo
			}
			menorProx = NULL;
			menorAnt = NULL;
		}
		
		if(verific>0){
			printf("\n\nBaralho foi ordenado!\n");
		}
		else
			printf("\n\nBaralho ja esta ordenado!\n");
		
		return l;
}

baralho *verificar(baralho *b1, baralho *b2){ // Verificar qual carta é maior que outra
		if(strcmp(b1->naipe, "ESPADA")==0){
			if(strcmp(b2->naipe, "ESPADA")==0){
				if(b1->valor<=b2->valor)
					return b1; // retorna primeira carta, não há troca de posições
				else
					return b2; // retorna segunda carta, há troca de posições
			}
			else
				return b1; // retorna primeira carta, não há troca de posições
		}
		else if(strcmp(b1->naipe, "BASTO")==0){
			if(strcmp(b2->naipe, "BASTO")==0){
				if(b1->valor<=b2->valor)
					return b1; // retorna primeira carta, não há troca de posições
				else
					return b2; // retorna segunda carta, há troca de posições
			}
			else if(strcmp(b2->naipe, "ESPADA")==0){
				return b2; // retorna segunda carta, há troca de posições
			}
			else
				return b1; // retorna primeira carta, não há troca de posições
		}
		else if(strcmp(b1->naipe, "OURO")==0){
			if(strcmp(b2->naipe, "OURO")==0){
				if(b1->valor<=b2->valor)
					return b1; // retorna primeira carta, não há troca de posições
				else
					return b2; // retorna segunda carta, há troca de posições
			}
			else if(strcmp(b2->naipe, "ESPADA")==0 || strcmp(b2->naipe, "BASTO")==0){
				return b2; // retorna segunda carta, há troca de posições
			}
			else
				return b1; // retorna primeira carta, não há troca de posições
		}
		else if(strcmp(b1->naipe, "COPA")==0){
			if(strcmp(b2->naipe, "COPA")==0){
				if(b1->valor<=b2->valor)
					return b1; // retorna primeira carta, não há troca de posições
				else
					return b2; // retorna segunda carta, há troca de posições			
			}
			else
				return b2; // retorna segunda carta, há troca de posições
		}
}

void imprimir(baralho *b){ // Impressão do Baralho
		
		baralho *aux, *ant;
		
		printf("\n\t\t\tCartas do Baralho:\n");
		
		ant = NULL;
		int cont=0;
		
		for(aux=b; aux!=NULL; aux=aux->prox){
			
			if(ant==NULL){
				printf("\nNaipe:\n");
				puts(aux->naipe);
			}
			else{
				int i;
				
				i = strcmp(aux->naipe, ant->naipe);
				
				if(i!=0){
					printf("\n\nNaipe:\n");
					puts(aux->naipe);
				}
			}
			if(aux->valor==1)
				printf("A - ");
			else if(aux->valor==11)
				printf("J - ");
			else if(aux->valor==12)
				printf("Q - ");
			else if(aux->valor==13)
				printf("K - ");
			
			else
				printf("%d - ", aux->valor);
			
			ant = aux;
			cont++;
		}
		printf("\n\n%d Cartas", cont);	
}
