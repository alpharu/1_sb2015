CFLAGS = -std=c++11 -O2 
INCLUDE = funk_montador.o funk_ligador.o
# make montador
# make ligador 

montador: montadorComp
	rm -f *.o
ligador: ligadorComp
	rm -f *.o

montadorComp: $(INCLUDE) montador.o
	g++ $(CFLAG) $(INCLUDE) montador.o -o montador
ligadorComp: $(INCLUDE) ligador.o
	g++ $(CFLAG) $(INCLUDE) ligador.o -o ligador


funk_montador.o: lib/funk_montador.cpp
	g++ -c $(CFLAGS) lib/funk_montador.cpp
funk_ligador.o: lib/funk_ligador.cpp
	g++ -c $(CFLAGS) lib/funk_ligador.cpp
montador.o: montador.cpp
	g++ -c $(CFLAGS) montador.cpp
ligador.o: ligador.cpp
	g++ -c $(CFLAGS) ligador.cpp

