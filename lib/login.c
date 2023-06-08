#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login(){
    char username[60];
    char password[60];
    int max_tentativas = 0;
    int role;

    printf("USER: ");
    gets(username);

    printf("\n\nPASSWORD: ");
    gets(password);

    while((role = verificaLogin(username,password)) == 0 && max_tentativas < 5){
        //printf("\033[2J");
        //printf("\033[1;1H");  

        printf("Login invalido\nDigite Novamente");

        printf("USER: ");
        gets(username);

        printf("\n\nPASSWORD: ");
        gets(password);

        max_tentativas++;
    }
    if(role == 2)
        adminPanel();
    if(role == 1)
        menu();

}



/* Verifica se o login do usuario/senha estao corretos */

int verificaLogin(char *username, char *password){
    char filename[30] = "src/database/users.txt";
    FILE *f;
    char user[120]; 
    char linha[120];
    char admin[20] = "adminadmin"; 

    printf("USER %s, PASSWORD %s",username, password);
    strcpy(user, username);
    strcat(user, password);
    printf("username concat %s", user);


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

