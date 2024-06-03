#include <string.h>
#include <stdio.h>
#include "util.h"

void imprimir_titulo(const char* titulo) {
    printf("\n===============================================\n");
    printf("%s\n", titulo);
    printf("================================================\n\n");
}

void leer_cadena(char* buffer, int longitud) {
    fgets(buffer, longitud, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remover el carácter de nueva línea
}
