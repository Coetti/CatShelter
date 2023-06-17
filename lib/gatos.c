/* 
    esta eh a implementacao da funcoes relacionadas ao gerenciamentos dos gatos (CRUD) 

    Create, 
    Read, 
    Update,
    Delete

    typedef struct Gato {

    unsigned int id;
    char nome[50];
    unsigned int idade;
    char raca[30];
    char pelagem[30];
    char vacinas[30][30];
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

*/

#include <stdio.h>
#include <string.h>


void createGato(Gato *gatos){
    Gato *cat = malloc(sizeof(Gato))
}

