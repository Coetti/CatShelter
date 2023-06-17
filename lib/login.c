#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void login(){
    char username[60];
    char password[60];
    int max_tentativas = 0;
    unsigned int role=100;

   do{  
        printf("\033[2J");
        printf("\033[1;1H");

        if(role==0)  
            printf("Login invalido!!!\n\nDigite Novamente\n\n");
        
        printf("USER: ");
        scanf("%s", username);

        printf("\n\nPASSWORD: ");
        scanf("%s",  password);

        max_tentativas++;
        
   }while((role = verificaLogin(username,password)) == 0 && max_tentativas < 5);

    if(role == 2)
        adminPanel();
    if(role == 1)
        menu();
    
    printf("\n\nTentativas maximas atingidas...Saindo!!!");
    exit(0);
}



/* Verifica se o login do usuario/senha estao corretos */

int verificaLogin(char *username, char *password){
    char filename[30] = "src/database/users.txt";
    FILE *f;
    char user[120]; 
    char linha[120];
    char admin[20] = "adminadmin"; 

    strcpy(user, username);
    strcat(user, password);

    f = fopen(filename, "r+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    if(strcmp(user, admin) == 0){
        fclose(f);
        return 2;
    }
    else{    
        while(fgets(linha, sizeof(linha), f) != NULL){
            if(strstr(linha, user) != NULL)
            return 1;   
        }
    }
    fclose(f); 
    return 0;
}

