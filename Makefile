CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcunit

OBJ = main.o estudiante.o materia.o util.o data.o config.o

sistema: $(OBJ)
	$(CC) -o sistema $(OBJ) $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

estudiante.o: estudiante.c estudiante.h
	$(CC) $(CFLAGS) -c estudiante.c

materia.o: materia.c materia.h
	$(CC) $(CFLAGS) -c materia.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

config.o: config.c config.h
	$(CC) $(CFLAGS) -c config.c

clean:
	rm -f *.o sistema