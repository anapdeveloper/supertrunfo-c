#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "jogo.h"

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Cria o baralho principal
    struct Carta baralho[TAMANHO_DECK];
    criarBaralho(baralho);

    printf("Bem-vindo ao Super Trunfo de Cidades de MG!\n");
    printf("O baralho foi criado. Embaralhando as cartas...\n");

    // Embaralha e inicia o jogo
    embaralhar(baralho, TAMANHO_DECK);
    iniciarJogo(baralho);

    return 0;
}