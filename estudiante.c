#include "estudiante.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void alta_estudiante(Sistema* sistema, const char* nombre, int edad) {
    if (sistema->num_estudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes.\n");
        return;
    }
    Estudiante* e = &sistema->estudiantes[sistema->num_estudiantes++];
    strncpy(e->nombre, nombre, MAX_NAME_LEN);
    e->edad = edad;
    e->num_materias = 0;
}

void modificar_estudiante(Sistema* sistema, int id, const char* nombre, int edad) {
    if (id < 0 || id >= sistema->num_estudiantes) {
        printf("ID de estudiante no válido.\n");
        return;
    }
    Estudiante* e = &sistema->estudiantes[id];
    strncpy(e->nombre, nombre, MAX_NAME_LEN);
    e->edad = edad;
}

void eliminar_estudiante(Sistema* sistema, int id) {
    if (id < 0 || id >= sistema->num_estudiantes) {
        printf("ID de estudiante no válido.\n");
        return;
    }
    for (int i = id; i < sistema->num_estudiantes - 1; i++) {
        sistema->estudiantes[i] = sistema->estudiantes[i + 1];
    }
    sistema->num_estudiantes--;
}

void listar_estudiantes(const Sistema* sistema) {
    for (int i = 0; i < sistema->num_estudiantes; i++) {
       const Estudiante* e = &sistema->estudiantes[i];
        printf("ID: %d, Nombre: %s, Edad: %d\n", i, e->nombre, e->edad);
    }
}

void buscar_estudiante_nombre(const Sistema* sistema, const char* nombre) {
    for (int i = 0; i < sistema->num_estudiantes; i++) {
       const Estudiante* e = &sistema->estudiantes[i];
        if (strcmp(e->nombre, nombre) == 0) {
            printf("ID: %d, Nombre: %s, Edad: %d\n", i, e->nombre, e->edad);
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

void buscar_estudiante_edad(const Sistema* sistema, int edad_min, int edad_max) {
    for (int i = 0; i < sistema->num_estudiantes; i++) {
       const Estudiante* e = &sistema->estudiantes[i];
        if (e->edad >= edad_min && e->edad <= edad_max) {
            printf("ID: %d, Nombre: %s, Edad: %d\n", i, e->nombre, e->edad);
        }
    }
}

void generar_estudiantes_aleatorios(Sistema* sistema, int cantidad) {
    const char* nombres[] = {"Juan", "Maria", "Luis", "Ana", "Pedro"};
    int num_nombres = sizeof(nombres) / sizeof(nombres[0]);
    for (int i = 0; i < cantidad; i++) {
        if (sistema->num_estudiantes >= MAX_ESTUDIANTES) {
            break;
        }
        const char* nombre = nombres[rand() % num_nombres];
        int edad = rand() % 10 + 18; // Edad entre 18 y 27
        alta_estudiante(sistema, nombre, edad);
    }
}
