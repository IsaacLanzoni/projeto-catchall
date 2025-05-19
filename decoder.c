//Developed by Isaac Lanzoni;
//Github Link:https://github.com/IsaacLanzoni;

#include <stdio.h>
#include <stdlib.h>

//Vetor que armazena os nomes de cada pokemon em seu respectivo endereco de memoria
const char *pokemonNames[256] = {
    [0x01] = "Rhydon",        [0x02] = "Kangaskhan",   [0x03] = "Nidoran♂",    [0x04] = "Clefairy",
    [0x05] = "Spearow",       [0x06] = "Voltorb",       [0x07] = "Nidoking",    [0x08] = "Slowbro",
    [0x09] = "Ivysaur",       [0x0A] = "Exeggutor",     [0x0B] = "Lickitung",   [0x0C] = "Exeggcute",
    [0x0D] = "Grimer",        [0x0E] = "Gengar",        [0x0F] = "Nidoran♀",    [0x10] = "Nidoqueen",
    [0x11] = "Cubone",        [0x12] = "Rhyhorn",       [0x13] = "Lapras",      [0x14] = "Arcanine",
    [0x15] = "Mew",           [0x16] = "Gyarados",      [0x17] = "Shellder",    [0x18] = "Tentacool",
    [0x19] = "Gastly",        [0x1A] = "Scyther",       [0x1B] = "Staryu",      [0x1C] = "Blastoise",
    [0x1D] = "Pinsir",        [0x1E] = "Tangela",       [0x1F] = "Missingno.",  [0x20] = "Missingno.",
    [0x21] = "Growlithe",     [0x22] = "Onix",          [0x23] = "Fearow",      [0x24] = "Pidgey",
    [0x25] = "Slowpoke",      [0x26] = "Kadabra",       [0x27] = "Graveler",    [0x28] = "Chansey",
    [0x29] = "Machoke",       [0x2A] = "Mr. Mime",      [0x2B] = "Hitmonlee",   [0x2C] = "Hitmonchan",
    [0x2D] = "Arbok",         [0x2E] = "Parasect",      [0x2F] = "Psyduck",     [0x30] = "Drowzee",
    [0x31] = "Golem",         [0x32] = "Missingno.",    [0x33] = "Magmar",      [0x34] = "Missingno.",
    [0x35] = "Electabuzz",    [0x36] = "Magneton",      [0x37] = "Koffing",     [0x38] = "Missingno.",
    [0x39] = "Mankey",        [0x3A] = "Seel",          [0x3B] = "Diglett",     [0x3C] = "Tauros",
    [0x3D] = "Missingno.",    [0x3E] = "Missingno.",    [0x3F] = "Missingno.",  [0x40] = "Farfetch'd",
    [0x41] = "Venonat",       [0x42] = "Dragonite",     [0x43] = "Missingno.",  [0x44] = "Missingno.",
    [0x45] = "Missingno.",    [0x46] = "Doduo",         [0x47] = "Poliwag",     [0x48] = "Jynx",
    [0x49] = "Moltres",       [0x4A] = "Articuno",      [0x4B] = "Zapdos",      [0x4C] = "Ditto",
    [0x4D] = "Meowth",        [0x4E] = "Krabby",        [0x4F] = "Missingno.",  [0x50] = "Missingno.",
    [0x51] = "Missingno.",    [0x52] = "Vulpix",        [0x53] = "Ninetales",   [0x54] = "Pikachu",
    [0x55] = "Raichu",        [0x56] = "Missingno.",    [0x57] = "Missingno.",  [0x58] = "Dratini",
    [0x59] = "Dragonair",     [0x5A] = "Kabuto",        [0x5B] = "Kabutops",    [0x5C] = "Horsea",
    [0x5D] = "Seadra",        [0x5E] = "Missingno.",    [0x5F] = "Missingno.",  [0x60] = "Sandshrew",
    [0x61] = "Sandslash",     [0x62] = "Omanyte",       [0x63] = "Omastar",     [0x64] = "Jigglypuff",
    [0x65] = "Wigglytuff",    [0x66] = "Eevee",         [0x67] = "Flareon",     [0x68] = "Jolteon",
    [0x69] = "Vaporeon",      [0x6A] = "Machop",        [0x6B] = "Zubat",       [0x6C] = "Ekans",
    [0x6D] = "Paras",         [0x6E] = "Poliwhirl",     [0x6F] = "Poliwrath",   [0x70] = "Weedle",
    [0x71] = "Kakuna",        [0x72] = "Beedrill",      [0x73] = "Missingno.",  [0x74] = "Dodrio",
    [0x75] = "Primeape",      [0x76] = "Dugtrio",       [0x77] = "Venomoth",    [0x78] = "Dewgong",
    [0x79] = "Missingno.",    [0x7A] = "Missingno.",    [0x7B] = "Caterpie",    [0x7C] = "Metapod",
    [0x7D] = "Butterfree",    [0x7E] = "Machamp",       [0x7F] = "Missingno.",  [0x80] = "Golduck",
    [0x81] = "Hypno",         [0x82] = "Golbat",        [0x83] = "Mewtwo",      [0x84] = "Snorlax",
    [0x85] = "Magikarp",      [0x86] = "Missingno.",    [0x87] = "Missingno.",  [0x88] = "Muk",
    [0x89] = "Missingno.",    [0x8A] = "Kingler",       [0x8B] = "Cloyster",    [0x8C] = "Missingno.",
    [0x8D] = "Electrode",     [0x8E] = "Clefable",      [0x8F] = "Weezing",     [0x90] = "Persian",
    [0x91] = "Marowak",       [0x92] = "Missingno.",    [0x93] = "Haunter",     [0x94] = "Abra",
    [0x95] = "Alakazam",      [0x96] = "Pidgeotto",     [0x97] = "Pidgeot",     [0x98] = "Starmie",
    [0x99] = "Bulbasaur",     [0x9A] = "Venusaur",      [0x9B] = "Tentacruel",  [0x9C] = "Missingno.",
    [0x9D] = "Goldeen",       [0x9E] = "Seaking",       [0x9F] = "Missingno.",  [0xA0] = "Missingno.",
    [0xA1] = "Missingno.",    [0xA2] = "Missingno.",    [0xA3] = "Ponyta",      [0xA4] = "Rapidash",
    [0xA5] = "Rattata",       [0xA6] = "Raticate",      [0xA7] = "Nidorino",    [0xA8] = "Nidorina",
    [0xA9] = "Geodude",       [0xAA] = "Porygon",       [0xAB] = "Aerodactyl",  [0xAC] = "Missingno.",
    [0xAD] = "Magnemite",     [0xAE] = "Missingno.",    [0xAF] = "Missingno.",  [0xB0] = "Charmander",
    [0xB1] = "Squirtle",      [0xB2] = "Charmeleon",    [0xB3] = "Wartortle",   [0xB4] = "Charizard",
    [0xB5] = "Missingno.",    [0xB6] = "Missingno.",    [0xB7] = "Missingno.",  [0xB8] = "Missingno.",
    [0xB9] = "Oddish",        [0xBA] = "Gloom",         [0xBB] = "Vileplume",   [0xBC] = "Bellsprout",
    [0xBD] = "Weepinbell",    [0xBE] = "Victreebel"
};

