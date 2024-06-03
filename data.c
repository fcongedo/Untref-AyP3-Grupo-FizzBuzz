#include "data.h"
#include <stdio.h>
#include <string.h>

void inicializar_sistema(Sistema* sistema) {
    sistema->num_estudiantes = 0;
    sistema->num_materias = 0;
}

void liberar_sistema(Sistema* sistema) {
    (void)sistema;// No hay memoria dinámica que liberar en este caso
}

void guardar_estudiantes_csv(const Sistema* sistema, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < sistema->num_estudiantes; i++) {
           const Estudiante* e = &sistema->estudiantes[i];
            fprintf(file, "%s,%d\n", e->nombre, e->edad);
        }
        fclose(file);
    }
}

void cargar_estudiantes_csv(Sistema* sistema, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            Estudiante e;
            sscanf(buffer, "%99[^,],%d", e.nombre, &e.edad);
            sistema->estudiantes[sistema->num_estudiantes++] = e;
        }
        fclose(file);
    }
}
