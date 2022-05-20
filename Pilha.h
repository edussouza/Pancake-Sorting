/*
	Name: Pilha.h 2.0	
	Author: Eduardo Cruz de Souza / Elias
	Date: 29/04/22 10:26
	Description: Implementação das operações em uma pilha 
				 Arquivo header de uma pilha que armazena os elementos a partir da posição 0
*/

#include <stdio.h>
#include "Booleano.h"

#define Max 10 
#define sinal -1
#define ghost -2

typedef struct {
	int topo;
	unsigned char Vetor[Max];	
}Pilha;

//interface
Pilha criarPilha();
bool pilhaVazia(Pilha);
Pilha pushPilha(Pilha, unsigned char);
Pilha popPilha(Pilha);
void mostrarPilha(Pilha);
unsigned char acessarTopo(Pilha);

//implementação
Pilha criarPilha(){
	Pilha A;
	A.topo = sinal;
	return A;
}

bool pilhaVazia(Pilha A){
	bool vazia;
	if(A.topo == sinal) vazia = TRUE;
	else vazia = FALSE;
	return vazia;
}

Pilha pushPilha(Pilha A, unsigned char x){
	int t;
	int m = Max - 1;
	if (A.topo != m){
	A.topo += 1;
	t = A.topo;
	A.Vetor[t] = x;
  }
	return A;	
}

Pilha popPilha(Pilha A){
	if (A.topo != sinal){
		int t = A.topo;
		A.topo = t - 1;
	}
	return A;
}

void mostrarPilha(Pilha A){
	int t = A.topo;
	if(t == sinal) printf("\npilha vazia");
	else{
		int k;
		for(k = t; k>=0; k--){
			printf(" %d\n", A.Vetor[k]);
		}
	}
}

unsigned char acessarTopo(Pilha A){
	unsigned char ch;
	if(A.topo == sinal) ch = ghost;
	else ch = A.Vetor[A.topo];
	return ch;
}