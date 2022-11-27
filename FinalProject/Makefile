#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and stu_sort.o to executable main
main: main.o student.o stu_sort.o toeflscore.o list.o
	g++ -g -o main main.o student.o stu_sort.o toeflscore.o list.o

#compile the main.cpp to main.o
main.o: main.cpp student.hpp stu_sort.hpp toeflscore.hpp list.hpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp student.hpp
	g++ -g -c student.cpp

#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp stu_sort.hpp
	g++ -g -c stu_sort.cpp

# compile toeflscore
toeflscore.o: toeflscore.cpp toeflscore.hpp
	g++ -g -c toeflscore.cpp

list.o: list.cpp list.hpp
	g++ -g -c list.cpp

#remove built files
clean:
	rm -rf main main.o student.o stu_sort.o toeflscore.o list.o *~
