CC1 = mpicc
CC2 = mpiexec 

DIRS = build/tarea build/laboratorio build/rTarea build/rLaboratorio
NUM_PROC = 8

MAKE_FOLDERS := $(shell mkdir -p $(DIRS))

#ifeq($(MAKECMDGOALS:all%=%,$(NUM_PROC)))

all: compile run
	@echo "¡Listo!"
	@echo  $(MAKECMDGOALS)
#all: all8 all2 primosSec

help:	
	@echo "make : compila y ejecuta todo el proyecto \nmake tarea : compila y ejecuta solo tarea \nmake lab : compila y ejecuta solo laboratorio \nmake compile : compila todo el proyecto\nmake run : ejecuta todos los archivos compilados \nmake clean : borra carpetas con ejecutables y resultados" 
#\nmake archivo : compila y ejecuta el archivo indicado
#\nmake run archivo : ejecuta el archivo indicado
	@echo "Archivos existentes:"
	@$(foreach file, $(wildcard src/tarea/*.c), echo $(subst src/tarea/,,$(subst .c,,$(file)));)
	@$(foreach file, $(wildcard src/laboratorio/*.c), echo $(subst src/laboratorio/,,$(subst .c,,$(file)));)

compile: tarea lab

run:
	@echo "Ejecutando código..."
#	@$(foreach exec, $(wildcard build/laboratorio/*.exe), $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec)))
#	@$(foreach exec, $(wildcard build/tarea/*.exe), $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec))) #mv build/**/*.exe build/)
	@$(foreach exec, $(wildcard build/**/*.exe), echo $(subst build/,,$(exec)); $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec));)
	@mv build/tarea/*txt build/rTarea/ ; mv build/laboratorio/*txt build/rLaboratorio/
	@echo "Ejecución terminada."
	@echo "_____________________"

#all8: compilar
#	$(CC2) -np 8 ./NumerosPrimos > test8.txt
#	$(CC2) -np 8 ./Matrix > matrix8.txt

#all2: compilar
#	$(CC2) -np 2 ./NumerosPrimos > test2.txt
#	$(CC2) -np 2 ./Matrix > matrix2.txt

#compilar:
#	$(CC1) NumerosPrimos.c -o NumerosPrimos -lm
#	$(CC1) Matrix.c -o Matrix -lm	

#primosSec:
#	$(CC1) NumerosPrimos.c -o build/NumerosPrimos -lm
#	$(CC2) -np 1 ./NumerosPrimos > primosSec.txt

#primos2:
#	$(CC1) NumerosPrimos.c -o NumerosPrimos -lm
#	$(CC2) -np 2 ./NumerosPrimos > primos2.txt

#primos8:
#	$(CC1) NumerosPrimos.c -o NumerosPrimos -lm
#	$(CC2) -np 8 ./NumerosPrimos > primos8.txt

#matrix2:
#	$(CC1) Matrix.c -o Matrix -lm
#	$(CC2) -np 2 ./Matrix > matrix2.txt

#matrix8:
#	$(CC1) Matrix.c -o Matrix -lm
#	$(CC2) -np 8 ./Matrix > matrix8.txt

tarea:
	@echo "Compilando tarea 2..."
	@$(foreach code, $(wildcard src/tarea/*.c), echo $(subst src/tarea/,,$(code)); $(CC1) $(code) -o $(subst src, build,$(subst .c,.exe,$(code)));)
	@echo "Compilación terminada."
	@echo "_____________________"

lab:
	@echo "Compilando ejercicios de laboratorio..."
	@$(foreach code, $(wildcard src/laboratorio/*.c), echo $(subst src/laboratorio/,,$(code)); $(CC1) $(code) -o $(subst src, build,$(subst .c,.exe,$(code)));)
	@echo "Compilación terminada."
	@echo "_____________________"

clean:
	rm -R build/
