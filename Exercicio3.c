#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct equipes{
		int equipe, pontos, vitorias, empates, derrotas;
		struct equipes *prox;
};
struct confrontos{
		int equip1, equip2, gol1, gol2;
};

typedef struct equipes equip;
typedef struct confrontos confr;

confr *inserirRodada(equip *l, int rodadaf, int rodada, confr confrontos[]); // Função de Inserção de Rodada e Validação
equip *inserirSetar(equip *l, int equip, int pt, int vit, int emp, int derrt); // Função de Setar Equipes para preparação das Rodadas
equip *organizar(equip *l, int quantidade); // Função para Organizar a classificação das Equipes
equip *verificar(equip *b1, equip *b2); // Função para Verificar qual equipe deve ser trocada de lugar no metodo de ordenação
equip *setar(equip *l); // Função para setar as Equipes, ela chama a Função inserirSetar
void imprimir(equip *l); // Função para impressão da tabela atualizada

main(){
		int rodada, rodadaf=1;
		
		equip *l = NULL;
		
		confr confrontos[5];
		
		int i=0;
		
		for(i=0; i<5; i++){
			confrontos[i].equip1 = 0;
			confrontos[i].equip2 = 0;
			confrontos[i].gol1 = 0;
			confrontos[i].gol2 = 0;
		}
		
		confr *pont;
		pont = confrontos;
		
		printf("Digite quandas rodadas o campeonato tera: ");
		scanf("%d", &rodada);
		
		int escolha, menu=0, k;
		
		l = setar(l);
		do{
			system("cls");
			printf("\n\t\tCampeonato de 10 equipes com %d rodada(s):\n\n", rodada);
			printf("- %d rodadas realizadas - \n", rodadaf-1);
			printf("\n\nEquipes cadastradas no campeonato!\n");
			imprimir(l);
			if(rodadaf<=rodada){
				printf("\n\n1 - Inserir %d rodada - \n", rodadaf);	
			}
			else
				printf("\n");
			printf("2 - Mostrar Tabela - \n");
			printf("3 - Sair do Sistema - \n");
			printf("Escolha a opcao desejada: ");
			scanf("%d", &escolha);
			
			switch(escolha){
				case 1:{
					pont = inserirRodada(l, rodadaf, rodada, pont);	
					if(rodadaf<=rodada){
						l = organizar(l, 10);
						imprimir(l);
						rodadaf++;
					}	
				
					getch();
					break;
				}
				case 2:{
					printf("\n\nVoce escolheu mostrar a Tabela do Campeonato!\n");
					getch();
					system("cls");
					imprimir(l);
					
					getch();
					break;
				}
				case 3:{
					menu++;
					
					printf("\n\nVoce escolheu sair do Programa!\n\n");
					printf("Saindo do Programa...\n");
					getch();
					
					break;
				}
				default:{
					printf("\nOpcao Invalida!Tente novamente...\n");
					getch();		
				}
			}
		}while(menu==0);
}

