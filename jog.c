#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int jogador, computador;
    int vidasJogador = 3;
    int vidasComputador = 3;
    int max = 3;
    int min = 1;

    printf("[]==============================[]\n");
    printf("[]                              []\n");
    printf("[]   PEDRA, PAPEL OU TESOURA    []\n");
    printf("[]      - BATALHA DE VIDAS -    []\n");
    printf("[]                              []\n");
    printf("[]==============================[]\n");

    while (vidasJogador > 0 && vidasComputador > 0) {

// Limpa a tela a cada rodada

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\nVidas - Você: %d | Computador: %d\n", vidasJogador, vidasComputador);
        printf("\nEscolha sua jogada:\n");
        printf("1 - PEDRA, 2 - PAPEL, 3 - TESOURA: ");
        scanf("%d", &jogador);

// Validação da jogada

        if (jogador < 1 || jogador > 3) {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

// Jogada do computador

        computador = min + rand() % (max - min + 1);

// Exibe jogadas

        printf("\nVocê escolheu: ");
        if (jogador == 1) printf("Pedra\n");
        else if (jogador == 2) printf("Papel\n");
        else printf("Tesoura\n");

        printf("Computador escolheu: ");
        if (computador == 1) printf("Pedra\n");
        else if (computador == 2) printf("Papel\n");
        else printf("Tesoura\n");

// Resultado da rodada

        if (jogador == computador) {
            printf("\nEmpate! Ninguém perde vida. ( OLHA QUE MERDA )\n");
        } 
        else if ((jogador == 1 && computador == 3) ||
                 (jogador == 2 && computador == 1) ||
                 (jogador == 3 && computador == 2)) {
            printf("\nIncrível! Você venceu esta rodada!\n");
            vidasComputador--;
        } 
        else {
            if (vidasJogador == 2) {
                printf("\nComputador venceu esta rodada! Tá jogando vendado?\n");
            } else if (vidasJogador == 1) {
                printf("\nComputador venceu esta rodada! Tá jogando com a mão amarrada?\n");
            } else {
                printf("\nComputador venceu esta rodada!\n");
            }
            vidasJogador--;  // Isso precisa acontecer em qualquer derrota
        }

// Pausa rápida antes da próxima rodada

        printf("\nPressione ENTER para continuar...");
        getchar(); // consome enter do scanf
        getchar(); // espera enter
    }

// Resultado final

    printf("\n===== FIM DO JOGO =====\n");

    if (vidasJogador == 0) {
        printf("Você perdeu todas as vidas! Computador venceu, seu misseavel.\n");
    } else {
        if (vidasJogador == 3) {
            printf("FLAWLESS VICTORY! PUTA MIERDA! eu realmente não esperava isso.\n");
            
// Créditos secretos

            printf("\n[]===================================[]\n");
            printf("[]        CRÉDITOS ESPECIAIS         []\n");
            printf("[]===================================[]\n");
            printf("[]                                   []\n");
            printf("[]     Parabéns, seu miseravel!      []\n");
            printf("[]      Você alcançou o ápice        []\n");
            printf("[]    sem perder uma única vida.     []\n");
            printf("[]                                   []\n");
            printf("[]  Desenvolvido por: O_MARQUEZINI   []\n");
            printf("[]    feito com C e muita cafeína    []\n");
            printf("[]   e também falta do que fazer.    []\n");
            printf("[]                                   []\n");
            printf("[]   Até a próxima batalha. BIXA!    []\n");
            printf("[]===================================[]\n");
        } else {
            printf("Você venceu! Parabéns por fazer o mínimo.\n");
        }
    }

    return 0;
}