#include "doacoes.h"
#include <stdio.h>
unsigned int idDoacoes = 0;
void menuDoacao(ListaCDE* l) {
    
    unsigned int opc;
    Doacao doacoes[100];
    doacoes->id = 0;

    do {
        limpaTela();
        desenhaGato();
        printf("-----------------------------------\n");
        printf("\nSelecione uma opcao:\n");
        printf("1 - Doacao\n");
        printf("2 - Entrada de estoque\n");
        printf("3 - Saida de estoque\n");
        printf("4 - Exibir estoque\n");
        printf("5 - Voltar\n");
        printf("Opcao: ");
        scanf("%u", &opc);

        switch (opc) {
            case 1:
                criarDoacao(doacoes);
                pressioneParaVoltar();
                break;
            case 2:
                limpaTela();
                desenhaGato();
                entradaEstoque(doacoes);
                pressioneParaVoltar();
                break;
            case 3:
                limpaTela();
                desenhaGato();
                saidaEstoque(doacoes);
                pressioneParaVoltar();
                break;
            case 4: 
                limpaTela();
                desenhaGato();
                exibirEstoque(doacoes);
                pressioneParaVoltar();
                break;
            case 5: 
                menu(l);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opc != 5);
}


void criarDoacao(Doacao *doacoes){
    limpaTela();
    desenhaGato();
    idDoacoes++;
    doacoes->id = idDoacoes;
    printf("\n------------NOVA DOACAO-------------");
    printf("\n\nDESCRICAO: ");
    scanf("%s", doacoes->descricao);
    printf("\nQUANTIDADE: ");
    scanf("%d", &doacoes->quantidade);
    printf("\nPESO: ");
    scanf("%f", &doacoes->peso);
    printf("\nDATA DE VALIDADE: ");
    scanf("%s", doacoes->dataDeValidade);
}

void entradaEstoque(Doacao *doacoes) {
    unsigned int idAtt;
    int encontrado = 0;
    int quantidade;

    printf("\n------------ENTRADA DE ESTOQUE-------------");
        printf("\nDIGITE O ID DO ITEM: ");
        scanf("%u", &idAtt);
        printf("\nDIGITE A QUANTIDADE A REMOVER: ");
        scanf("%d", &quantidade);

    for (int i = 0; i < 100; i++) {
        if (doacoes[i].id == idAtt) {
            doacoes[i].quantidade += quantidade;
            encontrado = 1;
            printf("\nEstoque atualizado com sucesso!\n");
        }
    }
    if (!encontrado) {
        printf("\nItem não encontrado no estoque.\n");
    }
}


void saidaEstoque(Doacao *doacoes){
    unsigned int idAtt;
    int encontrado = 0;
    int quantidade;

    printf("\n------------ENTRADA DE ESTOQUE-------------");
    printf("\nDIGITE O ID DO ITEM: ");
    scanf("%u", &idAtt);        
    printf("\nDIGITE A QUANTIDADE A REMOVER: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < 100; i++) {
        if (doacoes[i].id == idAtt) {
            doacoes[i].quantidade -= quantidade;
            encontrado = 1;
            printf("\nEstoque atualizado com sucesso!\n");
        }
    }
    if (!encontrado) {
        printf("\nItem não encontrado no estoque.\n");
    }
}

void exibirEstoque(Doacao *doacoes){
    printf("\n------------DOACAO-------------");
    printf("\nID: %u", doacoes->id);
    printf("\nDESCRICAO: %s", doacoes->descricao);
    printf("\nQUANTIDADE: %d", doacoes->quantidade);
    printf("\nPESO: %.2f", doacoes->peso);
    printf("\nDATA DE VALIDADE: %s", doacoes->dataDeValidade);
    printf("\n-------------------------------\n");
}