confr *inserirRodada(equip *l, int rodadaf, int rodada, confr *confrontos){ // Função para Inserção e validação das rodadas
		
		if(rodadaf<=rodada){ // Se as rodadas realizadas forem menor que o numero de rodadas haverá inserção de novas rodadas
			confr confrontoAtual[5];
			int i=0, equipe1, equipe2, confrant=1, confrag=1;
			
			for(i=0; i<5; i++){ // Setar confrontos da Rodada atual
				confrontoAtual[i].equip1 = 0;
				confrontoAtual[i].equip2 = 0;
				confrontoAtual[i].gol1 = 0;
				confrontoAtual[i].gol2 = 0;
			}
			
			inicio: // Rótulo para fazer os confrontos novamente se der erro na validação de algum confronto
				
			for(i=0; i<5; i++){ // 5 jogos por Rodada
				
				int vezes=0;
				
				do{
					getch();
					system("cls");
					
					if(rodadaf>1){ // Mostrará a rodada anterior se haver
						int k;
						
						printf("\n\nRodada Passada Confrontos:\n");
						for(k=0; k<5; k++){
							printf("Equipe %d: %d x %d :Equipe %d.\n", confrontos[k].equip1, confrontos[k].gol1, confrontos[k].gol2, confrontos[k].equip2);
						}
						printf("\n");	
					}	
					
					if(i>0){ // Partidas realizadas na Rodada atual
						int k;
						
						printf("\n\nPartidas realizadas na Rodada:\n");
						for(k=0; k<i; k++){
							printf("Equipe %d: %d x %d :Equipe %d.\n", confrontoAtual[k].equip1, confrontoAtual[k].gol1, confrontoAtual[k].gol2, confrontoAtual[k].equip2);
						}
						printf("\n");
					}

					int j;
					confrant=1;
					confrag=1;	
					if(vezes>0){ // Opção para Reiniciar a rodada se ocorrer erro de verificação
						int escolha;
						printf("Deseja reiniciar os enfrentamentos da rodada? <1>Sim <!=1>Nao: ");
						scanf("%d", &escolha);
						vezes=0;
						if(escolha==1){
							goto inicio;	// Jump para o rótulo inicio
						}
					}			
					printf("\nDigite a primeira equipe do enfrentamento %d da rodada %d: ", (i+1), rodadaf); // Digitar primeira equipe
					scanf("%d", &equipe1);
					printf("\nDigite a segunda equipe do enfrentamento %d da rodada %d: ", (i+1), rodadaf); // Digitar segunda equipe
					scanf("%d", &equipe2);
					if(equipe1>0 && equipe1<=10 && equipe2>0 && equipe2<=10 && equipe1!=equipe2){ // Condições para haver rodada
						if(rodadaf==1){ // verificar a primeira rodada
							if(i==0){ // Se for a primeira partida
								confrant=1;
								confrag=1;
							}
							else{ // Se for as próximas partidas
								for(j=0; j<i; j++){ // verificar rodada atual
									if(equipe1==confrontoAtual[j].equip1 || equipe1==confrontoAtual[j].equip2){
										confrant=0;
										confrag=0;
										break;
									}
								}
								for(j=0; j<i; j++){ // verificar rodada atual
									if(equipe2==confrontoAtual[j].equip1 || equipe2==confrontoAtual[j].equip2){
										confrant=0;
										confrag=0;
										break;
									}
								}
							}
						}
						else if(rodadaf>1){ // verificar rodadas posteriores a primeira rodada
							if(i==0){ // Se for a primeira partida
								confrag=1;
								
								for(j=0; j<5; j++){ // verificador rodada anterior
									if(equipe1==confrontos[j].equip1){
										if(equipe2==confrontos[j].equip2){
											confrant=0;
											break;	
										}
									}
								}
								
								for(j=0; j<5; j++){ // verificador rodada anterior
									if(equipe2==confrontos[j].equip1){
										if(equipe1==confrontos[j].equip2){
											confrant=0;
											break;	
										}
									}
								}
							}
							else{ // Se for as próximas partidas
								
								for(j=0; j<i; j++){ // verificador rodada atual
									if(equipe1==confrontoAtual[j].equip1 || equipe1==confrontoAtual[j].equip2){
										confrag=0;
										break;
									}
								}
								for(j=0; j<i; j++){ // verificador rodada atual
									if(equipe2==confrontoAtual[j].equip1 || equipe2==confrontoAtual[j].equip2){
										confrag=0;
										break;
									}
								}
								
								for(j=0; j<5; j++){ // verificador rodada anterior
									if(equipe1==confrontos[j].equip1){
										if(equipe2==confrontos[j].equip2){
											confrant=0;
											break;	
										}
									}
								}
								
								for(j=0; j<5; j++){ // verificador rodada anterior
									if(equipe2==confrontos[j].equip1){
										if(equipe1==confrontos[j].equip2){
											confrant=0;
											break;	
										}
									}
								}
							}
						}						
					}
					else{
						confrant=0; // partida não válida
						confrag=0; //
					}
					if(confrant==0 || confrag==0){ // Partida não válida
						printf("\nEquipes ja se enfrentaram ou sao invalidas. Tente a insercao novamente!\n\n");
						vezes++;
						confrant=1;
						confrag=1;
					}
					else if(confrant==1 && confrag==1){ // Partida Válida
						printf("\n\nEquipes Validadas!\n");
						
						/*equip *aux, *aux1, *aux2;
						
						for(aux=l; aux!=NULL; aux=aux->prox){
							if(aux->equipe==equipe1){
								aux1=aux;
								break;
							}
						}
						
						for(aux=l; aux!=NULL; aux=aux->prox){
							if(aux->equipe==equipe2){
								aux2=aux;
								break;
							}
						}
						
						*/ 
						int gol1, gol2;
						
						gol1 = rand() % 11; // Sorteio dos gols da primeira equipe
						gol2 = rand() % 11; // Sorteio dos gols da segunda equipe
						
						printf("Resultado da Partida: %d x %d.\n", gol1, gol2);
						
						if(gol1>gol2){
							printf("Equipe %d venceu a %d na partida!\n", equipe1, equipe2);
							/* aux1->pontos=aux1->pontos+3;
							aux1->vitorias=aux1->vitorias+1;
							aux2->derrotas=aux2->derrotas+1; */
						}
						else if(gol2>gol1){
							printf("Equipe %d venceu a %d na partida!\n", equipe2, equipe1);
							/* aux2->pontos=aux2->pontos+3;
							aux2->vitorias=aux2->vitorias+1;
							aux1->derrotas=aux1->derrotas+1; */
						}
						else{
							printf("A partida terminou empatada!\n");
							/* aux1->pontos=aux1->pontos+1;
							aux2->pontos=aux2->pontos+1;
							aux1->empates=aux1->empates+1;
							aux2->empates=aux2->empates+1; */
						}
						
						confrontoAtual[i].equip1 = equipe1; //
						confrontoAtual[i].equip2 = equipe2;	// Armazenando a partida da rodada na rodada atual
						confrontoAtual[i].gol1 = gol1; //
						confrontoAtual[i].gol2 = gol2;	//
						
						confrant=0;
						confrag=0;
					}
					
				}while(confrant==1 && confrag==1);
				vezes=0;
			}	
			
			equip *aux, *aux1, *aux2;
			
			for(i=0; i<5; i++){ // Achar as equipes que se enfrentaram e armazenar os pontos, vitorias, derrotas e empates para atualizar a Tabela do Campeonato
				for(aux=l; aux!=NULL; aux=aux->prox){
					if(aux->equipe==confrontoAtual[i].equip1){
						aux1=aux;
						break;
					}
				}
				
				for(aux=l; aux!=NULL; aux=aux->prox){
					if(aux->equipe==confrontoAtual[i].equip2){
						aux2=aux;
						break;
					}
				}
				
				if(confrontoAtual[i].gol1>confrontoAtual[i].gol2){
					aux1->pontos=aux1->pontos+3;
					aux1->vitorias=aux1->vitorias+1;
					aux2->derrotas=aux2->derrotas+1;
				}
				else if(confrontoAtual[i].gol2>confrontoAtual[i].gol1){
					aux2->pontos=aux2->pontos+3;
					aux2->vitorias=aux2->vitorias+1;
					aux1->derrotas=aux1->derrotas+1;
				}
				else{
					aux1->pontos=aux1->pontos+1;
					aux2->pontos=aux2->pontos+1;
					aux1->empates=aux1->empates+1;
					aux2->empates=aux2->empates+1;
				}
			}
			
			for(i=0; i<5; i++){ // Atribuir os confrontos da rodada atual para a rodada anterior, para a verificação da próxima rodada
				confrontos[i].equip1 = confrontoAtual[i].equip1;
				confrontos[i].equip2 = confrontoAtual[i].equip2;
				confrontos[i].gol1 = confrontoAtual[i].gol1;
				confrontos[i].gol2 = confrontoAtual[i].gol2;
			}
			
			printf("\n\nRodada Realizada:\n");
			for(i=0; i<5; i++){ // Mostra as partidas realizadas na rodada
				printf("Equipe %d: %d x %d :Equipe %d.\n", confrontos[i].equip1, confrontos[i].gol1, confrontos[i].gol2, confrontos[i].equip2);
			}
			printf("\n");
		}
		else{
			printf("\nO Campeonato terminou!\n\n");
		}
		
		return confrontos;
}

