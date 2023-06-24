#ifndef ADOCAO_H
#define ADOCAO_H


#include "gatos.h"
#include "catshelter.h"

typedef struct{

    char nome[100];
    char CPF[15];
    char RG[13];
    char telefone[12];
    char rua[50];
    char numero[5];
    char bairro[30];
    char cidade[30];
    char estado[30];

}Adotante;

void menuAdocao(ListaCDE *l);
void criarAdocao(ListaCDE *l, Gato *gatoAdotado, Adotante *tutor);
void fichaAdocao(Adotante *tutor);
int imprimeFicha(Gato *gatoAdotado, Adotante *tutor);
void exibeTutor(Adotante *tutor);
void criaArquivo(Arquivos arq, Gato *gatoAdotado, Adotante *tutor);

#endif