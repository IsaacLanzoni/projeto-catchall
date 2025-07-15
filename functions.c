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

unsigned char pokedexToGameID[151] = {
    0x99, // 001 - Bulbasaur
    0x09, // 002 - Ivysaur
    0x9A, // 003 - Venusaur
    0xB0, // 004 - Charmander
    0xB2, // 005 - Charmeleon
    0xB4, // 006 - Charizard
    0xB1, // 007 - Squirtle
    0xB3, // 008 - Wartortle
    0x1C, // 009 - Blastoise
    0x7B, // 010 - Caterpie
    0x7C, // 011 - Metapod
    0x7D, // 012 - Butterfree
    0x70, // 013 - Weedle
    0x71, // 014 - Kakuna
    0x72, // 015 - Beedrill
    0x24, // 016 - Pidgey
    0x96, // 017 - Pidgeotto
    0x97, // 018 - Pidgeot
    0xA5, // 019 - Rattata
    0xA6, // 020 - Raticate
    0x05, // 021 - Spearow
    0x23, // 022 - Fearow
    0x6C, // 023 - Ekans
    0x2D, // 024 - Arbok
    0x54, // 025 - Pikachu
    0x55, // 026 - Raichu
    0x60, // 027 - Sandshrew
    0x61, // 028 - Sandslash
    0x0F, // 029 - Nidoran♀
    0xA8, // 030 - Nidorina
    0x10, // 031 - Nidoqueen
    0x03, // 032 - Nidoran♂
    0xA7, // 033 - Nidorino
    0x07, // 034 - Nidoking
    0x04, // 035 - Clefairy
    0x8E, // 036 - Clefable
    0x52, // 037 - Vulpix
    0x53, // 038 - Ninetales
    0x64, // 039 - Jigglypuff
    0x65, // 040 - Wigglytuff
    0x6B, // 041 - Zubat
    0x82, // 042 - Golbat
    0xB9, // 043 - Oddish
    0xBA, // 044 - Gloom
    0xBB, // 045 - Vileplume
    0x6D, // 046 - Paras
    0x2E, // 047 - Parasect
    0x41, // 048 - Venonat
    0x77, // 049 - Venomoth
    0x3B, // 050 - Diglett
    0x76, // 051 - Dugtrio
    0x4D, // 052 - Meowth
    0x90, // 053 - Persian
    0x2F, // 054 - Psyduck
    0x80, // 055 - Golduck
    0x39, // 056 - Mankey
    0x75, // 057 - Primeape
    0x21, // 058 - Growlithe
    0x14, // 059 - Arcanine
    0x47, // 060 - Poliwag
    0x6E, // 061 - Poliwhirl
    0x6F, // 062 - Poliwrath
    0x94, // 063 - Abra
    0x26, // 064 - Kadabra
    0x95, // 065 - Alakazam
    0x6A, // 066 - Machop
    0x29, // 067 - Machoke
    0x7E, // 068 - Machamp
    0xBC, // 069 - Bellsprout
    0xBD, // 070 - Weepinbell
    0xBE, // 071 - Victreebel
    0x18, // 072 - Tentacool
    0x9B, // 073 - Tentacruel
    0xA9, // 074 - Geodude
    0x27, // 075 - Graveler
    0x31, // 076 - Golem
    0xA3, // 077 - Ponyta
    0xA4, // 078 - Rapidash
    0x25, // 079 - Slowpoke
    0x08, // 080 - Slowbro
    0x36, // 081 - Magnemite
    0xAD, // 082 - Magneton
    0x40, // 083 - Farfetch'd
    0x46, // 084 - Doduo
    0x74, // 085 - Dodrio
    0x3A, // 086 - Seel
    0x78, // 087 - Dewgong
    0x0D, // 088 - Grimer
    0x88, // 089 - Muk
    0x17, // 090 - Shellder
    0x8B, // 091 - Cloyster
    0x19, // 092 - Gastly
    0x93, // 093 - Haunter
    0x0E, // 094 - Gengar
    0x22, // 095 - Onix
    0x30, // 096 - Drowzee
    0x81, // 097 - Hypno
    0x4E, // 098 - Krabby
    0x8A, // 099 - Kingler
    0x06, // 100 - Voltorb
    0x8D, // 101 - Electrode
    0x0C, // 102 - Exeggcute
    0x0A, // 103 - Exeggutor
    0x11, // 104 - Cubone
    0x91, // 105 - Marowak
    0x2B, // 106 - Hitmonlee
    0x2C, // 107 - Hitmonchan
    0x0B, // 108 - Lickitung
    0x37, // 109 - Koffing
    0x8F, // 110 - Weezing
    0x12, // 111 - Rhyhorn
    0x01, // 112 - Rhydon
    0x28, // 113 - Chansey
    0x1E, // 114 - Tangela
    0x02, // 115 - Kangaskhan
    0x5C, // 116 - Horsea
    0x5D, // 117 - Seadra
    0x9D, // 118 - Goldeen
    0x9E, // 119 - Seaking
    0x1B, // 120 - Staryu
    0x98, // 121 - Starmie
    0x2A, // 122 - Mr. Mime
    0x1A, // 123 - Scyther
    0x48, // 124 - Jynx
    0x35, // 125 - Electabuzz
    0x33, // 126 - Magmar
    0x1D, // 127 - Pinsir
    0x3C, // 128 - Tauros
    0x85, // 129 - Magikarp
    0x16, // 130 - Gyarados
    0x13, // 131 - Lapras
    0x4C, // 132 - Ditto
    0x66, // 133 - Eevee
    0x69, // 134 - Vaporeon
    0x68, // 135 - Jolteon
    0x67, // 136 - Flareon
    0xAA, // 137 - Porygon
    0x62, // 138 - Omanyte
    0x63, // 139 - Omastar
    0x5A, // 140 - Kabuto
    0x5B, // 141 - Kabutops
    0xAB, // 142 - Aerodactyl
    0x84, // 143 - Snorlax
    0x4A, // 144 - Articuno
    0x4B, // 145 - Zapdos
    0x49, // 146 - Moltres
    0x58, // 147 - Dratini
    0x59, // 148 - Dragonair
    0x42, // 149 - Dragonite
    0x83, // 150 - Mewtwo
    0x15  // 151 - Mew
};

