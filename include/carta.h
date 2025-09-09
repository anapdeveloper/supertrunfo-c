#ifndef CARTA_H
#define CARTA_H

// Constante para o tamanho do baralho
#define TAMANHO_DECK 8

// Estrutura de dados para cada carta
struct Carta {
    char nomeCidade[50];
    long int populacao;
    double pib;
    double area;
    int idh; // Trocamos pontos turísticos por IDH (0 a 1000)
    double densidadePopulacional;
    double pibPerCapita;
    int ehSuperTrunfo; // 1 se for, 0 se não for
};

// Declaração das funções que serão implementadas em carta.c
void criarBaralho(struct Carta baralho[]);
void calcularAtributosDerivados(struct Carta *carta);
void exibirCarta(struct Carta carta, int modoCompleto);

#endif //CARTA_H