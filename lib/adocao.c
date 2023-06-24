#include "adocao.h"
#include "gatos.h"
#include "catshelter.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
extern Arquivos arq;

void menuAdocao(ListaCDE *l){
    unsigned int opc;
    Adotante *tutor;
    Gato *gatoAdotado;


    limpaTela();
    printf("-----------------------------------\n");
    desenhaGato();
    printf("\nSelecione uma opcao:\n");
    printf("1 - Gerar adocao\n");
    printf("2 - Imprimir ficha de adocao");
    printf("3 - Voltar\n");
    printf("Opcao: ");
    scanf("%u", &opc);

    do{ 
       switch(opc){
         case 1: 
             criarAdocao(l, gatoAdotado, tutor);
             break;
         case 2:
             imprimeFicha(gatoAdotado, tutor);
             break;    
         case 3:
             menu();
             break; 
         default:
             printf("Opcao invalida. Tente novamente.\n");
             
             break;    
         }
     }while (opc != 2);   
}

void criarAdocao(ListaCDE *l, Gato *gatoAdotado, Adotante *tutor){
    unsigned int id;
    Gato gatoAtualizado;
    limpaTela();

    printf("\nDigite o >>>ID<<< do gato que sera adotado");
    scanf("%u", &id);

    if(procuraID(l, id) !=  1){
        printf("\nGato com ID: %u nao encontrado!!", id);
        pressioneParaVoltar();
        menuAdocao(l);
    }

    gatoAtualizado =  atualizaAdocao(l, id);

    *gatoAdotado = gatoAtualizado;
    fichaAdocao(tutor);
}
void fichaAdocao(Adotante *tutor){
    
    printf("Digite o nome do novo tutor: ");
    fgets(tutor->nome, sizeof(tutor->nome), stdin);
    tutor->nome[strcspn(tutor->nome, "\n")] = '\0';
    for (int i = 0; tutor->nome[i] != '\0'; i++) {
        tutor->nome[i] = toupper(tutor->nome[i]);
    }

    printf("Digite o CPF: ");
    fgets(tutor->CPF, sizeof(tutor->CPF), stdin);
    tutor->CPF[strcspn(tutor->CPF, "\n")] = '\0';

    printf("Digite o RG: ");
    fgets(tutor->RG, sizeof(tutor->RG), stdin);
    tutor->RG[strcspn(tutor->RG, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(tutor->telefone, sizeof(tutor->telefone), stdin);
    tutor->telefone[strcspn(tutor->telefone, "\n")] = '\0';

    printf("Digite a rua: ");
    fgets(tutor->rua, sizeof(tutor->rua), stdin);
    tutor->rua[strcspn(tutor->rua, "\n")] = '\0';
    for (int i = 0; tutor->rua[i] != '\0'; i++) {
        tutor->rua[i] = toupper(tutor->rua[i]);
    }

    printf("Digite o numero: ");
    fgets(tutor->numero, sizeof(tutor->numero), stdin);
    tutor->numero[strcspn(tutor->numero, "\n")] = '\0';

    printf("Digite o bairro: ");
    fgets(tutor->bairro, sizeof(tutor->bairro), stdin);
    tutor->bairro[strcspn(tutor->bairro, "\n")] = '\0';
    for (int i = 0; tutor->bairro[i] != '\0'; i++) {
        tutor->bairro[i] = toupper(tutor->bairro[i]);
    }

    printf("Digite a cidade: ");
    fgets(tutor->cidade, sizeof(tutor->cidade), stdin);
    tutor->cidade[strcspn(tutor->cidade, "\n")] = '\0';
    for (int i = 0; tutor->cidade[i] != '\0'; i++) {
        tutor->cidade[i] = toupper(tutor->cidade[i]);
    }

    printf("Digite o estado: ");
    fgets(tutor->estado, sizeof(tutor->estado), stdin);
    tutor->estado[strcspn(tutor->estado, "\n")] = '\0';
    for (int i = 0; tutor->estado[i] != '\0'; i++) {
        tutor->estado[i] = toupper(tutor->estado[i]);
    }

}
int imprimeFicha(Gato *gatoAdotado, Adotante *tutor){
    limpaTela();
    desenhaGato();
    printf("\n--------------------------------------");
    printf("\nPARABENS PELA ADOCAO!!!");
    printf("\n\n>>>DADOS DO GATO<<<");
    exibeGato(*gatoAdotado);
    printf("\n\n>>>DADOS DO TUTOR<<<");
    exibeTutor(tutor);
    criaArquivo(arq, gatoAdotado, tutor);
}

void exibeTutor(Adotante *tutor){
    printf("\nNOME: %s", tutor->nome);
    printf("\nCPF: %s", tutor->CPF);
    printf("\nRG: %s", tutor->RG);
    printf("\nTELEFONE: %s", tutor->telefone);
    printf("\nENDERECO: %s NUMERO: %s - BAIRRO: %s - CIDADE: %s - %s", tutor->rua, tutor->numero, tutor->bairro, tutor->cidade, tutor->estado);
}


void criaArquivo(Arquivos arq, Gato *gatoAdotado, Adotante *tutor){
    
    char nomeArquivo[200]; 
    sprintf(nomeArquivo, "C:\\CatShelter\\fichas\\FICHA-DE-ADOCAO-%s-E-%s.txt", tutor->nome, gatoAdotado->nome);
    
    arq.f = fopen(nomeArquivo, "w");
    if(arq.f == NULL){
        printf("Erro ao criar o arquivo!!\n");
    }
    fprintf(arq.f, ">>>FICHA DE ADOCAO>><<CATSHELTER<<<\n");
    fprintf(arq.f, "NOME: %s\n", tutor->nome);
    fprintf(arq.f, "TELEFONE: %s\t\n", tutor->telefone);
    fprintf(arq.f, "CPF: %s\t", tutor->CPF);
    fprintf(arq.f, "RG: %s\n", tutor->RG);
    fprintf(arq.f, "ENDERECO: %s NUMERO: %s - BAIRRO: %s - CIDADE: %s - %s\n\n", tutor->rua, tutor->numero, tutor->bairro, tutor->cidade, tutor->estado);

    fprintf(arq.f, "ID: %u\t", gatoAdotado->id);
    fprintf(arq.f, "NOME: %s\t", gatoAdotado->nome);
    fprintf(arq.f, "IDADE%u\t\n", gatoAdotado->idade);
    fprintf(arq.f, "RACA: %s\t", gatoAdotado->raca);
    fprintf(arq.f, "PELAGEM: %s\t", gatoAdotado->pelagem);

    for (int j = 0; j < gatoAdotado->numVacinas; j++) {
        fprintf(arq.f, "VACINA %d: %s\n", j, gatoAdotado->vacinas[j]);
    }

    fprintf(arq.f, "%c\n", gatoAdotado->castrado);
    fprintf(arq.f, "%s\n", gatoAdotado->comorbidades);
    fprintf(arq.f, "%s\n", gatoAdotado->obs);
    fprintf(arq.f, "%s\n", gatoAdotado->dataDeEntrada);
    fprintf(arq.f, "%s\n", gatoAdotado->dataDeAdocao);

}