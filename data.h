#ifndef DATA_H
#define DATA_H

#define MAX_NAME_LEN 100
#define MAX_ESTUDIANTES 1000
#define MAX_MATERIAS 500

typedef struct {
    char nombre[MAX_NAME_LEN];
    int edad;
    int materias_inscritas[MAX_MATERIAS];
    int notas[MAX_MATERIAS];
    int num_materias;
} Estudiante;

typedef struct {
    char nombre[MAX_NAME_LEN];
    int estudiantes_inscritos[MAX_ESTUDIANTES];
    int num_estudiantes;
} Materia;

typedef struct {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    Materia materias[MAX_MATERIAS];
    int num_estudiantes;
    int num_materias;
} Sistema;

void inicializar_sistema(Sistema* sistema);
void liberar_sistema(Sistema* sistema);
void guardar_estudiantes_csv(const Sistema* sistema, const char* filename);
void cargar_estudiantes_csv(Sistema* sistema, const char* filename);

#endif // DATA_H
