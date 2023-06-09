OBJECTS = BSTree.o Node.o
CXXFLAGS = -g

all: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS)

main: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -o tests tests.o $(OBJECTS)
BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

tests.o: tests.cpp doctest.h
clean:
	rm -f main tests *.o
