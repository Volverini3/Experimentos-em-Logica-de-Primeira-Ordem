/*
* arquivo: "Controller.h"
* data: 28/06/2025
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void iniciarJogo();
 
void inicializarTabuleiro(Tabuleiro[][MAX]);

int lerId();

bool registrarFigura();

bool inserirFigura(Tabuleiro Tab[][MAX], int x, int y,char n, char f[], char t,char c[]);

char lerNome(Tabuleiro T[][MAX]);

void lerCoordenadas(Tabuleiro T[][MAX]);

bool verificarNome(Tabuleiro Tab[][MAX], char nom);

bool excluirFigura(Tabuleiro Tab[][MAX], int x, int y);

bool buscarPeca(Tabuleiro T[][MAX], char n);

bool verificarCor(Peca *p, char c[]);

char getTamanho(Peca *p);
 
bool verificarTamanho(Peca *p, char t);

bool verificarFigura(Peca *p, char *f);

bool aDireita(int x1 , int x2);

bool aEsquerda(int x1 , int x2);

bool acima(int y1 , int y2);

bool abaixo(int y1 , int y2);

bool maior(char tam1 , char tam2);

bool menor(char tam1 , char tam2);

bool entre(int x1 , int y1 , int x2 , int y2 , int x3 , int y3);

bool testeSentencas(Tabuleiro T[][MAX]);

void fclear();
 
