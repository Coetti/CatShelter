/*IMPLEMENTACAO DAS FUNCOES DE LISTA CIRCULAR DUPLAMENTE ENCADEADA
AUTOR: GABRIEL HENRIQUE COETTI 
BASEADO NO CODIGO FORNECIDO PELO PROFESSOR RAFAEL D'ANGELO
DATA: 19/06/23
LOCAL: PUCMINAS - POCOS DE CALDAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gatos.h"

void cria(ListaCDE *l){

    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insere(ListaCDE *l, Gato dados){

    // alocando no na memoria e checando se deu certo
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return 0;

    // guardando o dados e incrementando o tamanho da lista
    aux->dados = dados;
    l->tam++;

    // 1o caso: primeiro elemento
    if(l->inicio == NULL){

        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;

        return 1;
    }

    // 2o caso: ja ha elementos, insere no fim

    aux->ant = l->fim; //ant do novo fim aponta para antigo fim
    aux->prox = l->inicio; //prox do novo fim aponta pra inicio
    l->fim->prox = aux; //prox do antigo fim aponta para novo fim
    l->fim = aux; //l->fim aponta para novo fim
    l->inicio->ant = l->fim; //ant do inicio aponta para novo fim

    return 1;
}


int estaVazia(ListaCDE l){

    if(l.inicio == NULL)
        return 1;

    return 0;
}

Gato getInicio(ListaCDE l){

    return l.inicio->dados;
}


Gato getFim(ListaCDE l){

    return l.fim->dados;
}

int getTamanho(ListaCDE l){

    return l.tam;
}

int freeLista(ListaCDE *l){
    No *aux = l->inicio;
    No *prox;


    if(estaVazia(*l) == 1){
        printf("Nao ha Nos para remover");
        return 1;
    }else{
        while(aux != NULL){
        prox = aux->prox;
        free(aux);
        l->tam--;
        aux = prox;
    }
        l->inicio = NULL;
        l->fim = NULL;
        return 0;
    }
}