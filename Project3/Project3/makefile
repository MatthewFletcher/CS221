# target: dependencies
# 	action

#Create output file named output
output: main.o Book.o Library.o
	g++ main.o Book.o Library.o -o output


main.o: main.cpp
	g++ -c main.cpp


Book.o: Book.cpp Book.h
	g++ -c Book.cpp

Library.o: Library.cpp Library.h
	g++ -c Library.cpp

clean:
	rm *.o
