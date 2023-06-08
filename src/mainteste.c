#include <stdio.h>
#include <string.h>

typedef struct 
{
    int valor;
    char nome[20];
}Animal;



int main(){
    
    FILE *f;
    char filename[100];
    int i=0, tamanho=0;
    Animal gato[9];

    // Formata o nome do arquivo usando sprintf
    sprintf(filename, "arquivo_%d.txt", i);


    f = fopen(filename, "w+");
    
    if(f == NULL){
        printf("erro ao abrir\n");
        return 1;
    }

     for(i=0; i<9; i++){
        gato[i].valor = i;
        strcpy(gato[i].nome, "Gamora");
     }


    for(i=0; i<9; i++){
        fprintf(f, "%d - %s\n\n\n", gato[i].valor, gato[i].nome);
    }

    for(i=0; i<9; i++){
        fscanf(f, "%d - %s\n\n\n", &gato[i].valor,gato[i].nome);
        tamanho++;
        printf("tamanho %d\n", tamanho);
    }
    printf("\n\n");
    
    rewind(f);

    int vetor[tamanho];
    for(i=0; i<tamanho; i++){
    
        fscanf(f, "%d - %s\n\n\n", &gato[i].valor,gato[i].nome);
        printf("%d - %s\n\n\n", gato[i].valor, gato[i].nome);
        vetor[i] = gato[i].valor;
    }
    printf("\n\n");
    fclose(f);

    for(i=0; i<tamanho; i++){

        printf("\tvetor %d", vetor[i]);
    }
     printf("\nteste");
}   
    