//Funcao que decodifica caracteres
void decoder(unsigned char byte[11]);
//Funcao que lê bits e retorna a quantidade de pokemons vistos/capturados
int bitReader(unsigned char seenOrCatched[19]);
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
//Funcao que mostra os pokemons vistos pelo usuario
int returnSeenedOrOwnedPokemons(unsigned char seenOrCatched[19], int aux);

void decoder(unsigned char byte[11]){
    //Vetor quer mapeia os caracteres
    unsigned char map[256];
    //Variavel de Controle
    int i;

    //Estrutura de Repeticao que inicializa todos os indices com espaco (' ')
    for(i = 0; i < 256; i++){
        map[i] = ' ';
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
        printf("%c", map[byte[i]]);
        byte[i] = map[byte[i]];
        
    }

    printf("\n");

}

//Funcao que retorna a quantidade de pokemons vistos/capturados
int bitReader(unsigned char seenOrCatched[19]){
    int see = 0;
    for(int i = 0; i < 151; i++){
        int byteIndex = i / 8;
        int bitIndex = i % 8;
        int bit = (seenOrCatched[byteIndex] >> bitIndex) & 1;

        if(bit == 1){
            see++;
        }
        
    }

    return see;
}

//Funcao que retorna o trainer ID do usuario
void Id(unsigned char Id[2]){
        unsigned short trainer_id = Id[0] + (Id[1] << 8);
        printf("Trainer ID:%05d\n", trainer_id);
}

//Funcao que retorna a quantidade de insignias do usuario 
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


//Funcao que retorna a quantidade de tempo do save do usuario
void time(unsigned char clock[4]){
    printf("Tempo de Jogo:");
    printf(" %02d Horas e %02d Minutos\n", clock[0], clock[2]);
}

//Funcao que retorna a quantidade de dinheiro possuida pelo usuario
int pokeDollar(unsigned char money[3]){
    int value = 0;
    for(int i = 0; i < 3; i++){
        int highBit = (money[i] >> 4) & 0xF;
        int lowBit = money[i] & 0xF;
        value = value * 100 + highBit * 10 + lowBit;
    }

    return value;
}


//Funcao que retorna os pokemons que o usuario carrega
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

//Funcao que retorna bit logico para saber se o pokemon foi apenas visto, ou capturado
int returnSeenedOrOwnedPokemons(unsigned char seenOrCatched[19], int aux){
    
        int byteIndex = aux / 8;
        int bitIndex = aux % 8;
        int bit = (seenOrCatched[byteIndex] >> bitIndex) & 1;

        if (bit == 1) {
            return 1;
        } else{
            return 0;
        }
}