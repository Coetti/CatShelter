#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gatos.h"
#include "listacde.h"


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


int insereOrdenado(ListaCDE *l, Gato dados){

    // alocando no na memoria e checando se deu certo
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return 0;

    // guardando o dados e incrementando o tamanho da lista
    aux->dados = dados;
    l->tam++;

    /* 1o caso: primeiro elemento */
    if(l->inicio == NULL){

        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;

        return 1;
    }

    /* 2o caso: dados menor que o dados do inicio, insere no inicio */
    if(dados.id < l->inicio->dados.id){

        aux->ant = l->fim; //ant do novo inicio aponta para fim
        aux->prox = l->inicio; //prox do novo inicio aponta para antigo inicio
        l->inicio->ant = aux; // anterior do antigo inicio aponta para novo inicio
        l->inicio = aux; //l->inicio aponta para novo inicio
        l->fim->prox = l->inicio; //proximo do fim aponta para novo inicio

        return 1;
    }

    /* 3o caso: dados maior que o dados do fim, insere no fim */
    if(dados.id > l->fim->dados.id){

        aux->ant = l->fim; //ant do novo fim aponta para antigo fim
        aux->prox = l->inicio; //prox do novo fim aponta pra inicio
        l->fim->prox = aux; //prox do antigo fim aponta para novo fim
        l->fim = aux; //l->fim aponta para novo fim
        l->inicio->ant = l->fim; //ant do inicio aponta para novo fim

        return 1;
    }

    /* 4o caso: insercao ordenada no meio */

    // inicializa-se dois nos no comeco da lista, que serao responsaveis por percorre-la
    No *anterior = l->inicio;
    No *atual = anterior->prox;

    while(dados.id > atual->dados.id){

        // percorro a lista ate achar a posicao certa
        anterior = atual;
        atual = atual->prox;
    }
    // insiro o no entre anterior e atual
    aux->ant = anterior; // ant do novo no aponta para anterior
    aux->prox = atual; // prox do novo no aponta para atual
    anterior->prox = aux; // prox do anterior aponta para o novo no
    atual->ant = aux; // ant do atual aponta para o novo no

    return 1;
}

int retira(ListaCDE *l, Gato dados){

    No *aux;

    if(l->inicio == NULL){
        printf("Lista vazia\n");
        return 0;
    }

    /* 1o caso: lista unitaria */
    if((dados.id == l->inicio->dados.id) && (l->inicio == l->fim)) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = NULL; //inicio aponta pra null
        l->fim = NULL; // fim aponta pra null
        free(aux); // libero a memoria
        l->tam--;

        return 1;
    }

    /* 2o caso: removendo primeiro elemento */
    if(dados.id == l->inicio->dados.id) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = aux->prox; //inicio aponta para o novo inicio (o segundo elemento)
        l->inicio->ant = l->fim; // o anterior do novo inicio aponta para o fim
        l->fim->prox = l->inicio; // o proximo do fim aponta para o novo inicio
        free(aux); //libero memoria
        l->tam--;

        return 1;
    }

    /* 3o caso: removendo ultimo elemento */
    if(dados.id == l->fim->dados.id) {
        aux = l->fim; // aux aponta para o no que vou remover
        l->fim = aux->ant; //fim aponta para o novo fim (penultimo elemento)
        l->fim->prox = l->inicio; // o proximo do novo fim aponta para o inicio
        l->inicio->ant = l->fim; // o anterior do inicio aponta para o novo fim
        free(aux); //libero a memoria
        l->tam--;

        return 1;
    }

    /* 4o caso: removendo um elemento no meio */
    aux = l->inicio->prox; // aux aponta para o segundo elemento

    //percorro a lista ate achar o elemento, ou chegar no fim
    while((dados.id != aux->dados.id) && (aux != l->fim))
        aux = aux->prox;

    if(aux == l->fim){ // se cheguei ao fim, nao encontrei o elemento
        printf("O elemento %d nao esta na lista.\n", dados.id);
        return 0;
    }

    //se encontrei o elemento, removo ele
    aux->prox->ant = aux->ant; // o anterior do proximo a aux aponta para o elemento anterior a aux
    aux->ant->prox = aux->prox; // o proximo do anterior a aux aponta para o proximo elemento em relacao a aux
    free(aux); //libero a memoria
    l->tam--;

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

