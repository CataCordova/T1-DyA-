#Makefile para Tarea de estructura de Datos
tarea: main.c
	gcc main.c -o salida
	./salida

clean:
	$(RM) main