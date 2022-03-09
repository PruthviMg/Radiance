exec = Game
sfml = -lsfml-graphics -lsfml-window -lsfml-system
headers = -I/usr/include -Iinc/
sources = ${wildcard src/*.cpp}
objects = ${sources:.cpp=.o}

all: test.o ${objects}
	g++  test.o ${objects} -o ${exec} ${sfml}

%.o: src/*.cpp
	g++ -c ${headers} $< -o $@

test.o: test.cpp 
	g++ -c test.cpp ${headers} 

clean:
	-rm *.o 
	-rm src/*.o