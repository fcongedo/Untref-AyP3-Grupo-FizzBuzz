#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "estudiante.h"
#include "materia.h"
#include "util.h"
#include "config.h"

void mostrar_menu() {
    imprimir_titulo("Sistema de Gestión de Estudiantes");
    printf("1. Alta Estudiante\n");
    printf("2. Modificar Estudiante\n");
    printf("3. Eliminar Estudiante\n");
    printf("4. Listar Estudiantes\n");
    printf("5. Buscar Estudiante por Nombre\n");
    printf("6. Buscar Estudiante por Rango de Edad\n");
    printf("7. Alta Materia\n");
    printf("8. Modificar Materia\n");
    printf("9. Eliminar Materia\n");
    printf("10. Listar Materias\n");
    printf("11. Anotar Estudiante en Materia\n");
    printf("12. Rendir Materia\n");
    printf("13. Estadísticas\n");
    printf("14. Generar Datos Aleatorios\n");
    printf("15. Guardar Datos\n");
    printf("16. Cargar Datos\n");
    printf("17. Salir\n");
    printf("Seleccione una opción: ");
}

int main() {
    srand((unsigned int)time(NULL));

    Configuracion config;
    if (!cargar_configuracion("config.txt", &config)) {
        printf(RED_COLOR "Error al cargar el archivo de configuración." RESET_COLOR "\n");
        return 1;
    }

    Sistema sistema;
    inicializar_sistema(&sistema);

    char nombre[MAX_NAME_LEN];
    int edad, id, min_edad, max_edad, estudiante_id, materia_id;

    int opcion;
    do {
        mostrar_menu();
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        switch (opcion) {
            case 1:
                printf("Nombre: ");
                leer_cadena(nombre, MAX_NAME_LEN);
                printf("Edad: ");
                scanf("%d", &edad);
                alta_estudiante(&sistema, nombre, edad);
                break;

            case 2:
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                printf("Nuevo Nombre: ");
                leer_cadena(nombre, MAX_NAME_LEN);
                printf("Nueva Edad: ");
                scanf("%d", &edad);
                modificar_estudiante(&sistema, id, nombre, edad);
                break;

            case 3:
                printf("ID: ");
                scanf("%d", &id);
                eliminar_estudiante(&sistema, id);
                break;

            case 4:
                listar_estudiantes(&sistema);
                break;

            case 5:
                printf("Nombre: ");
                leer_cadena(nombre, MAX_NAME_LEN);
                buscar_estudiante_nombre(&sistema, nombre);
                break;

            case 6:
                printf("Edad mínima: ");
                scanf("%d", &min_edad);
                printf("Edad máxima: ");
                scanf("%d", &max_edad);
                buscar_estudiante_edad(&sistema, min_edad, max_edad);
                break;

            case 7:
                printf("Nombre: ");
                leer_cadena(nombre, MAX_NAME_LEN);
                alta_materia(&sistema, nombre);
                break;

            case 8:
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                printf("Nuevo Nombre: ");
                leer_cadena(nombre, MAX_NAME_LEN);
                modificar_materia(&sistema, id, nombre);
                break;

            case 9:
                printf("ID: ");
                scanf("%d", &id);
                eliminar_materia(&sistema, id);
                break;

            case 10:
                listar_materias(&sistema);
                break;

            case 11:
                printf("ID Estudiante: ");
                scanf("%d", &estudiante_id);
                printf("ID Materia: ");
                scanf("%d", &materia_id);
                anotar_estudiante_materia(&sistema, estudiante_id, materia_id);
                break;

            case 12:
                printf("ID Estudiante: ");
                scanf("%d", &estudiante_id);
                printf("ID Materia: ");
                scanf("%d", &materia_id);
                rendir_materia(&sistema, estudiante_id, materia_id);
                break;

            case 13:
                estadisticas_estudiantes(&sistema);
                estadisticas_materias(&sistema);
                break;
            case 14:
                generar_estudiantes_aleatorios(&sistema, 10);
                generar_materias_aleatorias(&sistema, 5);
                break;
            case 15:
                guardar_estudiantes_csv(&sistema, "estudiantes.csv");
                break;
            case 16:
                cargar_estudiantes_csv(&sistema, "estudiantes.csv");
                break;
        }
    } while (opcion != 17);

    liberar_sistema(&sistema);
    return 0;
}
