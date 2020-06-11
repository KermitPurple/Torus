all: main.o Coord.o Torus.o
	g++ bin/*.o -o bin/test.exe -I include -lopenGL32 -l freeGLUT
	@echo

main.o: src/main.cpp
	g++ src/main.cpp -c -o bin/main.o -I include -lopenGL32 -l freeGLUT

Coord.o: src/Coord.cpp
	g++ src/Coord.cpp -c -o bin/Coord.o -I include -lopenGL32 -l freeGLUT

Torus.o: src/Torus.cpp
	g++ src/Torus.cpp -c -o bin/Torus.o -I include -lopenGL32 -l freeGLUT

clean:
	rm bin/*

new:
	mkdir bin

test: all
	bin/test.exe
