/*
* arquivo: "View.c"
* data: 28/06/2025
*/

#include "View.h"


int menuPrincipal(Tabuleiro T[][MAX]){
	SetConsoleOutputCP(CP_UTF8);
	int x;
	mostrarTabuleiro(T);
	printf("\n\n\t     MENU\n"); 
	printf("    --------------------\n");
	printf("     1- Inserir peça\n");
	printf("     2- Remover peça\n");
	printf("     3- Formar sentenças\n");
	printf("     4- Verificar figura\n");
	printf("     5- Sair\n");
	printf("     >");
	scanf("%d" , &x);
	fclear();
	return x;
}

bool menuSentencas(Tabuleiro T[][MAX]){
	int x = 0;
	int y = 0;
	int z = 0;
	int w = 0;
	bool existe, flag = TRUE;
	int codigo;
	char peca;
	//loop para montar sentencas
	do{
		x = 0;	y = 0;	z = 0;	w = 0;
		menuAtributos();
		
		//loop para ver se o a escolha do menu de sentencas esta dentro do esperado
		do{
			printf(">");
			scanf("%d" , &x);
			fclear();
			switch(x){
				case 1:
					while((y < 1)||(y > 3)){
						y = menuCor(T);
						fclear();
						if((y < 1)||(y > 3))
							printf("Valor incorreto\n");
					}
					codigo = y;
					do{
						printf("Insira a peça\n");	printf(">");
						scanf("%c" , &peca);
						fclear();
						existe = verificarNome(T, peca);
						if(existe == FALSE)
							printf("Não existe nenhuma peça com esse nome\n");
					}while(existe == FALSE);
					
					listaParametros[cursorp] = peca;
					cursorp++;
					break;
					
				case 2:
					while((y < 1)||(y > 5)){
						y = menuTamanho(T);
						fclear();
						if((y < 1)||(y > 5))
							printf("Valor incorreto\n");
					}
					codigo = 3 + y;
				
					if(y < 4){
						do{
							printf("Insira a peça\n");	printf(">");
							scanf("%c" , &peca);
							fclear();
							existe = verificarNome(T, peca);
							if(existe == FALSE)
								printf("Não existe nenhuma peça com esse nome\n");
						}while(existe == FALSE);
						listaParametros[cursorp] = peca;
						cursorp++;
					}else{
						printf("Insira a primeira peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
						printf("Insira a segunda peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
					}
					
					break;
					
				case 3: 
					while((y < 1)||(y > 3)){
						y = menuForma(T);
						fclear();
						if((y < 1)||(y > 3))
							printf("valor incorreto\n");
					}
					do{
						printf("Insira a peça\n");	printf(">");
						scanf("%c" , &peca);
						fclear();
						existe = verificarNome(T, peca);
						if(existe == FALSE)
							printf("Não existe nenhuma peça com esse nome\n");
					}while(existe == FALSE);
					listaParametros[cursorp] = peca;
					cursorp++;
					codigo = 8 + y;
					break;
					
				case 4:
					while((y < 1)||(y > 5)){
						y = menuPosicao(T);
						fclear();
						if((y < 1)||(y > 5))
							printf("valor incorreto\n");
					}
					if(y < 5){
						printf("Insira a primeira peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
						printf("Insira a segunda peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
					}else{
						printf("Insira a primeira peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
						printf("Insira a segunda peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
						printf("Insira a terceira peça: \n");
						scanf("%c" , &peca);	fclear();
						listaParametros[cursorp] = peca;
						cursorp++;
					}
					codigo = 11 + y;
					break;
					
				case 5: 
					cursors = 1;
					cursorp = 1;
				break;
					
				default: 
					printf("opcao incorreta \n");
					break;
			}
		}while(x < 1||x > 5);
		if(x !=5 )
			{
			listaSentencas[cursors] = codigo;
			cursors++;

			do{
				mostrarListaSentencas(cursors-1);
				printf("Inserir mais sentenças?\n");
				printf("0- Não\n");
				printf("1- Sim\n");
				printf(">");
				scanf("%d" ,&z);	fclear();
				if((z < 0) || (z > 1))
					printf("opção incorreta\n");
			}while((z < 0) || (z > 1));
			
			if(z != 0){
				while((w < 1)||(w > 2)){
					printf("Operadores lógicos\n");
					printf("1- E\n");
					printf("2- Ou\n");
					printf(">");
					scanf("%d" , &w);	fclear();
					if((w < 1)||(w > 2))
						printf("Opção incorreta");
					codigo = 16 + w;
					listaSentencas[cursors] = codigo;
					cursors++;
					mostrarTabuleiro(T);
				}
			}
		}	
		if(x == 5){
			flag = FALSE;
		}
	}while(z != 0 && x !=5);
	return flag;
}

void menuAtributos(Tabuleiro T[][MAX]){
	printf("\nAtributos:\n");
	printf("1- Cor \n");
	printf("2- Tamanho \n");
	printf("3- Forma \n");
	printf("4- Posição \n");
	printf("5- Cancelar\n");
}

int menuCor(Tabuleiro T[][MAX]){
	int op;
	system("cls");
	mostrarTabuleiro(T);
	printf("\n1- É vermelho \n");
	printf("2- É verde \n");
	printf("3- É azul \n");
	printf(">");
	scanf("%d" , &op);
	return op;
}

int menuTamanho(Tabuleiro T[][MAX]){
	int op;
	system("cls");
	mostrarTabuleiro(T);
	printf("\n1- É pequeno \n");
	printf("2- É médio \n");
	printf("3- É grande \n");
	printf("4- É maior \n");
	printf("5- É menor \n");
	printf(">");
	scanf("%d" , &op);
	return op;
}

int menuForma(Tabuleiro T[][MAX]){
	int op;
	system("cls");
	mostrarTabuleiro(T);
	printf("\n1- É quadrado \n");
	printf("2- É triângulo \n");
	printf("3- É circulo \n");
	printf(">");
	scanf("%d" , &op);
	return op;	
}

int menuPosicao(Tabuleiro T[][MAX]){
	int op;
	system("cls");
	mostrarTabuleiro(T);
	printf("\n1- A direita \n");
	printf("2- A esquerda \n");
	printf("3- Em cima \n");
	printf("4- Em baixo \n");
	printf("5- Entre duas pecas \n");
	printf(">");
	scanf("%d" , &op);	
	return op;
}

void mostrarTabuleiro(Tabuleiro T[][MAX]){
	int i,j;
	printf("\t     TABULEIRO");
	printf("\n\n   1   2   3   4   5   6   7   8");
	printf("\n _________________________________\n");
	for(i=1; i<=MAX; i++)
		{
		//printf("%d", i);
		printf(" |");	
		for(j=1; j<=MAX; j++){
			if(T[i][j].ocupado == TRUE)
				{
				printf(" %c |", T[i][j].objeto->nome);
				}
			else
				printf("   |");
			}
			
		
		printf("\n%d|___|___|___|___|___|___|___|___|\n",i);	
		}
}

void mostrarPeca(Tabuleiro T[][MAX],int x, int y){
	printf("\nNome: %c\n", T[x][y].objeto->nome);
	printf("Formato: %s\n", T[x][y].objeto->figura);
	printf("Tamanho: %c\n", T[x][y].objeto->tamanho);
	printf("Cor: %s\n\n", T[x][y].objeto->cor);
	sleep(3);
}

void mostrarListaSentencas(int f){
	int i,j;
	j = 1;
	printf("\nSentenças adicionadas:\n");
	for(i=1; i<= f; i++){
		printf("  - ");
		switch(listaSentencas[i]){
			case 1: printf("%c é vermelho", listaParametros[j++]);	break;
			case 2: printf("%c é verde", listaParametros[j++]);	break;
			case 3: printf("%c é azul", listaParametros[j++]);	break;
			case 4: printf("%c é pequeno", listaParametros[j++]);	break;
			case 5:	printf("%c é medio", listaParametros[j++]);	break;
			case 6: printf("%c é grande", listaParametros[j++]);	break;
			case 7: printf("%c é maior que %c",listaParametros[j++], listaParametros[j++]);	break;
			case 8: printf("%c é menor que %c",listaParametros[j++], listaParametros[j++]);	break;
			case 9: printf("%c é quadrado", listaParametros[j++]);	break;
			case 10: printf("%c é triangulo", listaParametros[j++]);	break;
			case 11: printf("%c é circulo", listaParametros[j++]);	break;
			case 12: printf("%c está à direita de %c",listaParametros[j++], listaParametros[j++]);	break;
			case 13: printf("%c está à esquerda de %c",listaParametros[j++], listaParametros[j++]);	break;
			case 14: printf("%c está em cima de %c",listaParametros[j++], listaParametros[++j]);	break;
			case 15: printf("%c está abaixo de %c",listaParametros[j++], listaParametros[++j]);	break;
			case 16: printf("%c está entre %c e %c",listaParametros[j++], listaParametros[j++], listaParametros[j++]);	break;
			case 17: printf("\te"); break;
			case 18: printf("\tou"); break;
			}
		printf("\n\n");
	}
}

void imprimirMensagem(char m[]){
	printf("%s", m);
} 


