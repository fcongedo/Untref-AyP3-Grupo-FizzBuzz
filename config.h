#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int max_estudiantes;
    int max_materias;
} Configuracion;

int cargar_configuracion(const char* filename, Configuracion* config);

#endif // CONFIG_H
