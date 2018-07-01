CC1 = mpicc
CC2 = mpiexec 

DIRS = build/tarea build/laboratorio build/resultadosTarea build/resultadosLaboratorio
NUM_PROC = 8

MAKE_FOLDERS := $(shell mkdir -p $(DIRS))

#ifeq($(MAKECMDGOALS:all%=%,$(NUM_PROC)))

all: compile run
	@echo "¡Listo!"
#	@echo  $(MAKECMDGOALS)

help:	
	@echo "make : compila y ejecuta todo el proyecto \nmake tarea : compila solo tarea \nmake lab : compila solo laboratorio  \nmake runt : ejecuta archivos compilados de tarea \nmake runl : ejecuta archivos compilados de laboratorio \nmake compile : compila todo el proyecto\nmake run : ejecuta todos los archivos compilados \nmake clean : borra carpetas con ejecutables y resultados" 
#\nmake archivo : compila y ejecuta el archivo indicado
#\nmake run archivo : ejecuta el archivo indicado
	@echo "Archivos existentes:"
	@$(foreach file, $(wildcard src/tarea/*.c), echo $(subst src/tarea/,,$(subst .c,,$(file)));)
	@$(foreach file, $(wildcard src/laboratorio/*.c), echo $(subst src/laboratorio/,,$(subst .c,,$(file)));)

compile: tarea lab

run:	runt runl
#	@echo "Ejecutando código..."
#	@$(foreach exec, $(wildcard build/laboratorio/*.exe), $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec)))
#	@$(foreach exec, $(wildcard build/tarea/*.exe), $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec))) #mv build/**/*.exe build/)
#	@$(foreach exec, $(wildcard build/**/*.exe), echo $(subst build/,,$(exec)); $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec));)
#	@$(foreach output, $(wildcard build/tarea/*.txt), echo mv $(output) $(subst tarea,resultadosTarea,$(output));)
#	@$(foreach output, $(wildcard build/laboratorio/*.txt), echo mv $(output) $(subst laboratorio,resultadosLaboratorio,$(output));)
#	@mv build/tarea/*txt build/resultadosTarea/ ; mv build/laboratorio/*txt build/resultadosLaboratorio/
#	@echo "Ejecución terminada."
#	@echo "_____________________"

runt:
	@echo "Ejecutando tarea..."
	@$(foreach exec, $(wildcard build/tarea/*.exe), echo $(subst build/,,$(exec)); $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec));)
	@mv build/tarea/*txt build/resultadosTarea/
	@echo "Ejecución terminada."
	@echo "_____________________"

runl:
	@echo "Ejecutando laboratorio..."
	@$(foreach exec, $(wildcard build/laboratorio/*.exe), echo $(subst build/,,$(exec)); $(CC2) -np $(NUM_PROC) ./$(exec) > $(subst .exe,Np$(NUM_PROC)Out.txt,$(exec));)
#	@$(foreach exec, $(wildcard build/laboratorio/*.exe), echo time $(subst build/,,$(exec)); $(CC2) -np $(NUM_PROC) ./$(exec)  > $(subst laboratorio/,tiempos,$(subst .exe,Tiempo.txt,$(exec)));)
	@mv build/laboratorio/*txt build/resultadosLaboratorio/
	@echo "Ejecución terminada."
	@echo "_____________________"

tarea:
	@echo "Compilando tarea 2..."
	@$(foreach code, $(wildcard src/tarea/*.c), echo $(subst src/tarea/,,$(code)); $(CC1) $(code) -o $(subst src, build,$(subst .c,.exe,$(code))) -lm ;)
	@echo "Compilación terminada."
	@echo "_____________________"

lab:
	@echo "Compilando ejercicios de laboratorio..."
	@$(foreach code, $(wildcard src/laboratorio/*.c), echo $(subst src/laboratorio/,,$(code)); $(CC1) $(code) -o $(subst src, build,$(subst .c,.exe,$(code))) -lm ;)
	@echo "Compilación terminada."
	@echo "_____________________"

clean:
	rm -R build/
