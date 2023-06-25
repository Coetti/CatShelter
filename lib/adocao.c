#include "adocao.h"
#include "gatos.h"
#include "catshelter.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
extern Arquivos arq;
Gato gatoAdotado;
Adotante tutor;

void menuAdocao(ListaCDE *l) {
    
    unsigned int opc;

    getGatos(arq, l);

    do {
        limpaTela();
        desenhaGato();
        printf("-----------------------------------\n");
        printf("\nSelecione uma opcao:\n");
        printf("1 - Gerar adocao\n");
        printf("2 - Gerar arquivo da ficha de adocao\n");
        printf("3 - Voltar\n");
        printf("Opcao: ");
        scanf("%u", &opc);

        switch (opc) {
            case 1:
                gatoAdotado = criarAdocao(l);
                getchar();
                tutor = fichaAdocao(gatoAdotado);
                imprimeFicha(gatoAdotado, tutor);
                pressioneParaVoltar();
                break;
            case 2:
                criaArquivo(arq, gatoAdotado, tutor);
                printf("\n\nArquivo de adocao gerado com sucesso no diretorio: 'C:\\CatShelter\\fichas\\FICHA-DE-ADOCAO-%s-E-%s.txt'", tutor.nome, gatoAdotado.nome);
                pressioneParaVoltar();
                break;
            case 3:
                menu(l);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opc != 3);
}


Gato criarAdocao(ListaCDE *l){
    unsigned int id;
    Gato gatoAtualizado;

    limpaTela();
    printf("\nDigite o >>>ID<<< do gato que sera adotado\n");
    printf("ID: ");
    scanf("%u", &id);

    if(procuraID(l, id) !=  1){
        printf("\nGato com ID: %u nao encontrado!!", id);
        pressioneParaVoltar();
        menuAdocao(l);
    }

    gatoAtualizado =  atualizaAdocao(l, id);

    return gatoAtualizado;
}

Adotante fichaAdocao(Gato gatoAdotado){
    Adotante tutor;
    limpaTela();
    printf("Adotando gato ID: %d, nome: %s", gatoAdotado.id, gatoAdotado.nome);
    printf("\n\nDigite o nome do novo tutor: ");
    fgets(tutor.nome, sizeof(tutor.nome), stdin);
    tutor.nome[strcspn(tutor.nome, "\n")] = '\0';
    for (int i = 0; tutor.nome[i] != '\0'; i++) {
        tutor.nome[i] = toupper(tutor.nome[i]);
    }

    printf("Digite o CPF: ");
    fgets(tutor.CPF, sizeof(tutor.CPF), stdin);
    tutor.CPF[strcspn(tutor.CPF, "\n")] = '\0';

    printf("Digite o RG: ");
    fgets(tutor.RG, sizeof(tutor.RG), stdin);
    tutor.RG[strcspn(tutor.RG, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(tutor.telefone, sizeof(tutor.telefone), stdin);

    printf("Digite a rua: ");
    fgets(tutor.rua, sizeof(tutor.rua), stdin);
    tutor.rua[strcspn(tutor.rua, "\n")] = '\0';
    for (int i = 0; tutor.rua[i] != '\0'; i++) {
        tutor.rua[i] = toupper(tutor.rua[i]);
    }

    printf("Digite o numero: ");
    fgets(tutor.numero, sizeof(tutor.numero), stdin);
    tutor.numero[strcspn(tutor.numero, "\n")] = '\0';

    printf("Digite o bairro: ");
    fgets(tutor.bairro, sizeof(tutor.bairro), stdin);
    tutor.bairro[strcspn(tutor.bairro, "\n")] = '\0';
    for (int i = 0; tutor.bairro[i] != '\0'; i++) {
        tutor.bairro[i] = toupper(tutor.bairro[i]);
    }

    printf("Digite a cidade: ");
    fgets(tutor.cidade, sizeof(tutor.cidade), stdin);
    tutor.cidade[strcspn(tutor.cidade, "\n")] = '\0';
    for (int i = 0; tutor.cidade[i] != '\0'; i++) {
        tutor.cidade[i] = toupper(tutor.cidade[i]);
    }

    printf("Digite o estado: ");
    fgets(tutor.estado, sizeof(tutor.estado), stdin);
    tutor.estado[strcspn(tutor.estado, "\n")] = '\0';
    for (int i = 0; tutor.estado[i] != '\0'; i++) {
        tutor.estado[i] = toupper(tutor.estado[i]);
    }

    return tutor;
}
void imprimeFicha(Gato gatoAdotado, Adotante tutor){
    limpaTela();
    desenhaGato();
    printf("\n--------------------------------------");
    printf("\nPARABENS PELA ADOCAO!!!");
    printf("\n>>>DADOS DO GATO<<<\n");
    exibeGato(gatoAdotado);
    printf("\n>>>DADOS DO TUTOR<<<\n");
    exibeTutor(tutor);
}

void exibeTutor(Adotante tutor){
    printf("\nNOME: %s", tutor.nome);
    printf("\nCPF: %s", tutor.CPF);
    printf("\nRG: %s", tutor.RG);
    printf("\nTELEFONE: %s", tutor.telefone);
    printf("\nENDERECO: %s NUMERO: %s - BAIRRO: %s - CIDADE: %s - %s\n", tutor.rua, tutor.numero, tutor.bairro, tutor.cidade, tutor.estado);
}


void criaArquivo(Arquivos arq, Gato gatoAdotado, Adotante tutor){
    
    char nomeArquivo[200]; 
    sprintf(nomeArquivo, "C:\\CatShelter\\fichas\\FICHA-DE-ADOCAO-%s-E-%s.txt", tutor.nome, gatoAdotado.nome);
    
    arq.f = fopen(nomeArquivo, "w+");
    if(arq.f == NULL){
        printf("Erro ao criar o arquivo!!\n");
    }
    fprintf(arq.f, "------------------------->>>FICHA DE ADOCAO>><<CATSHELTER<<<-------------------------\n\n");
    fprintf(arq.f, "NOME: %s\t", tutor.nome);
    fprintf(arq.f, "TELEFONE: %s", tutor.telefone);
    fprintf(arq.f, "CPF: %s\t", tutor.CPF);
    fprintf(arq.f, "RG: %s\n", tutor.RG);
    fprintf(arq.f, "ENDERECO: %s NUMERO: %s - BAIRRO: %s - CIDADE: %s - %s\n", tutor.rua, tutor.numero, tutor.bairro, tutor.cidade, tutor.estado);
    fprintf(arq.f, "\n\n");
    fprintf(arq.f, "ID: %u\t", gatoAdotado.id);
    fprintf(arq.f, "NOME: %s\n", gatoAdotado.nome);
    fprintf(arq.f, "IDADE: %u\t", gatoAdotado.idade);
    fprintf(arq.f, "RACA: %s\t", gatoAdotado.raca);
    fprintf(arq.f, "PELAGEM: %s\t\n", gatoAdotado.pelagem);

    for (int j = 0; j < gatoAdotado.numVacinas; j++) {
        fprintf(arq.f, "VACINA %d: %s\n", j+1, gatoAdotado.vacinas[j]);
    }

    fprintf(arq.f, "CASTRADO: %c\n", gatoAdotado.castrado);
    fprintf(arq.f, "COMORBIDADES: %s\n", gatoAdotado.comorbidades);
    fprintf(arq.f, "OBSERVACOES: %s\n", gatoAdotado.obs);
    fprintf(arq.f, "DATA DE ENTRADA: %s\t", gatoAdotado.dataDeEntrada);
    fprintf(arq.f, "DATA DE ADOCAO: %s\n", gatoAdotado.dataDeAdocao);
    fprintf(arq.f, "-------------------------CATSHELTER - TELEFONE: 19981355375-------------------------");
    fclose(arq.f);
}