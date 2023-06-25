    /* IMPLEMENTACAO DO ARQUIVO HEADER DA BIBLIOTECA MENU
    AUTOR: GABRIEL HENRIQUE COETTI
    DATA: 19/06/23
    LOCAL: PUCMINAS - POCOS DE CALDAS*/
    #include <stdio.h>
    #include <stdlib.h>
    #include "catshelter.h"
    #include "gatos.h"
    #include "adocao.h"
    #include "doacoes.h"

    void limpaTela(){
        printf("\033[2J");
        printf("\033[H");
    }

    void desenhaGato(){
        printf(" /\\_/\\\n");
        printf("( o.o )\n");
        printf(" > ^ <    __\n");
        printf("/     \\  /  \\ \n");
        printf("\\     /_/  \n");
    }

    void pressioneParaVoltar(){
        getchar();
        printf("\nAperte qualquer tecla para voltar!!\n");
        getchar();
    }

    void menu(ListaCDE* lista){
        unsigned int opc;

        limpaTela();
        printf("-----------------------------------\n");
        desenhaGato();
        printf("\nSelecione uma opcao:\n");
        printf("1 - Gatos\n");
        printf("2 - Doacoes\n");
        printf("3 - Adocoes\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%u", &opc);

        do{ 
            switch(opc){
                case 1: 
                    menuGato(lista);
                    break;
                case 2:
                    menuDoacao(lista);
                    break;
                case 3:
                    menuAdocao(lista);
                    break;
                case 4:
                    limpaTela();
                    printf("----------------------\n");
                    desenhaGato(); 
                    printf("\nEncerrando o programa.\n");
                    freeLista(lista);
                    exit(0);
                            
                default:
                printf("Opcao invalida. Tente novamente.\n");
                    break;    
            }
        }while (opc != 4);        
    }

