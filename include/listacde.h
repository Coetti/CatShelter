#ifndef LISTACDE_H
#define LISTACDE_H

#include "gatos.h"

typedef struct no {
    Gato dados;
    struct no *ant;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} ListaCDE;

void cria(ListaCDE *l);
int insere(ListaCDE *l, Gato dados);
int insereOrdenado(ListaCDE *l, Gato dados);
int retira(ListaCDE *l, Gato dados);
int estaVazia(ListaCDE l);
Gato getInicio(ListaCDE l);
Gato getFim(ListaCDE l);
int getTamanho(ListaCDE l);
void mostra(ListaCDE *l, int filtro);
Gato* procura(ListaCDE *l, char *nomeProcurado);

#endif /* LISTACDE_H */
