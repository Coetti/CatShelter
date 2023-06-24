/*Implementacao da biblioteca gatos.c que contem as funcoes relacionadas ao objeto gato e seu CRUD
AUTOR: GABRIEL HENRIQUE COETTI
DATA: 19/06/23
LOCAL: PUCMINAS - POCOS DE CALDAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gatos.h"
#include "catshelter.h"
#include "adocao.h"

void menuGato(ListaCDE* lista) {
    int opcao = 0;
    int filtro = 0;
    unsigned int id;
    unsigned int novoID;
    char nomeProcurado[50];
    Gato novoGato;
    Gato *gatoProcurado;
    extern Arquivos arq;  // Declare a variável externa para acessá-la
    
    if(getGatos(arq, lista)!= 1){
        printf("erro ao ler arquivo");
        exit(0);
    }
    
    do {
        printf("-----------------------------------\n");
        desenhaGato();
        printf("\nSelecione uma opcao:\n");
        printf("1. Cadastrar um novo gato\n");
        printf("2. Mostrar animais cadastrados\n");
        printf("3. Procurar um gato pelo nome\n");
        printf("4. Atualizar os dados de um gato\n");
        printf("5. Excluir um gato\n");
        printf("6. Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpaTela();
        switch (opcao) {
            case 1:
                novoID = ultimoID(lista);
                novoGato = createGato(novoID);
                insereOrdenado(lista, novoGato);
                abreArquivoGatosEscrever(arq, lista);
                break;
            case 2:
                if(estaVazia(*lista)){
                printf("\n-------------------------------------------------\n");
                printf("\nNao ha registros para serem exibidos\n");
                pressioneParaVoltar();
            }
            else{
                printf("\n-------------------------------------------------\n");
                printf("1 = Ordenada por ID  / / / 2 = Animais disponiveis para adocao \n");
                scanf("%d", &filtro);
                mostra(lista, filtro);
                pressioneParaVoltar();
            }
            break;
            case 3:
                printf("Digite o nome do gato: ");
                scanf("%s", nomeProcurado);
                for (int i = 0; nomeProcurado[i] != '\0'; i++) {
                    nomeProcurado[i] = toupper(nomeProcurado[i]);
                }
                if((gatoProcurado = procuraNome(lista, nomeProcurado)) != NULL){
                    printf("Gato com nome %s\n", nomeProcurado);
                    exibeGato(*gatoProcurado);
                }else{
                    printf("Gato com nome %s nao encontrado!!!", nomeProcurado);
                }
                pressioneParaVoltar();
                break;
            case 4: 
                printf("\nDigite o ID do gato que deseja atualizar: ");
                scanf("%u", &id);
                if(procuraID(lista, id) == 1){
                    printf("1 - Nome /// 2 - Raca /// 3 - Adocao /// 4 - Idade /// ");
                    printf("5 - Pelagem /// 6 - Vacinas /// 7 - Castrado /// ");
                    printf("8 - Comorbidades /// 9 - Observação /// 10 - Data de Entrada /// 11 - Data de Adocao\n");
                    printf("Escolha o campo que deseja atualizar\n");
                    scanf("%d", &filtro);
                    if(atualiza(lista, id, filtro)){
                        printf("Dados atualizados com sucesso!");
                        abreArquivoGatosEscrever(arq, lista);
                    }
                }
                else{
                    printf("ID nao encontrado!!!");
                }
                pressioneParaVoltar();
                break;
            case 5:
                printf("\nDigite o ID do gato que deseja remover: ");
                scanf("%u", &id);
                if(retira(lista, id) == 1){
                    printf("Gato com id: %u excluido com sucesso", id);
                    abreArquivoGatosEscrever(arq, lista);
                }else{
                    printf("Gato com id %u nao encontrado!!!",id);
                }
                pressioneParaVoltar();
                break;
            case 6:
                menu();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                pressioneParaVoltar();
                break;
        }
    } while (opcao != 6);
}


Gato createGato(unsigned int novoID){
    Gato novoGato;
    
    novoGato.id = novoID + 1;

    limpaTela();
    printf("-----------------------------------------\n");
    printf("REGISTRANDO GATO DE ID >>>%u<<<\n", novoGato.id);
    printf("Preencha os dados do novo gato\n\n");
    getchar();

    printf("Nome: ");
    fgets(novoGato.nome, sizeof(novoGato.nome), stdin);
    novoGato.nome[strcspn(novoGato.nome, "\n")] = '\0';
    for (int i = 0; novoGato.nome[i] != '\0'; i++) {
        novoGato.nome[i] = toupper(novoGato.nome[i]);
    }

    printf("Disponivel para adocao (S/N): ");
    scanf(" %c", &novoGato.adocao);
    getchar();
    novoGato.adocao = toupper(novoGato.adocao);

    printf("Idade: ");
    scanf("%u", &novoGato.idade);
    getchar();

    printf("Raca: ");
    fgets(novoGato.raca, sizeof(novoGato.raca), stdin);
    novoGato.raca[strcspn(novoGato.raca, "\n")] = '\0';

    for (int i = 0; novoGato.raca[i] != '\0'; i++) {
        novoGato.raca[i] = toupper(novoGato.raca[i]);
    }

    printf("Pelagem: ");
    fgets(novoGato.pelagem, sizeof(novoGato.pelagem), stdin);
    novoGato.pelagem[strcspn(novoGato.pelagem, "\n")] = '\0'; // Remover o caractere de nova linha

    for (int i = 0; novoGato.pelagem[i] != '\0'; i++) {
        novoGato.pelagem[i] = toupper(novoGato.pelagem[i]);
    }
    fflush(stdin);
    printf("Digite o numero de vacinas: ");
    scanf("%d", &novoGato.numVacinas);
    getchar();

    for(int i = 0; i < novoGato.numVacinas; i++){
        printf("Digite a vacina %d: ", i+1);
        fgets(novoGato.vacinas[i], sizeof(novoGato.vacinas), stdin);
    }

    printf("Castrado (S/N): ");
    scanf(" %c", &novoGato.castrado);
    getchar();

    novoGato.castrado = toupper(novoGato.castrado);

    printf("Comorbidades: ");
    fgets(novoGato.comorbidades, sizeof(novoGato.comorbidades), stdin);
    novoGato.comorbidades[strcspn(novoGato.comorbidades, "\n")] = '\0';

    for (int i = 0; novoGato.comorbidades[i] != '\0'; i++) {
        novoGato.comorbidades[i] = toupper(novoGato.comorbidades[i]);
    }

    printf("Observacao: ");
    fgets(novoGato.obs, sizeof(novoGato.obs), stdin);
    novoGato.obs[strcspn(novoGato.obs, "\n")] = '\0';

    for (int i = 0; novoGato.obs[i] != '\0'; i++) {
        novoGato.obs[i] = toupper(novoGato.obs[i]);
    }

    printf("No abrigo desde: ");
    scanf(" %s", novoGato.dataDeEntrada);
    getchar();

    printf("Adotado em: ");
    scanf(" %s", novoGato.dataDeAdocao);

    return novoGato;
}


void exibeGato(Gato gatoMostrado){
    printf("ID: %u\n", gatoMostrado.id);
    printf("Nome: %s\n", gatoMostrado.nome);
    printf("Disponivel para adocao?: %c\n", gatoMostrado.adocao);
    printf("Idade: %u\n", gatoMostrado.idade);
    printf("Raca: %s\n", gatoMostrado.raca);
    printf("Pelagem: %s\n", gatoMostrado.pelagem);
    for (int i = 0; i < gatoMostrado.numVacinas; i++) {
        printf("Vacina %d: %s\n", i+1,gatoMostrado.vacinas[i]);
    }
    printf("Castrado?: %c\n", gatoMostrado.castrado);
    printf("Comorbidades: %s\n", gatoMostrado.comorbidades);
    printf("Observacao: %s\n", gatoMostrado.obs);
    printf("No abrigo desde: %s\n", gatoMostrado.dataDeEntrada);
    printf("Adotado em: %s\n", gatoMostrado.dataDeAdocao);
    printf("\n\n");  
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

int retira(ListaCDE *l, unsigned int id){

    No *aux;

    if(l->inicio == NULL){
        printf("\nLista vazia\n");
        return 0;
    }

    /* 1o caso: lista unitaria */
    if((id == l->inicio->dados.id) && (l->inicio == l->fim)) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = NULL; //inicio aponta pra null
        l->fim = NULL; // fim aponta pra null
        free(aux); // libero a memoria
        l->tam--;

        return 1;
    }

    /* 2o caso: removendo primeiro elemento */
    if(id == l->inicio->dados.id) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = aux->prox; //inicio aponta para o novo inicio (o segundo elemento)
        l->inicio->ant = l->fim; // o anterior do novo inicio aponta para o fim
        l->fim->prox = l->inicio; // o proximo do fim aponta para o novo inicio
        free(aux); //libero memoria
        l->tam--;

        return 1;
    }

    /* 3o caso: removendo ultimo elemento */
    if(id == l->fim->dados.id) {
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
    while((id != aux->dados.id) && (aux != l->fim))
        aux = aux->prox;

    if(aux == l->fim){ // se cheguei ao fim, nao encontrei o elemento
        printf("\nO elemento %d nao esta na lista.\n", id);
        return 0;
    }

    //se encontrei o elemento, removo ele
    aux->prox->ant = aux->ant; // o anterior do proximo a aux aponta para o elemento anterior a aux
    aux->ant->prox = aux->prox; // o proximo do anterior a aux aponta para o proximo elemento em relacao a aux
    free(aux); //libero a memoria
    l->tam--;

    return 1;
}

