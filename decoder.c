#include <stdio.h>
#include "save_data.c"
#include "functions.c"

int main(){
    int i = 0; //Variavel de Controle
    int seenedOrCatched = 0; //Variavel que recebe o valor da funcao bitReader & returnSeenedOrOwnedPokemons
    int badge = 0; //Variavel que recebe o valor da funcao badges
    int dollar = 0; //Variavel que recebe o valor da funcao pokeDollar
    int seen[151]; //Vetor que armazena a quantidade de pokemons vistos
    int caught[151]; //Vetor que armazena a quantidade de pokemons capturados
    unsigned char byteId[2]; //Vetor que armazena a quantidade de bits que sao utilizados no endereco de id's
    unsigned char seenOrCatched[19]; //Vetor que usado para armazenar a quantidade de bits de pokemons vistos/capturados
    unsigned char badgeByte[1]; //Vetor que armazena a quantidade de insignias possuidas
    unsigned char clock[4]; //Vetor que armazena o tempo de jogo do usuario
    unsigned char money[3]; //Vetor que armazena a quantidade de dinheiro do usuario
    unsigned char partyNumber; //Variavel que armazena a quantidade de pokemons na party
    unsigned char partySpecies[6]; //Vetor que armazena os Ids de cada pokemon respectivo da party
    unsigned char trainerName[11]; //Vetor que armazena o nome do treinador 
    unsigned char rivalName[11]; //Vetor que armazena o nome do rival
    unsigned char partyOneNickname[11]; //Vetor que armazena o apelido do primeiro pokemon da party
    unsigned char partyTwoNickname[11]; //Vetor que armazena o apelido do segundo pokemon da party
    unsigned char partyThreeNickname[11]; //Vetor que armazena o apelido do terceiro pokemon da party
    unsigned char partyFourNickname[11]; //Vetor que armazena o apelido do quarto pokemon da party
    unsigned char partyFiveNickname[11]; //Vetor que armazena o apelido do quinto pokemon da party
    unsigned char partySixNickname[11]; //Vetor que armazena o apelido do sexto pokemon da party
    

    FILE *save;
    save = fopen("../save2.sav","rb");

    //Caminho de Arquivos para testes
    //../save1.sav
    //../save2.sav

    if(!save){
        printf("Erro ao tentar abrir o arquivo.");
        return 1;
    }

    printf("\n");

    while (i < 11){
        i++;
        //Lê o nome do Trainer
        if(i == 1){
            printf("Nome do Treinador:");
            fseek(save, 0x2598, SEEK_SET);
            fread(trainerName, 1, 11, save);
            decoder(trainerName);
        }
        //Lê o ID do Trainer
        if(i == 2){
            fseek(save, 0x2605, SEEK_SET);
            fread(byteId, 1, 2, save);
            Id(byteId);
        }
        //Lê a quantidade de insignias do Trainer
        if(i == 3){
            fseek(save, 0x2602, SEEK_SET);
            fread(badgeByte, 1, 1, save);
            badge = badges(badgeByte);
            printf("Insignias: %d\n", badge);

        }
        //Lê a quantidade de Dinheiro do Trainer
        if(i == 4){
            fseek(save, 0x25F3, SEEK_SET);
            fread(money, 1, 3, save);
            dollar = pokeDollar(money);
            printf("Dinheiro: %d\n", dollar);
        }
        //Mostra quantos Pokemons foram vistos
        if(i == 5){
            fseek(save, 0x25B6, SEEK_SET);
            fread(seenOrCatched, 1, 19, save);
            seenedOrCatched = bitReader(seenOrCatched);
            printf("Pokemons Vistos: %d\n", seenedOrCatched);
        }
        //Mostra quantos Pokemons foram capturados
        if(i == 6){
            fseek(save, 0x25A3, SEEK_SET);
            fread(seenOrCatched, 1, 19, save);
            seenedOrCatched = bitReader(seenOrCatched);
            printf("Pokemons Capturados: %d\n", seenedOrCatched);
        }
        //Mostra o Tempo de Jogo
        if(i == 7){
            fseek(save, 0x2CED, SEEK_SET);
            fread(clock, 1, 4, save);
            time(clock);
        }
        //Mostra o Nome do Rival
        if(i == 8){
            printf("Nome do Rival: ");
            fseek(save, 0x25F6, SEEK_SET);
            fread(rivalName, 1, 11, save);
            decoder(rivalName);
        }
        //Mostra a quantidade e especies de Pokemons na Party
        if(i == 9){
            fseek(save, 0x2F2C, SEEK_SET);
            fread(&partyNumber, 1, 1, save);
            fread(partySpecies, 1, 6, save);
            printf("Numero de Pokemons na Party: %d\n", partyNumber);
            party(partySpecies, partyNumber, pokemonNames);
        }
        //Mostra os Apelidos de cada Pokemon da Party
        if(i == 10){
            printf("Nicknames:");
            for(int j = 0; j < partyNumber; j++) {
                fseek(save, (0x3073 + 11) + (j * 11), SEEK_SET);
                if(j == 0){
                    fread(partyOneNickname, 1, 11, save);
                    printf("\n");
                    decoder(partyOneNickname);
                }
                if(j == 1){
                    fread(partyTwoNickname, 1, 11, save);
                    printf("\n");
                    decoder(partyTwoNickname);
                }
                if(j == 2){
                    fread(partyThreeNickname, 1, 11, save);
                    printf("\n");
                    decoder(partyThreeNickname);
                }
                if(j == 3){
                    fread(partyFourNickname, 1, 11, save);
                    printf("\n");
                    decoder(partyFourNickname);
                }
                if(j == 4){
                    fread(partyFiveNickname, 1, 11, save);
                    printf("\n");
                    decoder(partyFiveNickname);
                }
                if(j == 5){
                    fread(partySixNickname, 1, 11, save);
                    printf("\n");
                    decoder(partySixNickname);
                }
            }
        }

        //Mostra a lista de pokemons vistos e capturados-
        if(i == 11){
            printf("Pokemons Vistos:\n");



            //Estrutura de repeticao que analisa quais pokemon foram vistos
            for(int h = 0; h < 151; h++){
                int analizer;
                //Aponta o ponteiro do sistema para o offset 0x25B6
                fseek(save, 0x25B6, SEEK_SET);
                fread(seenOrCatched, 1, 19, save);
                analizer = returnSeenedOrOwnedPokemons(seenOrCatched, h);

                unsigned char gameId = pokedexToGameID[h];
                const char* name = pokemonNames[gameId];

                //Verifica se há um pokemon com esse nome
                if (name != NULL) {
                    printf("%03d: %s: ", h + 1, name);

                } else {
                    printf("%03d: [ID %02X sem nome]\n", h + 1, gameId);
                }

                //Verifica se o pokemon foi visto, ou nao
                if(analizer == 1){
                    printf("Visto: Sim                  ");

                    seen[h] = h + 1;

                } else {
                    printf("Visto: Nao                  ");
                    
                    seen[h] = 0;

                }

                //Aponta o ponteiro do sistema para o offset 0x25A3
                fseek(save, 0x25A3, SEEK_SET);
                fread(seenOrCatched, 1, 19, save);
                analizer = returnSeenedOrOwnedPokemons(seenOrCatched, h);

                //Verifica se o pokemon foi capturado ou nao
                if(analizer == 1){
                    printf("Capturado: Sim\n");

                    caught[h] = h + 1;

                } else {
                    printf("Capturado: Nao\n");

                    caught[h] = 0;
                }


            }
                //funcao que cria o arquivo JSON para exportacao
                exportJson(trainerName, seen, caught);

        }

        
    }
    //Fecha o Save
    fclose(save);

    return 0;
}