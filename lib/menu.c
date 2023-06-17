#include <stdio.h>

void menu(){
    unsigned int opc;

    printf("\n\nteste menu\n");
    scanf("%d", &opc);

    switch(opc){
        case 1:  menuGatos();
            break;
    }
}    