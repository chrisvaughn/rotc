#makefile for THE RETURN OF THE CAJUNS

TheReturn: board.o mosquito.o cajun.o driver.o
           CC -o TheReturn board.o mosquito.o cajun.o driver.o

board.o: board.cpp
         CC -c board.cpp

cajun.o: cajun.cpp
         CC -c cajun.cpp

mosquito.o: mosquito.cpp
            CC -c mosquito.cpp

driver.o: driver.cpp
          CC -c driver.cpp

