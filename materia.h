#ifndef MATERIA_H
#define MATERIA_H

#include "data.h"

void alta_materia(Sistema* sistema, const char* nombre);
void modificar_materia(Sistema* sistema, int id, const char* nombre);
void eliminar_materia(Sistema* sistema, int id);
void listar_materias(const Sistema* sistema);
void anotar_estudiante_materia(Sistema* sistema, int estudiante_id, int materia_id);
void rendir_materia(Sistema* sistema, int estudiante_id, int materia_id);
void estadisticas_estudiantes(const Sistema* sistema);
void estadisticas_materias(const Sistema* sistema);
void generar_materias_aleatorias(Sistema* sistema, int cantidad);

#endif // MATERIA_H
