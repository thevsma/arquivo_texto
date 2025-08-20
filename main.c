#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int total_char = 0, total_linhas = 0, total_palavras = 0;

    FILE* fp;
    fp = fopen("entrada.txt", "r");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo texto");
        exit(1);
    }

    char ch;
    int in_word = 0;
    while ((ch = fgetc(fp)) != EOF) {
        total_char++;

        if (isspace(ch)) {
            in_word = 0;
        }else if (!in_word) {
            in_word = 1;
            total_palavras++;
        }

        if (ch == '\n') {
            total_linhas++;
        }
    }

    printf("total de char: %d\ntotal de linhas: %d\ntotal de palavras: %d\n", total_char, total_linhas, total_palavras);

    return 0;
}