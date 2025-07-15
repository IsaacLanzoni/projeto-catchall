#include <stdio.h>
#include <stdlib.h>

//Funcao que cria arquivo JSON para exportacao
void exportJson(unsigned char *trainerName, int seen[], int caught[]){
    FILE *fp = fopen("save_data.json", "w");
    if(fp == NULL){
        perror("Erro ao criar arquivo JSON");
        return;
    }

    fprintf(fp, "{");
    fprintf(fp, " \"trainer_name\": \"%s\", \n", trainerName);


    //Exportando pokemons vistos
    fprintf(fp, "\"seen\": [");
    for(int i = 0; i < 151; i++){
        if(i != 0) fprintf(fp, ", ");
        fprintf(fp, "%d", seen[i]);
    }
    fprintf(fp, "], \n");

    //Exportando pokemons capturados
    fprintf(fp, "\"caught\": [");
    for(int i = 0; i < 151; i++){
        if(i != 0) fprintf(fp, ", ");
        fprintf(fp, "%d", caught[i]);
    }
    fprintf(fp, "] \n");

    fprintf(fp, "}\n");
    fclose(fp);

    printf("JSON Salvo com sucesso no arquivo \"save_data.json\" ");
}