equip *inserirSetar(equip *l, int equip1, int pt, int vit, int emp, int derrt){ // Inserção com Setar equipes, com 0 em todos os atributos de pontuação
	
		equip *novo = NULL;
		
		if(l==NULL){ // Se for a primeira equipe
				
				novo = (equip*)malloc(sizeof(equip));
				
				novo->equipe = equip1;
				novo->pontos = pt;
				novo->vitorias = vit;
				novo->empates = emp;
				novo->derrotas = derrt;
				novo->prox = l;
				
				return novo;
		}
		else{ // Se for as próximas equipes
			equip *aux;
			
			novo = (equip*)malloc(sizeof(equip));
			
			for(aux=l; aux!=NULL; aux=aux->prox){
				if(aux->prox==NULL){
					break;
				}
			}
			
			aux->prox = novo;
			novo->prox = NULL;	
			novo->equipe = equip1;
			novo->pontos = pt;
			novo->vitorias = vit;
			novo->empates = emp;
			novo->derrotas = derrt;
			
			return l;
		}
}

equip *setar(equip *l){ // Função que leva ao Setar os atributos das equipes, Setar vitorias, derrotas, pontos e empates
		int cont=1, i;
		
		for(i=0; i<10; i++){
			l = inserirSetar(l, cont, 0, 0, 0, 0);
			cont++;
		}
		
		return l;	
}

