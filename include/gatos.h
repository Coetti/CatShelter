/*
    header para a definicao do objeto Gato e funcoes do CRUD e alocao dinamica deles
*/

#ifndef GATOS_H
#define GATOS_H
typedef struct{

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

typedef struct no {
    Gato dados;
    struct no *ant;
    struct no *prox;
} No;

typedef struct ListaCDE{
    No *inicio;
    No *fim;
    int tam;
} ListaCDE;

void menuGato(ListaCDE *lista);
Gato createGato();
int insereOrdenado(ListaCDE *l, Gato dados);
void exibeGato(Gato);
void mostra(ListaCDE *l, int filtro);
Gato* procuraNome(ListaCDE *l, char nomeProcurado[]);
int procuraID(ListaCDE *l, unsigned int id);
int retira(ListaCDE *l, unsigned int id);
int atualiza(ListaCDE *l, unsigned int id, int filtro);


void cria(ListaCDE *l);
int insere(ListaCDE *l, Gato dados);
int estaVazia(ListaCDE l);
Gato getInicio(ListaCDE l);
Gato getFim(ListaCDE l);
int getTamanho(ListaCDE l);

#endif