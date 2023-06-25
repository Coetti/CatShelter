#ifndef DOACOES_H
#define DOACOES_H


#include "gatos.h"
#include "catshelter.h"

typedef struct{
    unsigned int id;
    char descricao[50];
    int quantidade;
    float peso;
    char dataDeValidade[20];
}Doacao; 

void menuDoacao(ListaCDE* l);
void criarDoacao(Doacao *doacoes);
void entradaEstoque(Doacao *doacoes);
void saidaEstoque(Doacao *doacoes);
void exibirEstoque(Doacao *doacoes);

#endif