/*
    Exibe os elementos da lista, dependendo do sentido:
    1 - exibe do inicio ao fim
    2 - exibe do fim ao inicio
*/
void mostra(ListaCDE *l, int filtro) {
    No *aux;

    if (l->inicio == NULL) {
        printf("Lista vazia!\n");
    } else {
        if (filtro == 1) {
            printf("\nExibindo lista ordenada por ID\n\n");
            aux = l->inicio;
            do {
                printf("ID: %d\n",aux->dados.id);
                printf("Nome: %s\n", aux->dados.nome);
                printf("Disponivel para adocao?: %s\n", aux->dados.adocao);
                printf("Idade: %d\n", aux->dados.idade);
                printf("Raca: %s\n",aux->dados.raca);
                printf("Pelagem: %s\n", aux->dados.pelagem);
                for (int i = 0; i < 30; i++) {
                    printf("Vacina: %s\n", aux->dados.vacinas[i]);
                }
                printf("Castrado?: %c\n", aux->dados.castrado);
                printf("Comorbidades: %s\n", aux->dados.comorbidades);
                printf("Observacao: %s\n", aux->dados.obs);
                printf("No abrigo desde: %s\n", aux->dados.dataDeEntrada);
                printf("Adotado em: %s\n", aux->dados.dataDeAdocao);
                aux = aux->prox;
            } while (aux != l->inicio);
        }

        if (filtro == 2) {
            printf("\nFiltro disponivel para adocao aplicado! \n\n");
            aux = l->inicio;
            do {
                if (strcmp(aux->dados.adocao, "SIM") == 0) {
                    printf("ID: %d\n", aux->dados.id);
                    printf("Nome: %s\n", aux->dados.nome);
                    printf("Disponivel para adocao?: %s\n", aux->dados.adocao);
                    printf("Idade: %d\n", aux->dados.idade);
                    printf("Raca: %s\n", aux->dados.raca);
                    printf("Pelagem: %s\n", aux->dados.pelagem);
                    for (int i = 0; i < 30; i++) {
                        printf("Vacina: %s\n", aux->dados.vacinas[i]);
                    }
                    printf("Castrado?: %c\n", aux->dados.castrado);
                    printf("Comorbidades: %s\n", aux->dados.comorbidades);
                    printf("Observacao: %s\n", aux->dados.obs);
                    printf("No abrigo desde: %s\n", aux->dados.dataDeEntrada);
                    printf("Adotado em: %s\n", aux->dados.dataDeAdocao);
            }
                aux = aux->prox;
            } while (aux != l->inicio);
        }

    }
}

Gato* procura(ListaCDE *l, char *nomeProcurado) {
    No *aux;
    if (l->inicio == NULL) {
        printf("Sem gatos registrados!\n");
    } else {
        aux = l->inicio;    
        
        while (aux != l->fim) {
            if (strcmp(aux->dados.nome, nomeProcurado) == 0) {
                return &(aux->dados);
            }
            aux = aux->prox; 
        }
        printf("\n\nGato com nome %s nao encontrado", nomeProcurado);
        printf("\n\nPressione qualquer tecla para voltar");
        getchar();
    }
        printf("\n\nGato com nome %s nao encontrado",nomeProcurado);
        printf("\n\nPressione qualquer tecla para voltar");
        getchar();
        //pesquisaGato();
        return 0;
}   

/*agora inserir na gato.c o menu e a funcao para criar um novo gato para testar a implementacao da lista

ERRO LISTA VAZIA*/