/*
    header para a definicao do objeto Gato e funcoes do CRUD e alocao dinamica deles
*/

#ifndef GATOS_H
#define GATOS_H
#include <stdio.h>
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

typedef struct Arquivos{
    FILE *f;
    char bancoGatos[100];
    char bancoDoacoes[100];
}Arquivos;


void menuGato(ListaCDE *lista);
Gato createGato(unsigned int novoID);
int insereOrdenado(ListaCDE *l, Gato dados);
void exibeGato(Gato);
void mostra(ListaCDE *l, int filtro);
Gato* procuraNome(ListaCDE *l, char nomeProcurado[]);
int procuraID(ListaCDE *l, unsigned int id);
int retira(ListaCDE *l, unsigned int id);
int atualiza(ListaCDE *l, unsigned int id, int filtro);
Gato atualizaAdocao(ListaCDE *l, unsigned int id);
unsigned int ultimoID(ListaCDE *l);


void cria(ListaCDE *l);
int insere(ListaCDE *l, Gato dados);
int estaVazia(ListaCDE l);
Gato getInicio(ListaCDE l);
Gato getFim(ListaCDE l);
int getTamanho(ListaCDE l);
int freeLista(ListaCDE *l);

//relacionadas ao arquivo
//int lerQtdGatos(Arquivos arq);
Gato abreArquivoGatosLer(Arquivos arq);
void abreArquivoGatosEscrever(Arquivos arq, Gato gato);
int getGatos(Arquivos arq, ListaCDE *l);
void escreverGatos(Arquivos arq, ListaCDE* l);

#endif