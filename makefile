#makefile for THE RETURN OF THE CAJUNS

all: board.o mosquito.o cajun.o driver.o
	gcc -o rotc board.o mosquito.o cajun.o driver.o

board.o: board.cpp
	gcc -c board.cpp

cajun.o: cajun.cpp
	gcc -c cajun.cpp

mosquito.o: mosquito.cpp
	gcc -c mosquito.cpp

driver.o: driver.cpp
	gcc -c driver.cpp

clean:
	rm *.o

