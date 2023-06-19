/* gcc -Wall src/main.c lib/login.c lib/adminPanel.c lib/menu.c -Iinclude -o catshelter */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gatos.h"
#include "listacde.h"

void menu(ListaCDE *lista);
Gato criarGato();

int main() {
    ListaCDE lista;
    cria(&lista); 
    menu(&lista);
    return 0;
}

void menu(ListaCDE* lista) {
    int opcao = 0;
    int filtro = 0;
    unsigned int id;
    char nomeProcurado[50];
    Gato novoGato;
    Gato *gatoProcurado;
    do {
        printf("\nSelecione uma opcao:\n");
        printf("1. Cadastrar um novo gato\n");
        printf("2. Mostrar animais cadastrados\n");
        printf("3. Procurar um gato pelo nome\n");
        printf("4. Atualizar os dados de um gato\n");
        printf("5. Excluir um gato\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                novoGato = criarGato();
                insereOrdenado(lista, novoGato);
                break;
            case 2:
                if(!estaVazia(*lista)){
                printf("\n-------------------------------------------------\n");
                printf("1 = Ordenada por ID  / / / 2 = Animais disponiveis para adocao \n");
                scanf("%d", &filtro);
                mostra(lista, filtro);
            }
            else{
                printf("Nao ha registros para serem exibidos");
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
                }else{
                    printf("Gato com nome %s nao encontrado!!!", nomeProcurado);
                }
                break;
            case 4: 
                printf("\nDigite o ID do gato que deseja atualizar: ");
                scanf("%d", &id);
                if(!procuraID(lista, id)){
                    printf("1 - Nome /// 2 - Raça /// 3 - Adoção /// 4 - Idade");
                    printf("5 - Pelagem /// 6 - Vacinas /// 7 - Castrado ");
                    printf("8 - Comorbidades /// 9 - Observação /// 10 - Data de Entrada /// 11 - Data de Adoção\n");
                    printf("Escolha o campo que deseja atualizar\n");
                    scanf("%d", &filtro);
                    if(!atualiza(lista, id, filtro)){
                        printf("Dados atualizados com sucesso!");
                    }
                }else{
                    printf("ID nao encontrado!!!");
                }
                break;
            case 5:
                printf("\nDigite o ID do gato que deseja remover: ");
                scanf("%d", &id);
                if(!retira(lista, id)){
                    printf("Gato com id: %d excluido com sucesso", id);
                }else{
                    printf("Gato com id %d nao encontrado!!!",id);
                }
                break;
            case 6:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);
}

Gato criarGato() {
    Gato novoGato;
    printf("Digite os dados do gato:\n");
    printf("ID: ");
    scanf("%d", &novoGato.id);
    printf("Nome: ");
    scanf("%s", novoGato.nome);
    for (int i = 0; novoGato.nome[i] != '\0'; i++) {
        novoGato.nome[i] = toupper(novoGato.nome[i]);
    }
    printf("Disponivel para adocao (S/N): ");
    scanf(" %c", &novoGato.adocao);
    getchar();
    novoGato.adocao = toupper(novoGato.adocao);
    printf("Idade: ");
    scanf("%d", &novoGato.idade);
    printf("Raca: ");
    scanf("%s", novoGato.raca);
    getchar();
    for (int i = 0; novoGato.raca[i] != '\0'; i++) {
        novoGato.raca[i] = toupper(novoGato.raca[i]);
    }
    printf("Pelagem: ");
    scanf("%s", novoGato.pelagem);
    getchar();
    for (int i = 0; novoGato.pelagem[i] != '\0'; i++) {
        novoGato.pelagem[i] = toupper(novoGato.pelagem[i]);
    }
    printf("Digite o numero de vacinas: ");
    scanf("%d", &novoGato.numVacinas);
    for(int i = 0; i<novoGato.numVacinas; i++){
        printf("Digite a vacina %d: ", i+1);
        scanf("%s", novoGato.vacinas[i]);
    }
    printf("Castrado (S/N): ");
    scanf(" %c", &novoGato.castrado);
    getchar();
    novoGato.castrado = toupper(novoGato.castrado);
    printf("Comorbidades: ");
    scanf("%s", novoGato.comorbidades);
    for (int i = 0; novoGato.comorbidades[i] != '\0'; i++) {
        novoGato.comorbidades[i] = toupper(novoGato.comorbidades[i]);
    }
    printf("Observacao: ");
    scanf("%s", novoGato.obs);
    for (int i = 0; novoGato.obs[i] != '\0'; i++) {
        novoGato.obs[i] = toupper(novoGato.obs[i]);
    }
    printf("No abrigo desde: ");
    scanf("%s", novoGato.dataDeEntrada);
    printf("Adotado em: ");
    scanf("%s", novoGato.dataDeAdocao);
    return novoGato;
}
