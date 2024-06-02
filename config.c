#include "config.h"
#include <stdio.h>

int cargar_configuracion(const char* filename, Configuracion* config) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 0;
    }
    fscanf(file, "%d %d", &config->max_estudiantes, &config->max_materias);
    fclose(file);
    return 1;
}
