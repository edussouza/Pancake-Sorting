/*
	Name: Pilha.h 2.0	
	Author: Eduardo Cruz de Souza
	Date: 29/04/22 10:26
	Description: Implementação de um programa que coloca uma pilha 
	aleatoria em ordem crescente, com o menor número no topo da pilha,
	usando a estratégia de Pancake Sorting

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Booleano.h"
#include "Fila.h"
#include "Pilha.h"

//interface
Pilha inverter(Pilha, int);
int contarPilha(Pilha, unsigned char);
Pilha construirPilha(int);

int main (){
	
    int n, qtd;
    
    int panquecas = 8;
    
    Pilha s1;
  
    s1 = criarPilha();
   	 
    s1 = construirPilha(panquecas);
    
    mostrarPilha(s1);
    
    printf("------------------\n");
    
    n = panquecas;
	
		do {
			qtd = contarPilha(s1, n);
			if (qtd != n) {
				if (qtd != 1) {
					s1 = inverter(s1, qtd);					
				}
				s1 = inverter(s1, n);
			}
			n -= 1;
		} while (n != 1);
	
	mostrarPilha(s1);


	
}

//implementação 
Pilha inverter(Pilha A, int n){
    Fila B;
    B = criarFila();
    unsigned char chP;
    unsigned char chF;
    int i;
    if(chP != sinal){
    	chP = acessarTopo(A);
        for(i = 0; i < n; i++){
        	
            B = pushFila(B, chP);
            A = popPilha(A);
            chP = acessarTopo(A);
        }         
		for(i = 0; i < n; i++){
            chF = acessarPrimeiro(B);
            A = pushPilha(A, chF);
            B = popFila(B);
        }
    }
    return A;
}

int contarPilha(Pilha A, unsigned char x){
    int cont = 0;
	Pilha C = criarPilha();
    C = A; 
    bool vazia = pilhaVazia(A);
    unsigned char ch = acessarTopo(C);    
    
    if(vazia == FALSE){	
        while(ch != x){
            C = popPilha(C);
            ch = acessarTopo(C); 
            cont++;            
    	}    
  }
  return cont + 1;
}

Pilha construirPilha(int n){
    Pilha A;
    A = criarPilha();
    unsigned char Vet[n];
    int i, random, element, aux;
    
    srand(time(NULL));
    
    for(i = 0; i < n; i++){     
         Vet[i] = i + 1;
    }
	for(i = 0; i < n; i++){		
		random = rand() % n;
		aux = Vet[i];
		Vet[i] = Vet[random];
		Vet[random] = aux;
	}							
    for(i = 0; i < n; i++){		
        element = Vet[i];
        A = pushPilha(A, element);
    }
    return A;
}    