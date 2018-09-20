# target: dependencies
# 	action

#Create output file named output
output: main.o Student.o
	g++ main.o Student.o -o output


main.o: main.cpp
	g++ -c main.cpp # -c says don't make an executable, just a .o file


Student.o: Student.cpp Student.h
	g++ -c Student.cpp

clean:
	rm *.o output
