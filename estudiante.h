#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "data.h"

void alta_estudiante(Sistema* sistema, const char* nombre, int edad);
void modificar_estudiante(Sistema* sistema, int id, const char* nombre, int edad);
void eliminar_estudiante(Sistema* sistema, int id);
void listar_estudiantes(const Sistema* sistema);
void buscar_estudiante_nombre(const Sistema* sistema, const char* nombre);
void buscar_estudiante_edad(const Sistema* sistema, int edad_min, int edad_max);
void generar_estudiantes_aleatorios(Sistema* sistema, int cantidad);

#endif // ESTUDIANTE_H
