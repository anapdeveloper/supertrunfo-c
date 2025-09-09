#include <stdio.h>
#include <string.h>
#include "carta.h"

// Função que preenche o nosso baralho com dados reais
void criarBaralho(struct Carta baralho[]) {
    // Dados de 8 cidades de Minas Gerais
    struct Carta dados[TAMANHO_DECK] = {
        {"Belo Horizonte", 2315560, 98.5, 331.3, 810, 0, 0, 0},
        {"Uberlandia", 713232, 43.2, 4115.2, 789, 0, 0, 0},
        {"Contagem", 621865, 34.7, 195.3, 766, 0, 0, 0},
        {"Juiz de Fora", 516247, 17.6, 1436.8, 778, 0, 0, 0},
        {"Montes Claros", 394350, 12.5, 3582.0, 762, 0, 0, 0},
        {"Divinopolis", 231091, 7.8, 708.9, 759, 0, 0, 0},
        {"Ouro Preto", 74824, 3.1, 1245.8, 788, 0, 0, 0},
        {"Diamantina", 47723, 1.2, 3869.7, 749, 0, 0, 1} // Diamantina é o Super Trunfo!
    };

    // Copia os dados para o array do baralho
    for (int i = 0; i < TAMANHO_DECK; i++) {
        baralho[i] = dados[i];
        calcularAtributosDerivados(&baralho[i]);
    }
}

// Calcula os atributos que não são inseridos diretamente
void calcularAtributosDerivados(struct Carta *carta) {
    if (carta->area > 0) {
        carta->densidadePopulacional = (double)carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}

// Mostra uma carta na tela
void exibirCarta(struct Carta carta, int modoCompleto) {
    printf("\n============== CARTA ==============\n");
    if(carta.ehSuperTrunfo) {
        printf(">>> SUPER TRUNFO <<<\n");
    }
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("-----------------------------------\n");

    if (modoCompleto) {
        printf("[1] População: %ld hab\n", carta.populacao);
        printf("[2] PIB: R$ %.2f Bi\n", carta.pib);
        printf("[3] Área: %.2f km²\n", carta.area);
        printf("[4] IDH (x1000): %d\n", carta.idh);
        printf("[5] Densidade: %.2f hab/km²\n", carta.densidadePopulacional);
        printf("[6] PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
    } else {
        printf("População: %ld hab\n", carta.populacao);
        printf("PIB: R$ %.2f Bi\n", carta.pib);
        printf("Área: %.2f km²\n", carta.area);
        printf("IDH (x1000): %d\n", carta.idh);
        printf("Densidade: %.2f hab/km²\n", carta.densidadePopulacional);
        printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
    }
     printf("===================================\n");
}