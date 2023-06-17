/* gcc -Wall src/main.c lib/login.c lib/adminPanel.c lib/menu.c -Iinclude -o catshelter */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "gatos.h"
#include "listacde.h"

void menu(ListaCDE* lista);
Gato criarGato();

int main() {
    ListaCDE lista;
    cria(&lista); 
    menu(&lista);
    return 0;
}

void menu(ListaCDE* lista) {
    int opcao = 0;
    Gato novoGato; // Declare novoGato outside the switch statement
    do {
        printf("\nSelecione uma opcao:\n");
        printf("1. Criar novo gato\n");
        printf("2. Inserir gato na lista\n");
        printf("3. Mostrar lista\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Criar novo gato
                novoGato = criarGato(); // Assign the created gato to novoGato
                insere(lista, novoGato);
                printf("Novo gato criado e inserido na lista.\n");
                main();
                break;
            case 2:
                novoGato = criarGato();
                insereOrdenado(lista, novoGato);
                main();
                break;
            case 3:
                mostra(lista, 1);
            /*
                printf("\nDados do gato:\n");
                printf("ID: %d\n", novoGato.id);
                printf("Nome: %s\n", novoGato.nome);
                printf("Disponível para adoção: %s\n", novoGato.adocao);
                printf("Idade: %d\n", novoGato.idade);
                printf("Raça: %s\n", novoGato.raca);
                printf("Pelagem: %s\n", novoGato.pelagem);
                printf("Castrado: %c\n", novoGato.castrado);
                printf("Comorbidades: %s\n", novoGato.comorbidades);
                printf("Observação: %s\n", novoGato.obs);
                printf("No abrigo desde: %s\n", novoGato.dataDeEntrada);
                printf("Adotado em: %s\n", novoGato.dataDeAdocao);*/
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);
}

Gato criarGato() {
    Gato novoGato;
    printf("Digite os dados do gato:\n");
    printf("ID: ");
    scanf("%d", &novoGato.id);
    printf("Nome: ");
    scanf("%s", novoGato.nome);
    printf("Disponivel para adocao (S/N): ");
    scanf("%s", novoGato.adocao);
    printf("Idade: ");
    scanf("%d", &novoGato.idade);
    printf("Raca: ");
    scanf("%s", novoGato.raca);
    printf("Pelagem: ");
    scanf("%s", novoGato.pelagem);
    printf("Castrado (S/N): ");
    scanf("%c", &novoGato.castrado);
    printf("Comorbidades: ");
    scanf("%s", novoGato.comorbidades);
    printf("Observacao: ");
    scanf("%s", novoGato.obs);
    printf("No abrigo desde: ");
    scanf("%s", novoGato.dataDeEntrada);
    printf("Adotado em: ");
    scanf("%s", novoGato.dataDeAdocao);
    return novoGato;
}
