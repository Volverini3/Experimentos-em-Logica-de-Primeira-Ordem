/*
* arquivo: "Controller.c"
* data: 28/06/2025
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Booleano.h"
#include "Controller.h"
#include "View.c"

void iniciarJogo(){
	Tabuleiro Tab[MAX+1][MAX+1];
	int opcao;
	bool resultado, concluido;
	char n;
	inicializarTabuleiro(Tab);
	
	do{
		concluido = FALSE;
		opcao = menuPrincipal(Tab);
		
		switch(opcao){
			case 1: concluido = registrarFigura(Tab);
					if(concluido){ 
						imprimirMensagem("\tPeça inserida com sucesso\n\n");
						}
					else
						imprimirMensagem("\tErro ao inserir peça\n\n");
				    break;
			
			case 2: imprimirMensagem("Digite o nome da peça que deseja excluir\n"); imprimirMensagem(">");
					scanf("%c", &n);
					fclear();
					if(buscarPeca(Tab, n))
						{
						concluido = excluirFigura(Tab, linha, coluna);
						if(concluido)	
							imprimirMensagem("\tPeça excluída com sucesso\n\n");	
						else 
							imprimirMensagem("\tErro ao excluir peça\n\n");
						}
				    else
						imprimirMensagem("\tPeça inexistente\n\n");		
				    break;
				    
			case 3: system("cls");
			
					if(menuSentencas(Tab)){
						resultado = testeSentencas(Tab);
						if(resultado)
							imprimirMensagem("\n      TRUE\n\n");
						else 
							imprimirMensagem("\n      FALSE\n\n");	
					}	
					sleep(3);
					break;    
				    
			case 4: imprimirMensagem("Digite o nome da peça que deseja ver\n"); imprimirMensagem(">");
					scanf("%c", &n);
					fclear();
					if(buscarPeca(Tab, n))
						mostrarPeca(Tab,linha, coluna);
					else
						imprimirMensagem("\tPeça inexistente\n");
					break;
					
			case 5: 
				break;
			
			default: system("cls");
					 imprimirMensagem("\t  Opção inválida\n\n");
		}	
	}while(opcao != 5);
	fclear();
	
}

bool buscarPeca(Tabuleiro T[][MAX], char n){
	int i, j;
	Peca *aux;
	bool achou = FALSE;
	for(i=1; i<=MAX; i++)
		for(j=1; j<=MAX; j++)
			if(T[i][j].ocupado == TRUE)
				if(T[i][j].objeto->nome == n)
					{
					achou = TRUE;
					linha = i;
					coluna = j;
					}
	return achou;
}

void inicializarTabuleiro(Tabuleiro T[][MAX]){
    int i,j;
    for( i =  1; i <= 8; i++)
        for( j =  1; j <= 8; j++)
        	{
        	T[i][j].ocupado = FALSE;	
        	T[i][j].objeto = NULL;
			}
            
}

bool inserirFigura(Tabuleiro T[][MAX], int x, int y,char n, char f[], char t,char c[]){
	bool inserir = FALSE;
	if(T[x][y].ocupado == FALSE)
		{
		Peca* novo;
		novo = malloc(sizeof(Peca));
		novo->nome = n;
		strcpy(novo->figura, f);
		novo->tamanho = t;
		strcpy(novo->cor, c);
		T[x][y].ocupado = TRUE; 
		T[x][y].objeto = novo;
		inserir = TRUE;
		}
	return inserir;
}

bool registrarFigura(Tabuleiro T[][MAX]){
	int x,y,id;
	bool registrou =FALSE;
	char nome;
	system("cls");

	nome = lerNome(T);
	lerCoordenadas(T);	x = linha;	y = coluna;	
	
	imprimirMensagem("\nAproxime a tag do leitor\n");
	do{
	id = lerId();
	if(id != -1){
		switch(id){
			case 5625265: registrou = inserirFigura(T, x,y,nome,"qdrd", 'p', "green"); 
						  system("cls");
						  break;
			case 5615213: registrou = inserirFigura(T, x,y,nome,"qdrd", 'p', "blue");
						  system("cls");
						  break;
			case 5656250: registrou = inserirFigura(T, x,y,nome,"qdrd", 'p', "red");
						  system("cls");
						  break;
			case 5650551: registrou = inserirFigura(T, x,y,nome,"qdrd", 'm', "green"); 
						  system("cls");
						  break;
			case 2548872: registrou = inserirFigura(T, x,y,nome,"qdrd", 'm', "red");
						  system("cls");
						  break;			  
			case 5622354: registrou = inserirFigura(T, x,y,nome,"qdrd", 'm', "blue");
						  system("cls");
						  break;
			case 5655939: registrou = inserirFigura(T, x,y,nome,"qdrd", 'g', "red");
						  system("cls");
						  break;
			case 5633130: registrou = inserirFigura(T, x,y,nome,"qdrd", 'g', "blue");
						  system("cls");
						  break;
			case 5615264: registrou = inserirFigura(T, x,y,nome,"qdrd", 'g', "green");
						  system("cls");
						  break;			  
			
			}	
		}	
	}while(registrou == FALSE);
	
	return registrou;
}

char lerNome(Tabuleiro T[][MAX]){
	char nome;
	do{
		imprimirMensagem("Digite um nome para a figura\n");	
		imprimirMensagem(">");
		scanf("%c", &nome);
		fclear();
		if(verificarNome(T, nome))	
			{
			system("cls");	imprimirMensagem("Esse nome já está sendo utilizado\n\n");	
			}
	}while(verificarNome(T, nome));
	return nome;
}

void lerCoordenadas(Tabuleiro T[][MAX]){
	do{
		imprimirMensagem("Digite as coordenadas(x, y)\n");
		imprimirMensagem(">");
		scanf("%d, %d", &linha,&coluna);
		fclear();	
		if(T[linha][coluna].ocupado == TRUE)
			{
			system("cls");	imprimirMensagem("Esse lugar já está ocupado\n\n");		
			}	
		else if(linha<1 || linha>8 || coluna<1 || coluna>8)
			{
			system("cls");	imprimirMensagem("Coordenadas inválidas\n\n");
			}
	}while(T[linha][coluna].ocupado == TRUE || linha<1 || linha>8 || coluna<1 || coluna>8);
}

int lerId(){
	// Nome da porta COM — altere conforme necessário
    const char *porta = "\\\\.\\COM8";  // "\\\\.\\COMX" é a forma correta para COM10 ou superior
	int id;
    HANDLE hSerial;
    hSerial = CreateFileA(porta,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
    id = -1;

    if (hSerial == INVALID_HANDLE_VALUE)
		{
    	system("cls");
        printf("Erro ao abrir a porta serial. Código: %ld\n\n", GetLastError());
    	}
	
	else{
		// Configurações da porta serial
    	DCB dcbSerialParams = {0};
    	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    	if (!GetCommState(hSerial, &dcbSerialParams)) 
			{
    		system("cls");
        	imprimirMensagem("Erro ao obter estado da porta\n");
        	CloseHandle(hSerial);
    		}
	
		else{
			dcbSerialParams.BaudRate = CBR_9600;
		    dcbSerialParams.ByteSize = 8;
		    dcbSerialParams.StopBits = ONESTOPBIT;
		    dcbSerialParams.Parity   = NOPARITY;
		
		    if (!SetCommState(hSerial, &dcbSerialParams)) {
		    	system("cls");
		        imprimirMensagem("Erro ao configurar a porta serial\n");
		        CloseHandle(hSerial);
		    	}
		    
		    else{
			    // Timeout da leitura
			    COMMTIMEOUTS timeouts = {0};
			    timeouts.ReadIntervalTimeout = 50;
			    timeouts.ReadTotalTimeoutConstant = 50;
			    timeouts.ReadTotalTimeoutMultiplier = 10;
			
			    SetCommTimeouts(hSerial, &timeouts);
			    char buffer[256];
			    DWORD bytesRead;
			    int leu = 1;
			
			    imprimirMensagem("Lendo dados da porta serial...\n");
			
			    do{
			        if (ReadFile(hSerial, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) 
						{
			            if (bytesRead > 0)
							{
			                buffer[bytesRead] = '\0'; // finaliza a string
			                leu = 0;
			                id = atoi(buffer);
			            	}
			        	}
					else {
			        	system("cls");
			            imprimirMensagem("Erro ao ler dados.\n");
			        	}
			    }while (leu == 1 || id < 1000000);
			    CloseHandle(hSerial);
			}	
		}	
	}
	return id;    
}

bool excluirFigura(Tabuleiro Tab[][MAX], int x, int y){
	bool excluiu = FALSE;
	if(Tab[x][y].ocupado == TRUE)
		{
		Peca* aux;
		aux = Tab[x][y].objeto;
		free(aux);
		Tab[x][y].objeto = NULL;
		Tab[x][y].ocupado = FALSE;
		excluiu = TRUE;
		}
	return excluiu;
}

bool verificarNome(Tabuleiro Tab[][MAX], char nom){
	int i,j;
	bool achou = FALSE;
	for(i=1; i<=MAX; i++)
		for(j=1; j<=MAX; j++)
			{
			if(Tab[i][j].ocupado == TRUE)
				{
				if(Tab[i][j].objeto->nome == nom)
					achou = TRUE;
				}
			}
	return achou;
}

bool verificarCor(Peca *p, char c[]){
	bool igual = FALSE;
	if(p != NULL){
		if(strcmp(p->cor, c) == 0)
			igual = TRUE;
	}
	return igual;
}

char getTamanho(Peca *p){
	char tam;
	tam = p->tamanho;
	return tam;
}

bool verificarTamanho(Peca *p, char t){
	bool igual = FALSE;
	if(p != NULL){
		if(p->tamanho == t)
		igual = TRUE;
	}
	return igual;
}

bool verificarFigura(Peca *p, char f[]){
	bool igual = FALSE;
	if(p != NULL){ 
		if(strcmp(p->figura, f) == 0)
			igual = TRUE;
	}
	return igual;
}

bool aDireita(int x1 , int x2){
	bool q = FALSE;
	if(x1 > x2)
		q = TRUE;
	return q;	
}
 
bool aEsquerda(int x1 , int x2){
	bool q = FALSE;
	if(x2 > x1)
		q = TRUE;
	return q;
}
 
bool acima(int y1 , int y2){
	bool q = FALSE;
	if(y1 < y2)	
		q = TRUE;
	return q;
}
 
bool abaixo(int y1 , int y2){
	bool q = FALSE;
	if(y2 < y1)
		q = TRUE;
	return q;
}
 
bool maior(char tam1 , char tam2){
	bool q = FALSE;
	if(tam1 == 'g')
		if(tam2 != 'g')
			q = TRUE;
	else if(tam1 == 'm')
		if(tam2 == 'p')
			q = TRUE;
	return q;	
}
 
bool menor(char tam1 , char tam2){
	bool q = FALSE;
	if(tam1 == 'p')
		if(tam2 != 'p')
			q = TRUE;
	else if(tam1 == 'm')
		if(tam2 == 'g')
			q = TRUE;
	return q;	
}

bool entre(int x1 , int y1 , int x2 , int y2 , int x3 , int y3){
	bool q = FALSE;
	if((x1 == x2)&&(x2 == x3)){
		if(((y2 < y1)&&(y1 < y3))||((y3 < y1)&&(y1 < y2)))
			q = TRUE;
	}else if((y1 == y2)&&(y2 == y3)){
		if(((x2 < x1)&&(x1 < x3))||((x3 < x1)&&(x1 < x2)))
			q = TRUE;
	}else if((abs((x1 - x2)) == abs(y1 - y2))&&(abs((x1 - x3)) == abs(y1 - y3))){
		if(((y2 > y1)&&(y1 > y3))||((y3 > y1)&&(y1 > y2)))
			q = TRUE;
	}
	return q;
} 

bool testeSentencas(Tabuleiro T[][MAX]){
	int fim = cursors - 1;
	int param = 1;
	bool s1 = FALSE , s2 = FALSE;
	int x1 , x2 , x3 , y1 , y2 , y3;
	char t1 , t2;
	cursors = 1;
	cursorp = 1;
	int i = 1;
	while(i <= fim){
		switch(listaSentencas[i]){
			case 1:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarCor(T[linha][coluna].objeto , "red");
				break;
			case 2:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarCor(T[linha][coluna].objeto,"green");
				break;
			case 3:	
				buscarPeca(T , listaParametros[param]);
				s2 = verificarCor(T[linha][coluna].objeto,"blue");
				break;
			case 4:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarTamanho(T[linha][coluna].objeto , 'p');
				break;
			case 5:	
				buscarPeca(T , listaParametros[param]);
				s2 = verificarTamanho(T[linha][coluna].objeto , 'm');
				break;			
			case 6:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarTamanho(T[linha][coluna].objeto , 'g');
				break;
			case 7:
				buscarPeca(T , listaParametros[param]);
				t2 = getTamanho(T[linha][coluna].objeto);
				param++;
				buscarPeca(T , listaParametros[param]);
				t1 = getTamanho(T[linha][coluna].objeto);
				s2 = maior(t1 , t2);
				break;
			case 8:
				buscarPeca(T , listaParametros[param]);
				t1 = getTamanho(T[linha][coluna].objeto);
				param++;
				buscarPeca(T , listaParametros[param]);
				t2 = getTamanho(T[linha][coluna].objeto);
				s2 = menor(t1 , t2);
				break;
			case 9:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarFigura(T[linha][coluna].objeto , "qdrd");
				break;
			case 10:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarFigura(T[linha][coluna].objeto , "tri");
				break;
			case 11:
				buscarPeca(T , listaParametros[param]);
				s2 = verificarFigura(T[linha][coluna].objeto , "circ");
				break;
			case 12:
				buscarPeca(T , listaParametros[param]);
				x1 = linha;
				param++;
				buscarPeca(T , listaParametros[param]);
				x2 = linha;
				s2 = aDireita(x1 , x2);
				break;
			case 13:
				buscarPeca(T , listaParametros[param]);
				x1 = linha;
				param++;
				buscarPeca(T , listaParametros[param]);
				x2 = linha;
				s2 = aEsquerda(x1 , x2);
				break;
			case 14:
				buscarPeca(T , listaParametros[param]);
				y1 = coluna;
				param++;
				buscarPeca(T , listaParametros[param]);
				y2 = coluna;
				s2 = acima(y1 , y2);
				break;
			case 15:
				buscarPeca(T , listaParametros[param]);
				y1 = coluna;
				param++;
				buscarPeca(T , listaParametros[param]);
				y2 = coluna;
				s2 = abaixo(y1 , y2);
				break;
			case 16:
				buscarPeca(T , listaParametros[param]);
				x1 = linha;
				y1 = coluna;
				param++;
				buscarPeca(T , listaParametros[param]);
				x2 = linha;
				y2 = coluna;
				param++;
				buscarPeca(T , listaParametros[param]);
				x3 = linha;
				y3 = coluna;
				s2 = entre(x1 , y1 , x2 , y2 , x3 ,y3);
				break;
		}
		param++;
		
		if(i == 1)
			s1 = s2;
		else if((i <= fim)){
			if(listaSentencas[i-1] == 17)
				{
				//printf("%d	", s1); printf("%d	", s2); 
				s1 = s1 && s2;	
				}
			else if(listaSentencas[i-1] == 18)
				{
				//printf("%d	", s1); printf("%d	", s2);
				s1 = s1 || s2;	
				}
				
		}
		//printf("%d\n", s1);
		i++;
	}
	system("cls");
	mostrarListaSentencas(fim);
	return s1;
}

void fclear()
  {
  int ch;
  while((ch=fgetc(stdin))!=EOF&&ch!='\n');
  }
