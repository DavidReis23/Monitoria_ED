#include <stdio.h>

void draw_torre(int n);
void turbinar_torre(int *torre, int bonus);
void swap_torres(int *a, int *b);

int main(void) {
    int alfa, beta;

    printf("=== PAINEL DE CONTROLE DE TORRES ===\n");

    printf("Digite o nivel inicial da Torre Alfa: ");
    if (scanf("%d", &alfa) != 1) {
        printf("Entrada invalida para a Torre Alfa!\n");
        return 1;
    }

    printf("Digite o nivel inicial da Torre Beta: ");
    if (scanf("%d", &beta) != 1) {
        printf("Entrada invalida para a Torre Beta!\n");
        return 1;
    }

    if (alfa <= 0 || beta <= 0) {
        printf("Aviso: os niveis das torres devem ser maiores que zero!\n");
        return 1;
    }

    printf("\n--- ESTADO INICIAL ---\n");
    printf("Torre Alfa (Nivel %d):\n", alfa);
    draw_torre(alfa);

    printf("Torre Beta (Nivel %d):\n", beta);
    draw_torre(beta);

    turbinar_torre(&alfa, 2);
    swap_torres(&alfa, &beta);

    printf("\n--- ESTADO FINAL APOS PONTEIROS ---\n");
    printf("Torre Alfa Agora (Nivel %d):\n", alfa);
    draw_torre(alfa);

    printf("Torre Beta Agora (Nivel %d):\n", beta);
    draw_torre(beta);

    return 0;
}

void draw_torre(int n) {
    if (n <= 0) {
        return;
    }

    draw_torre(n - 1);

    for (int i = 0; i < n; i++) {
        printf("# ");
    }

    printf("\n");
}

void turbinar_torre(int *torre, int bonus) {
    if (torre != NULL) {
        *torre = *torre + bonus;
    }
}

void swap_torres(int *a, int *b) {
    if (a != NULL && b != NULL) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
