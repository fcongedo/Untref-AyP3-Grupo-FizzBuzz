#include <stdlib.h>
#include "materia.h"
#include <stdio.h>
#include <string.h>



void alta_materia(Sistema* sistema, const char* nombre) {
    if (sistema->num_materias >= MAX_MATERIAS) {
        printf("No se pueden agregar más materias.\n");
        return;
    }
    Materia* m = &sistema->materias[sistema->num_materias++];
    strncpy(m->nombre, nombre, MAX_NAME_LEN);
    m->num_estudiantes = 0;
}

void modificar_materia(Sistema* sistema, int id, const char* nombre) {
    if (id < 0 || id >= sistema->num_materias) {
        printf("ID de materia no válido.\n");
        return;
    }
    Materia* m = &sistema->materias[id];
    strncpy(m->nombre, nombre, MAX_NAME_LEN);
}

void eliminar_materia(Sistema* sistema, int id) {
    if (id < 0 || id >= sistema->num_materias) {
        printf("ID de materia no válido.\n");
        return;
    }
    for (int i = id; i < sistema->num_materias - 1; i++) {
        sistema->materias[i] = sistema->materias[i + 1];
    }
    sistema->num_materias--;
}

void listar_materias(const Sistema* sistema) {
    for (int i = 0; i < sistema->num_materias; i++) {
        const Materia* m = &sistema->materias[i];
        printf("ID: %d, Nombre: %s\n", i, m->nombre);
    }
}

void anotar_estudiante_materia(Sistema* sistema, int estudiante_id, int materia_id) {
    if (estudiante_id < 0 || estudiante_id >= sistema->num_estudiantes || materia_id < 0 || materia_id >= sistema->num_materias) {
        printf("ID de estudiante o materia no válido.\n");
        return;
    }
    Estudiante* e = &sistema->estudiantes[estudiante_id];
    Materia* m = &sistema->materias[materia_id];
    e->materias_inscritas[e->num_materias++] = materia_id;
    m->estudiantes_inscritos[m->num_estudiantes++] = estudiante_id;
}

void rendir_materia(Sistema* sistema, int estudiante_id, int materia_id) {
    if (estudiante_id < 0 || estudiante_id >= sistema->num_estudiantes || materia_id < 0 || materia_id >= sistema->num_materias) {
        printf("ID de estudiante o materia no válido.\n");
        return;
    }
    Estudiante* e = &sistema->estudiantes[estudiante_id];
    for (int i = 0; i < e->num_materias; i++) {
        if (e->materias_inscritas[i] == materia_id) {
            e->notas[i] = rand() % 10 + 1; // Nota entre 1 y 10
            return;
        }
    }
    printf("El estudiante no está inscrito en esta materia.\n");
}

void estadisticas_estudiantes(const Sistema* sistema) {
    int total = sistema->num_estudiantes;
    float promedio_edad = 0.0f;
    for (int i = 0; i < total; ++i) {
        promedio_edad += (float)sistema->estudiantes[i].edad;
    }
    promedio_edad /= (float)total;
    printf("Total de Estudiantes: %d\n", total);
    printf("Edad Promedio: %.2f\n", promedio_edad);
}

void estadisticas_materias(const Sistema* sistema) {
    int total = sistema->num_materias;
    printf("Total de Materias: %d\n", total);
}

void generar_materias_aleatorias(Sistema* sistema, int cantidad) {
    const char* nombres[] = {"Matemáticas", "Física", "Química", "Historia", "Geografía"};
    int num_nombres = sizeof(nombres) / sizeof(nombres[0]);
    for (int i = 0; i < cantidad; i++) {
        if (sistema->num_materias >= MAX_MATERIAS) {
            break;
        }
        const char* nombre = nombres[rand() % num_nombres];
        alta_materia(sistema, nombre);
    }
}
