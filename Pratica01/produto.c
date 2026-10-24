#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
} Produto;

int main(void) {
    Produto catalogo[3] = {
        {"Teclado Mecanico", 250.00f},
        {"Mouse", 80.00f},
        {"Monitor", 900.00f}
    };

    char termo[50];
    int encontrado = 0;

    printf("Digite o nome do produto para consulta: ");

    if (fgets(termo, sizeof(termo), stdin) == NULL) {
        printf("Erro ao ler o nome do produto.\n");
        return 1;
    }

    termo[strcspn(termo, "\n")] = '\0';

    for (int i = 0; i < 3; i++) {
        if (strcmp(termo, catalogo[i].nome) == 0) {
            printf("[Sucesso] Produto: %s | Preco: R$ %.2f\n",
                   catalogo[i].nome, catalogo[i].preco);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("[Aviso] O item \"%s\" nao consta no catalogo da loja.\n", termo);
    }

    return 0;
}
