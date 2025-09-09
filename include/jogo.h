#ifndef JOGO_H
#define JOGO_H

#include "carta.h" // Precisa conhecer a struct Carta

// Declaração das funções que serão implementadas em jogo.c
void embaralhar(struct Carta baralho[], int n);
void iniciarJogo(struct Carta baralho[]);

#endif //JOGO_H