void mostra(ListaCDE *l, int filtro){
    No *aux;
    Gato gatoMostrado;
    if (l->inicio == NULL) {
        printf("\nLista vazia!\n");
    } else {
        if (filtro == 1) {
            printf("\nExibindo os gatos ordenados por ID\n\n");
            aux = l->inicio;
            do {
                gatoMostrado = aux->dados;
                exibeGato(gatoMostrado);
                aux = aux->prox;
            } while (aux != l->inicio);
        }

        if (filtro == 2) {
            printf("\nFiltro disponivel para adocao aplicado! \n\n");
            aux = l->inicio;
            do {
                if (aux->dados.adocao == 'S') {
                    gatoMostrado = aux->dados;
                    exibeGato(gatoMostrado);  
                }
                aux = aux->prox;
            } while (aux != l->inicio);
        }

    }
}

Gato* procuraNome(ListaCDE *l, char nomeProcurado[]) {
    No *aux;
    if (l->inicio == NULL) {
        printf("\nSem gatos registrados!\n");
    } 
    aux = l->inicio;
    do{
        if(strcmp(aux->dados.nome, nomeProcurado) == 0) {
            return &(aux->dados);
        }
        aux = aux->prox; 
    }while(aux != l->inicio);
    return NULL;     
}   

int procuraID(ListaCDE *l, unsigned int id){
    No *aux;
    if (l->inicio == NULL) {
        printf("\nSem gatos registrados!\n");
        return 0;
    }
    aux = l->inicio;    
    
    do{
        if (id == aux->dados.id) {
            return 1;
        }
        aux = aux->prox; 
    }while(aux != l->inicio);

    return 0;
}

