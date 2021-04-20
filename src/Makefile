CPP = g++
CPPFLAGS = -std=c++17 -Wall
PROGRAM = martist
AR=ar

# Files
MODULES_MARTIST=Expression.cpp ExpressionTree.cpp Martist.cpp Image.cpp main.cpp
OBJECTS_MARTIST=Expression.o ExpressionTree.o Martist.o Image.o main.o
EXEC_ALL=martist

$(PROGRAM): $(OBJECTS_MARTIST)
	$(CPP) -o $(PROGRAM) $(OBJECTS_MARTIST)


Expression.o: Expression.cpp 
	$(CPP) -c Expression.cpp -o Expression.o $(CFLAGS)

ExpressionTree.o: ExpressionTree.cpp
	$(CPP) -c ExpressionTree.cpp -o ExpressionTree.o $(CFLAGS)

Martist.o: Martist.cpp
	$(CPP) -c Martist.cpp -o Martist.o $(CFLAGS)

Image.o: Image.cpp 
	$(CPP) -c Image.cpp -o Image.o $(CFLAGS)

main.o: main.cpp 	
	$(CPP) -c main.cpp -o main.o $(CFLAGS)

all: $(EXEC)

clean:
	rm -f *.o $(EXEC_ALL)