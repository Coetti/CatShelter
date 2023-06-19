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
int retira(ListaCDE *l, int id);
int atualiza(ListaCDE *l, int id, int filtro);
int estaVazia(ListaCDE l);
Gato getInicio(ListaCDE l);
Gato getFim(ListaCDE l);
int getTamanho(ListaCDE l);
void mostra(ListaCDE *, int filtro);
Gato* procuraNome(ListaCDE *l, char nomeProcurado[]);
int procuraID(ListaCDE *l, int id);

#endif /* LISTACDE_H */