int atualiza(ListaCDE *l, unsigned int id, int filtro){
    No *aux;
    
    if (l->inicio == NULL) {
        printf("\nSem gatos registrados!\n");
    }

    aux = l->inicio;

    do{
        if(id == aux->dados.id){
            limpaTela();
            switch (filtro) {
                case 1:
                    printf("Digite o novo nome: ");
                    fgets(aux->dados.nome, sizeof(aux->dados.nome), stdin);
                    aux->dados.nome[strcspn(aux->dados.nome, "\n")] = '\0';
                    for (int i = 0; aux->dados.nome[i] != '\0'; i++) {
                        aux->dados.nome[i] = toupper(aux->dados.nome[i]);
                    }
                    break;
                case 2:
                    printf("Digite a nova raca: ");
                    fgets(aux->dados.raca, sizeof(aux->dados.raca), stdin);
                    aux->dados.raca[strcspn(aux->dados.raca, "\n")] = '\0';
                    for (int i = 0; aux->dados.raca[i] != '\0'; i++) {
                        aux->dados.raca[i] = toupper(aux->dados.raca[i]);
                    }
                    break;
                case 3:
                    printf("Digite a nova informação de adocao (s/n): ");
                    scanf(" %c", &aux->dados.adocao);
                    getchar(); 
                    aux->dados.adocao = toupper(aux->dados.adocao);
                    break;
                case 4:
                    printf("Digite a nova idade: ");
                    scanf("%u", &aux->dados.idade);
                    break;
                case 5:
                    printf("Digite a nova pelagem: ");
                    fgets(aux->dados.pelagem, sizeof(aux->dados.pelagem), stdin);
                    aux->dados.pelagem[strcspn(aux->dados.pelagem, "\n")] = '\0'; // Remover o caractere de nova linha
                    for (int i = 0; aux->dados.pelagem[i] != '\0'; i++) {
                        aux->dados.pelagem[i] = toupper(aux->dados.pelagem[i]);
                    }
                    break;
                case 6:
                    printf("Digite o novo numero de vacinas: ");
                    scanf("%d", &aux->dados.numVacinas);
                    for (int i = 0; i < aux->dados.numVacinas; i++) {
                        printf("Digite a vacina %d: ", i + 1);
                        fgets(aux->dados.vacinas[i], sizeof(aux->dados.vacinas[i]), stdin);
                    }
                    break;
                case 7:
                    printf("Digite a nova informacao de castrado (s/n): ");
                    scanf(" %c", &aux->dados.castrado);
                    getchar();
                    aux->dados.castrado = toupper(aux->dados.castrado);
                    break;
                case 8:
                    printf("Digite as novas comorbidades: ");
                    fgets(aux->dados.comorbidades, sizeof(aux->dados.comorbidades), stdin);
                    aux->dados.comorbidades[strcspn(aux->dados.comorbidades, "\n")] = '\0';
                    for (int i = 0; aux->dados.comorbidades[i] != '\0'; i++) {
                        aux->dados.comorbidades[i] = toupper(aux->dados.comorbidades[i]);
                    } 
                    break;
                case 9:
                    printf("Digite as novas observacoes: ");
                    fgets(aux->dados.obs, sizeof(aux->dados.obs), stdin);
                    aux->dados.obs[strcspn(aux->dados.obs, "\n")] = '\0';
                    for (int i = 0; aux->dados.obs[i] != '\0'; i++) {
                        aux->dados.obs[i] = toupper(aux->dados.obs[i]);
                    } 
                    break;
                case 10:
                    printf("Digite a nova data de entrada: ");
                    fgets(aux->dados.dataDeEntrada, sizeof(aux->dados.dataDeEntrada), stdin);
                    break;
                case 11:
                    printf("Digite a nova data de adocao: ");
                    fgets(aux->dados.dataDeAdocao, sizeof(aux->dados.dataDeAdocao), stdin);
                    break;
                default:
                    printf("Opcao invalida.\n");
                    pressioneParaVoltar();
            }

            return 1;
        }
        aux = aux->prox;
    }while(aux != l->inicio);
    
    return 0;
}

