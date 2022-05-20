/*
	Name: Fila.h 	
	Author: Eduardo Cruz de Souza
	Date: 03/05/2022
	Description: Assinatura das funções de operações em uma fila 
				 Arquivo header de uma fila que armazena os elementos a partir da posição 0
*/


#include <stdio.h>
#include "Booleano.h"

#define Max 10 
#define sinal -1
#define ghost -2
        
typedef struct{
    int inicio;
    int fim;
    unsigned char Vetor[Max];
} Fila;

//interface
Fila criarFila();
void mostrarFila(Fila);
bool filaVazia(Fila);
unsigned char acessarPrimeiro(Fila);
Fila pushFila(Fila, unsigned char);
Fila popFila(Fila);


//implementação
Fila criarFila(){
    Fila A;
    A.inicio = sinal;
    A.fim = sinal;
    return A;
}

bool filaVazia(Fila A){
    bool vazia = TRUE;
    int i = A.inicio;
    if(i != sinal) vazia = FALSE;
    return vazia;
}

unsigned char acessarPrimeiro(Fila A){
    unsigned char x, y;
    if(A.inicio == sinal) x = ghost;
    else{
        y = A.inicio;
        x = A.Vetor[y];
    }
    return x;
}

Fila pushFila(Fila A, unsigned char y){
    int seg;
    seg = (A.fim + 1) % Max;
    if(seg != A.inicio){
        A.Vetor[seg] = y;
        if(A.inicio ==  sinal) A.inicio = seg;
        A.fim = seg;
    }
    return A;
}

Fila popFila(Fila A){
    int seg;
    if(A.inicio != sinal){
        if(A.inicio == A.fim){
            A.inicio = sinal;
            A.fim = sinal;
        }else{
            seg = (A.inicio + 1) % Max;
            A.inicio = seg;
        }
    }
    return A;
}

void mostrarFila(Fila A){
	int i, f;
	i = A.inicio;
	f = A.fim;
	int k;	
	if(A.inicio == sinal) printf("Fila Vazia!!");
	else {
		do{
			k = (i) % Max;
			printf(" %d ", A.Vetor[k]);
			i++;			
		} while (i != f + 1);
	}
}