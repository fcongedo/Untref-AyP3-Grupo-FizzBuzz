#include <string.h>
#include <stdio.h>
#include "util.h"

void imprimir_titulo(const char* titulo) {
    printf("=== %s ===\n", titulo);
}

void leer_cadena(char* buffer, int longitud) {
    fgets(buffer, longitud, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remover el carácter de nueva línea
}
