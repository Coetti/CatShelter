/* IMPLEMENTACAO DO ARQUIVO HEADER DA BIBLIOTECA LOGIN
AUTOR: GABRIEL HENRIQUE COETTI
DATA: 08/06/23
LOCAL: PUCMINAS - POCOS DE CALDAS*/
#include "gatos.h"

#ifndef LOGIN_H
#define LOGIN_H



//definicoes e prototipos
void login(ListaCDE* lista);
int verificaLogin(char *, char *);
void adminPanel();
void menu(ListaCDE* lista);
void limpaTela();
void desenhaGato();
void pressioneParaVoltar();
#endif