//Funcao que decodifica caracteres
void decoder(unsigned char byte[11]);
//Funcao que lê bits e retorna a quantidade de pokemons vistos/capturados
int bitReader(unsigned char seen[19]);
//Funcao que mostra o Trainer Id
void Id(unsigned char Id[2]);
//Funcao que retorna a quantidade de Insiginías
int badges(unsigned char badgeByte[1]);
//Funcao que mostra o Tempo de Jogo
void time(unsigned char clock[4]);
//Funcao que retorna a quantidade de dinheiro do usuário
int pokeDollar(unsigned char money[3]);
//Funcao que mostra os pokemons que o Trainer está carregando
void party(unsigned char partySpecies[6], unsigned char partyNumber, const char *pokemonNames[256]);




int main(){
    int i = 0; //Variavel de Controle
    int seened = 0; //Variavel que recebe o valor da funcao bitReader
    int badge = 0; //Variavel que recebe o valor da funcao badges
    int dollar = 0; //Variavel que recebe o valor da funcao pokeDollar
    unsigned char byte[11]; //Vetor que armazena a quantidade de bytes a serem utilizados
    unsigned char byteId[2]; //Vetor que armazena a quantidade de bits que sao utilizados no endereco de id's
    unsigned char seen[19]; //Vetor que armazena a quantidade de bits de pokemons vistos
    unsigned char badgeByte[1]; //Vetor que armazena a quantidade de insignias possuidas
    unsigned char clock[4];//Vetor que armazena o tempo de jogo do usuario
    unsigned char money[3];//Vetor que armazena a quantidade de dinheiro do usuario
    unsigned char partyNumber;//Variavel que armazena a quantidade de pokemons na party
    unsigned char partySpecies[6];//Vetor que armazena os Ids de cada pokemon respectivo da party

    FILE *save;
    save = fopen("../save1.sav","rb");

    //Caminho de Arquivos para testes
    //../save1.sav
    //../save2.sav

    if(!save){
        printf("Erro ao tentar abrir o arquivo.");
        return 1;
    }

    printf("\n");

    while (i < 10){
        i++;
        //Lê o nome do Trainer
        if(i == 1){
            printf("Nome do Treinador:");
            fseek(save, 0x2598, SEEK_SET);
            fread(byte, 1, 11, save);
            decoder(byte);
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
            fread(seen, 1, 19, save);
            seened = bitReader(seen);
            printf("Pokemons Vistos: %d\n", seened);
        }
        //Mostra quantos Pokemons foram capturados
        if(i == 6){
            fseek(save, 0x25A3, SEEK_SET);
            fread(seen, 1, 19, save);
            seened = bitReader(seen);
            printf("Pokemons Vistos: %d\n", seened);
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
            fread(byte, 1, 11, save);
            decoder(byte);
        }
        //Mostra a quantidade de Pokemons na Party
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
                fread(byte, 1, 11, save);
                printf("\n");
                decoder(byte);
            }
        }
    }
    //Fecha o Save
    fclose(save);

    return 0;
}