Gato atualizaAdocao(ListaCDE *l, unsigned int id){
    No* aux;
    Gato gatoAdotado;

    if(estaVazia(*l) == 1){
        printf("Lista vazia");
        pressioneParaVoltar();
        menuAdocao(l);
    }

    aux = l->inicio;

    do{
        if(aux->dados.id == id){

            aux->dados.adocao = 'N';
            gatoAdotado = aux->dados;
        }
        aux = aux->prox;
    }while(aux != l->inicio);

    return gatoAdotado;
}

unsigned int ultimoID(ListaCDE *l){
    unsigned int ultimoID;
    if(estaVazia(*l) == 1){
        ultimoID = 1;
        return ultimoID; 
    }
    ultimoID = l->fim->dados.id;
    return ultimoID; 
}

/*--------------------------------------------FUNCOES RELACIONADAS AOS ARQUIVOS------------------------------------------------------*/

Arquivos arq = {NULL,"C:\\CatShelter\\database\\gatosDB.txt","C:\\CatShelter\\database\\doacoesDB.txt"};

void abreArquivoGatosEscrever(Arquivos arq, ListaCDE* l){
    No *aux;
    aux = l->inicio;

    arq.f = fopen(arq.bancoGatos, "w+");
    if (arq.f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    do{
        fprintf(arq.f, "%u\n", aux->dados.id);
        fprintf(arq.f, "%s\n", aux->dados.nome);
        fprintf(arq.f, "%c\n", aux->dados.adocao);
        fprintf(arq.f, "%u\n", aux->dados.idade);
        fprintf(arq.f, "%s\n", aux->dados.raca);
        fprintf(arq.f, "%s\n", aux->dados.pelagem);
        fprintf(arq.f, "%d\n", aux->dados.numVacinas);

        for (int j = 0; j < aux->dados.numVacinas; j++) {
            fprintf(arq.f, "%s\n", aux->dados.vacinas[j]);
        }

        fprintf(arq.f, "%c\n", aux->dados.castrado);
        fprintf(arq.f, "%s\n", aux->dados.comorbidades);
        fprintf(arq.f, "%s\n", aux->dados.obs);
        fprintf(arq.f, "%s\n", aux->dados.dataDeEntrada);
        fprintf(arq.f, "%s\n", aux->dados.dataDeAdocao);
        aux = aux->prox;
    }while(aux != l->inicio);

    fclose(arq.f);
}

int getGatos(Arquivos arq, ListaCDE *l) {
    arq.f = fopen(arq.bancoGatos, "r");
    if (arq.f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    Gato gato;
    int resultado;

    while ((resultado = abreArquivoGatosLer(arq, &gato)) == 1) {
        insereOrdenado(l, gato); 
    }

    if (resultado == 0) {
        printf("Erro na leitura do arquivo.\n");
    }

    fclose(arq.f);
    return 1;
}


int abreArquivoGatosLer(Arquivos arq, Gato *gato) {
    int result;

    result = fscanf(arq.f, "%u", &(gato->id));
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->nome);
    if (result != 1)
        return 0;

    result = fscanf(arq.f, " %c", &(gato->adocao));
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%u", &(gato->idade));
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->raca);
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->pelagem);
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%d", &(gato->numVacinas));
    if (result != 1)
        return 0;

    for (int i = 0; i < gato->numVacinas; i++) {
        result = fscanf(arq.f, "%s", gato->vacinas[i]);
        if (result != 1)
            return 0;
    }

    result = fscanf(arq.f, " %c", &(gato->castrado));
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->comorbidades);
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->obs);
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->dataDeEntrada);
    if (result != 1)
        return 0;

    result = fscanf(arq.f, "%s", gato->dataDeAdocao);
    if (result != 1)
        return 0;

    return 1;
}


/*
int abreArquivoGatosLer(Arquivos arq, Gato *gato){
    int result;
    fscanf(arq.f, "%u", &gato.id);
    fscanf(arq.f, "%s", gato.nome);
    fscanf(arq.f, " %c", &gato.adocao);
    fscanf(arq.f, "%u", &gato.idade);
    fscanf(arq.f, "%s", gato.raca);
    fscanf(arq.f, "%s", gato.pelagem);
    fscanf(arq.f, "%d", &gato.numVacinas);

    for (int i = 0; i < gato.numVacinas; i++) {
        fscanf(arq.f, "%s", gato.vacinas[i]);
    }

    fscanf(arq.f, " %c", &gato.castrado);
    fscanf(arq.f, "%s", gato.comorbidades);
    fscanf(arq.f, "%s", gato.obs);
    fscanf(arq.f, "%s", gato.dataDeEntrada);
    fscanf(arq.f, "%s", gato.dataDeAdocao);

    return gato;
}*/