equip *organizar(equip *l, int quantidade){ // Função para ordenar as 10 equipes de acordo com a classificação... com as equipes com mais pontos em primeiro, equipes com menos em ultimo
		equip *aux; // Ponteiro Auxiliar que recebe o endereço do primeiro elemento da lista e vai atualizando ao longo das comparações
		equip *aux2; // Ponteiro do Laço que procura a equipe a partir do criterio de organizacao do campeonato feito pelo desenvolvedor para comparação 
		equip *p; // Ponteiro que recebe o endereço próximo elemento em relação ao aux
		equip *aux3; // Ponteiro do Laço que procura o elemento anterior a equipe da comparação
		equip *menor; // Ponteiro que recebe o endereço  da equipe da comparação feita
		equip *menorProx; // Ponteiro que recebe o endereço do próximo elemento a equipe da comparação, se tiver
		equip *menorAnt; // Ponteiro que recebe o endereço do anterior elemento a equipe da comparação, se tiver
		equip *auxAnt; // Ponteiro que recebe o endereço do anterior elemento ao aux, que é o que percorre a lista
		equip *auxProx; // Ponteiro que recebe o endereço do proximo elemento ao aux, que é o que percorre a lista
		
		equip *min, *min2;
		
		int i, contador=0;
		
		aux = l;
		auxAnt = NULL;
		auxProx = aux->prox;
		p = aux->prox;
		
		for(i=0; i<(quantidade-1); i++){ // Laço definido pela quantidade de elementos menos 1
			
			min = aux;
			min2 = min;
			
			for(aux2=p; aux2!=NULL; aux2=aux2->prox){ // Laço para achar a equipe a ser comparada a partir do requisito
			
				min = verificar(min, aux2);
				
				if(min!=min2){
					
					menor = min; // Endereço da equipe
					
					contador++; // Contador que é incrementado para mostrar que foi achada a equipe		
				}
			}
			
			if(contador>0){ // Se foi achada a equipe a que está sendo comparada
			
				if(menor->prox==NULL){ 
					menorProx = NULL; // Se após a equipe não tiver elementos
				}
				else
					menorProx = menor->prox; // Ponteiro para o próximo elemento a equipe
				if(aux->prox==menor){ // A equipe é vizinha
					menorAnt = NULL; 
				}
				else{
					for(aux3=l; aux3!=NULL; aux3=aux3->prox){
						if(aux3->prox==menor){
							menorAnt = aux3; // A equipe possui anterior
						}
					}
				}
				
				if(aux==l){ // Se o elemento comparado é o primeiro da lista
					if(menorAnt==NULL){ // Se a equipe é vizinha
						aux->prox=menor->prox;
						menor->prox = aux;
						l = menor; // Atualização do ponteiro l 
						aux = menor->prox;	
					}	
					else{ // Se a equipe não é vizinha
						menorAnt->prox = aux;  
						menor->prox = aux->prox; // Reapontamento
						aux->prox = menorProx; 
						l = menor; // Atualização do ponteiro l
						aux = menor->prox;
					}
					auxAnt = l; // Anterior ao aux novo é o primeiro elemento
					auxProx = aux->prox; // Próximo ao auxiliar que será comparado
					p = aux->prox;
				}
				else{ // Se o elemento comparado não é o primeiro elemento da lista
					if(menorAnt==NULL){ // Se a equipe é vizinha
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para a equipe
						menor->prox = aux; // A equipe apontará para o auxiliar
						aux->prox = menorProx; // Próximo ao auxiliar apontará para o próximo a equipe, havendo assim a troca de posições
						
						p = aux->prox; // Atualização do P
						auxAnt = menor; // Ponteiro auxiliar anterior é a equipe
						auxProx = aux->prox;
					}
					else{ // Se a equipe não é vizinha
						auxAnt->prox = menor; // Anterior ao auxiliar aponta para a equipe
						menor->prox = auxProx; // A equipe apontará próximo para o próximo ao auxiliar
						menorAnt->prox = aux; // Antecessor apontará para o auxiliar que será trocado de posição
						aux->prox = menorProx; // Auxiliar agora em sua nova posição apontará para o próximo a equipe antiga
						
						aux = menor->prox; // Atualização do P
						auxAnt = menor; // Ponteiro auxiliar anterios é a equipe
						auxProx = aux->prox;
						p = aux->prox;
					}
				}
				contador=0;	
				min=NULL;
			}
			else{ // Se não foi achado uma equipe ao elemento comparado, segue o rumo normal da lista, sem fazer novos apontamentos
				auxAnt = aux; // Auxiliar anterior recebe o aux
				aux = aux->prox; // Aux deslocará para o próximo
				auxProx = aux->prox; // Auxiliar próximo recebe o Aux próximo
				p = aux->prox; // P recebe o Aux próximo
			}
			menorProx = NULL;
			menorAnt = NULL;
		}
		
		return l; // retorna ponteiro para o primeiro endereço de equipe
}