void decoder(unsigned char byte[11]){
    //Vetor quer mapeia os caracteres
    unsigned char map[256];
    //Variavel de Controle
    int i;

    //Estrutura de Repeticao que inicializa todos os indices com '?'
    for(i = 0; i < 256; i++){
        map[i] = '?';
    }

    //Mapeamento manual
    map[0x50] = '\0';
    //Mapeamento Manual
    map[0x4A] = ' ';

    //Estrutura de Repeticao que Mapeia as Letras Maiusculas dentro do vetor
    for(i = 0; i < 26; i++){
        map[0x80 + i] = 'A' + i;
    }
    //Estrutura de Repeticao que Mapeia as Letras Minusculas dentro do vetor
    for(i = 0; i < 26; i++){
        map[0xA0 + i] = 'a' + i;
    }
    //Estrutura de Repeticao que Mapeia os Números dentro do vetor
    for(i = 0; i <= 9; i++){
        map[0xF6 + i] = '0' + i;
    }

    //Mapeamento Manual
    map[0xAB] = '!';
    map[0xAC] = '?';
    map[0xAD] = '.';
    map[0xAE] = '-';
    map[0xB8] = ',';
        
    //Estrutura de Dados que exibe o nome do Trainer decodificando os bytes com base no vetor Map
    for(i = 0; i < 11; i++){
        if(byte[i] == 0x50) break; 
        printf("%c", map[byte[i]]);
    }

    printf("\n");

}

int bitReader(unsigned char seen[19]){
    int see = 0;
    for(int i = 0; i < 151; i++){
        int byteIndex = i / 8;
        int bitIndex = i % 8;
        int bit = (seen[byteIndex] >> bitIndex) & 1;

        if(bit == 1){
            see++;
        }
    }

    return see;
}


void Id(unsigned char Id[2]){
        unsigned short trainer_id = Id[0] + (Id[1] << 8);
        printf("Trainer ID:%05d\n", trainer_id);
}

int badges(unsigned char badgeByte[1]){
    int badgeCount = 0;

    for(int i = 0; i < 8; i++){
        int byteIndex = i / 8;
        int bitIndex = i % 8;
        int bit = (badgeByte[byteIndex] >> bitIndex) & 1;

        if(bit == 1){
            badgeCount++;
        }
    }

    return badgeCount;
}

void time(unsigned char clock[4]){
    printf("Tempo de Jogo:");
    printf(" %02d Horas e %02d Minutos\n", clock[0], clock[2]);
}

int pokeDollar(unsigned char money[3]){
    int value = 0;
    for(int i = 0; i < 3; i++){
        int highBit = (money[i] >> 4) & 0xF;
        int lowBit = money[i] & 0xF;
        value = value * 100 + highBit * 10 + lowBit;
    }

    return value;
}

void party(unsigned char partySpecies[6], unsigned char partyNumber, const char *pokemonNames[256]){
   
    for(int i = 0; i < partyNumber; i++){
         unsigned char id = partySpecies[i];
         if(id >= 1){
           printf("PokemonN%d: %s\n", i + 1, pokemonNames[id]);
         }
         else{
            printf("Pokemon N%d: VAZIO\n", i + 1);
         }
    }

}