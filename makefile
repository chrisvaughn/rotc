#makefile for THE RETURN OF THE CAJUNS

all: board.o mosquito.o cajun.o driver.o
	g++ -o rotc board.o mosquito.o cajun.o driver.o

board.o: board.cpp
	g++ -c board.cpp

cajun.o: cajun.cpp
	g++ -c cajun.cpp

mosquito.o: mosquito.cpp
	g++ -c mosquito.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o