equip *verificar(equip *b1, equip *b2){ // Função verificadora das duas equipes comparadas... Se retornar b1 não há troca de posição entre equipes
		if(b1->pontos>b2->pontos){
			return b1; // retorna o mesmo endereço, logo não haverá troca de posições
		}
		else if(b2->pontos>b1->pontos){
			return b2; // retorna a equipe que possui mais pontos, a equipe que deverá ficar à frente da equipe do ponteiro b1
		}
		else{
			if(b1->vitorias>b2->vitorias){
				return b1; // retorna a primeira equipe, pois possui mais vitorias
			}
			else if(b2->vitorias>b1->vitorias){
				return b2; // retorna a segunda equipe, pois possui mais vitorias
			}
			else{
				if(b1->empates>b2->empates){
					return b1; // retorna a primeira equipe, pois possui mais empates
				}
				else if(b2->empates>b1->empates){
					return b2; // retorna a segunda equipe, pois possui mais empates
				}
				else{
					if(b1->derrotas<b2->derrotas){
						return b1; // retorna a primeira equipe, pois possui menos derrotas
					}
					else if(b2->derrotas<b1->derrotas){
						return b2; // retorna a segunda equipe, pois possui menos derrotas
					}
					else
						return b1; // retorna a primeira equipe, assim não há troca de posições
				}
			}
		}
}

void imprimir(equip *l){
		equip *aux;

		int coloc=1;

		printf("\nImpressao da Tabela do Campeonato:\n\n"); 
		printf("------------------------------------------------------------------\n");
		for(aux=l; aux!=NULL; aux=aux->prox){ // Impressão das equipes e sua classificação, pontos etc.
			printf("%d - Equipe %d ||   %d P   ||   %d V   ||   %d E   ||   %d D   ||\n", coloc, aux->equipe, aux->pontos, aux->vitorias, aux->empates, aux->derrotas);
			coloc++;
		}
		printf("------------------------------------------------------------------\n");
}
