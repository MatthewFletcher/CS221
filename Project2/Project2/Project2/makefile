# target: dependencies
# 	action

#Create output file named output
output: main.o Student.o HogwartsSWW.o House.o
	g++ main.o Student.o -o output


main.o: main.cpp
	g++ -c main.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

House.o: House.cpp House.h
	g++ -c House.cpp

HogwartsSWW.o: HogwartsSWW.cpp HogwartsSWW.h
	g++ -c HogwartsSWW.cpp

clean:
	rm *.o
