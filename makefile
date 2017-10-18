all: list

list: main.o customer.o list.o
	g++ main.o customer.o list.o -o list 

main.o: main.cpp 
	g++ -c main.cpp 

customer.o: customer.cpp
	g++ -c customer.cpp 

list.o: list.cpp
	g++ -c list.cpp

clean:
	rm *.o list
