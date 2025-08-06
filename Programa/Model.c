/*
* arquivo: "Model.c"
* data: 28/06/2025
*/

#include "Model.h"

typedef struct Peca{
	char nome;
    char figura[10];
    char tamanho;
    char cor[10];
}Peca;

typedef struct Tabuleiro{
    bool ocupado;
    Peca *objeto;
}Tabuleiro;


