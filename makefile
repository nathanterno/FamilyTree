FamilyTree:
	g++ -g -std=c++11 Individual.cpp Family.cpp Database.cpp Node.cpp Queue.cpp main.cpp -o FamilyTree

CXXFLAGS = -Wall

OBJECTS = Individual.o Family.o Database.o Node.o Queue.o main.o
	  #(listing all of your object files here, separated by space)
HEADERS = Individual.h Family.h Database.h Node.h Queue.h
	  #(listing all header files here, separated by spaces)

FamilyTree: $(OBJECTS)
	g++ -g -std=c++11 $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -g -std=c++11 -c $< -o $@

clean:
	rm -i *.o FamilyTree