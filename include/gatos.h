/*
    header para a definicao do struct Gato e funcoes do CRUD
*/

#ifndef GATO_H
#define GATO_H

typedef struct Gato {

    unsigned int id;
    char nome[50];
    char adocao;
    unsigned int idade;
    char raca[30];
    char pelagem[30];
    int numVacinas;
    char vacinas[10][30];
    char castrado;
    char comorbidades[100];
    char obs[200];
    char dataDeEntrada[11];
    char dataDeAdocao[11];

}Gato;

void createGato(Gato *);
void readGato(Gato *);
void updateGato(Gato *);
void deleteGato(Gato *);


#endif