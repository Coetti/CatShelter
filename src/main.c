/* gcc -Wall src/main.c lib/login.c lib/adminPanel.c lib/menu.c -Iinclude -o catshelter
IMPLEMENTACAO DO ARQUIVO MAIN.C DO PROJETO CATSHELTER
AUTOR: GABRIEL HENRIQUE COETTI
DATA: 19/06/23
LOCAL: PUCMINAS - POCOS DE CALDAS*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include "catshelter.h"
#include "gatos.h"

int main() {
    ListaCDE lista;
    cria(&lista); 
    menu(&lista);
    return 0;
}