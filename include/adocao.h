#ifndef ADOCAO_H
#define ADOCAO_H


#include "gatos.h"
#include "catshelter.h"

typedef struct{

    char nome[100];
    char CPF[16];
    char RG[14];
    char telefone[13];
    char rua[50];
    char numero[5];
    char bairro[30];
    char cidade[30];
    char estado[30];

}Adotante;

void menuAdocao(ListaCDE *l);
Gato criarAdocao(ListaCDE *l);
Adotante fichaAdocao(Gato gatoAdotado);
void imprimeFicha(Gato gatoAdotado, Adotante tutor);
void exibeTutor(Adotante tutor);
void criaArquivo(Arquivos arq, Gato gatoAdotado, Adotante tutor);

#endif