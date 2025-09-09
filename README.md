Super Trunfo de Cidades de MG em C
Este é um projeto de console em C que implementa o clássico jogo Super Trunfo, utilizando como tema as cidades de Minas Gerais.

O jogo foi desenvolvido com uma estrutura modular, separando a lógica das cartas e a mecânica do jogo em diferentes arquivos, seguindo boas práticas de engenharia de software.

Funcionalidades
Baralho com 8 cidades de Minas Gerais.

Uma carta "Super Trunfo" que vence qualquer outra.

Sistema de turnos: quem vence a rodada joga na próxima.

Lógica de "monte" para rodadas empatadas.

Oponente com uma IA simples para escolher o melhor atributo.

Embaralhamento aleatório das cartas a cada novo jogo.

Estrutura do Projeto
/include: Contém os arquivos de cabeçalho (.h) com as declarações de structs e funções.

/src: Contém os arquivos de código-fonte (.c) com a implementação da lógica.

Makefile: Script para facilitar a compilação do projeto.

Como Compilar e Executar
Pré-requisitos: É necessário ter um compilador C como o GCC instalado.

Compilar: Navegue até a pasta raiz do projeto no terminal e execute o comando:

make

Isso irá compilar o projeto e criar um executável chamado supertrunfo.

Executar: Para iniciar o jogo, execute o seguinte comando:

./supertrunfo

Como Jogar
O baralho será embaralhado e dividido entre você e o computador.

A cada rodada, a carta do topo do seu monte é revelada.

Se for sua vez, você escolhe um atributo para comparar. Se for a vez do computador, ele escolherá o atributo com maior valor.

Quem tiver o maior valor no atributo escolhido vence a rodada e fica com a carta do oponente.

Em caso de empate, as cartas vão para um "monte" e são disputadas na próxima rodada.

O jogo termina quando um dos jogadores fica com todas as cartas do baralho.

