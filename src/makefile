compiler = g++
std = -std=c++14
main = main.cpp
others = botao.cpp caminho.cpp caracol.cpp comida.cpp fila.cpp includes.cpp sal.cpp
output = ../bin/caracoisAladosFamintos
include_paths = -I../include
library_paths = -L../lib
compiler_flags = -w -g -Wl,-subsystem,windows
linker_flags = -lallegro-5.0.10-monolith-mt

ola: compile run

compile:
	$(compiler) $(std) $(main) $(others) $(include_paths) $(library_paths) $(compiler_flags) $(linker_flags) -o $(output)

run:
	./$(output)

clear:
	rm $(output)
