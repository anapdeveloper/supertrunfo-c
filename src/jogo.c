#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

// Função para embaralhar o deck usando o algoritmo Fisher-Yates
void embaralhar(struct Carta baralho[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// Função para comparar o atributo escolhido
// Retorna 1 se o jogador 1 vence, -1 se o jogador 2 vence, 0 para empate
int compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    double val1, val2;
    switch (atributo) {
        case 1: val1 = c1.populacao; val2 = c2.populacao; break;
        case 2: val1 = c1.pib; val2 = c2.pib; break;
        case 3: val1 = c1.area; val2 = c2.area; break;
        case 4: val1 = c1.idh; val2 = c2.idh; break;
        case 5: val1 = c1.densidadePopulacional; val2 = c2.densidadePopulacional; break;
        case 6: val1 = c1.pibPerCapita; val2 = c2.pibPerCapita; break;
        default: return 0;
    }
    if (val1 > val2) return 1;
    if (val2 > val1) return -1;
    return 0;
}

// A função principal do jogo
void iniciarJogo(struct Carta baralho[]) {
    struct Carta maoJogador[TAMANHO_DECK];
    struct Carta maoOponente[TAMANHO_DECK];
    struct Carta monte[TAMANHO_DECK]; // Cartas em caso de empate
    int numCartasJogador = 0;
    int numCartasOponente = 0;
    int numCartasMonte = 0;

    // Distribuir cartas
    for (int i = 0; i < TAMANHO_DECK; i++) {
        if (i % 2 == 0) {
            maoJogador[numCartasJogador++] = baralho[i];
        } else {
            maoOponente[numCartasOponente++] = baralho[i];
        }
    }

    int turnoJogador = 1; // 1 para jogador, 0 para oponente
    int rodada = 1;

    // Loop principal do jogo
    while (numCartasJogador > 0 && numCartasOponente > 0) {
        printf("\n\n--- RODADA %d ---\n", rodada++);
        printf("PLACAR: Você [%d cartas] vs Oponente [%d cartas]\n", numCartasJogador, numCartasOponente);

        struct Carta cartaJogador = maoJogador[0];
        struct Carta cartaOponente = maoOponente[0];

        if (cartaJogador.ehSuperTrunfo) {
             printf("Você tem o SUPER TRUNFO! Você venceu a rodada automaticamente!\n");
             exibirCarta(cartaJogador, 0);
             maoJogador[numCartasJogador++] = cartaOponente;
             numCartasOponente--;
             //mover cartas do monte para o jogador
             for(int i=0; i < numCartasMonte; i++){ maoJogador[numCartasJogador++] = monte[i]; }
             numCartasMonte = 0;
             turnoJogador = 1; // Quem vence joga
             continue; //Pula para proxima rodada
        }
        if (cartaOponente.ehSuperTrunfo) {
             printf("O oponente tem o SUPER TRUNFO! Ele venceu a rodada automaticamente!\n");
             exibirCarta(cartaOponente, 0);
             maoOponente[numCartasOponente++] = cartaJogador;
             numCartasJogador--;
             //mover cartas do monte para o oponente
             for(int i=0; i < numCartasMonte; i++){ maoOponente[numCartasOponente++] = monte[i]; }
             numCartasMonte = 0;
             turnoJogador = 0; // Quem vence joga
             continue; //Pula para proxima rodada
        }


        printf("Sua carta é:\n");
        exibirCarta(cartaJogador, turnoJogador);
        
        int escolha = 0;
        if(turnoJogador) {
            printf("Escolha um atributo (1-6): ");
            scanf("%d", &escolha);
            while(escolha < 1 || escolha > 6) {
                printf("Opção inválida. Escolha um atributo (1-6): ");
                scanf("%d", &escolha);
            }
        } else {
            printf("Oponente está escolhendo...\n");
            // Lógica simples para o PC: escolher o melhor atributo
            double maxVal = 0;
            for(int i=1; i<=6; i++){
                if(compararAtributo(cartaOponente, cartaJogador, i) == 1){
                     escolha = i;
                     break;
                }
            }
            if(escolha == 0) escolha = 1; // Se não tiver nenhum melhor, escolhe o primeiro
            printf("Oponente escolheu o atributo %d.\n", escolha);
        }

        int resultado = compararAtributo(cartaJogador, cartaOponente, escolha);

        printf("\n-- Disputa --\n");
        exibirCarta(cartaJogador, 0);
        printf("      VS\n");
        exibirCarta(cartaOponente, 0);

        // Remove cartas das mãos dos jogadores
        for(int i=0; i < numCartasJogador - 1; i++) maoJogador[i] = maoJogador[i+1];
        numCartasJogador--;
        for(int i=0; i < numCartasOponente - 1; i++) maoOponente[i] = maoOponente[i+1];
        numCartasOponente--;

        if (resultado == 1) { // Jogador vence
            printf("\n>> Você venceu a rodada!\n");
            maoJogador[numCartasJogador++] = cartaJogador;
            maoJogador[numCartasJogador++] = cartaOponente;
            for(int i=0; i < numCartasMonte; i++){ maoJogador[numCartasJogador++] = monte[i]; }
            numCartasMonte = 0;
            turnoJogador = 1;
        } else if (resultado == -1) { // Oponente vence
            printf("\n>> O oponente venceu a rodada!\n");
            maoOponente[numCartasOponente++] = cartaJogador;
            maoOponente[numCartasOponente++] = cartaOponente;
            for(int i=0; i < numCartasMonte; i++){ maoOponente[numCartasOponente++] = monte[i]; }
            numCartasMonte = 0;
            turnoJogador = 0;
        } else { // Empate
            printf("\n>> Empate! As cartas vão para o monte.\n");
            monte[numCartasMonte++] = cartaJogador;
            monte[numCartasMonte++] = cartaOponente;
        }
    }

    // Fim de jogo
    printf("\n\n################ FIM DE JOGO ################\n");
    if (numCartasJogador > 0) {
        printf("PARABÉNS! Você venceu o jogo!\n");
    } else {
        printf("Que pena! O oponente venceu o jogo.\n");
    }
}