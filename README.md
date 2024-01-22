# CST2550-Library-Management-System
Coursework: 1 Library Management System

2023-24 CST2550 Software Engineering Management and Development
Created/Coded By Arbaaz Ali Hussain M00872279.

Within this repository it contains the files for CST2550 Coursework 1 created in c++, this is a library management system which is a program for tracking members and books whih have been utilised in the program.

Please make sure that the  .csv files & makefile remains in the library management system directory.

# Terminal commands.

make - Compiles the files and makes .exe executables for testing and the library management system.

make clean - Cleans and removes the repository of .o files and .exe files.

./tests.exe or ./tests  - Runs the catch 2 testing within the terminal. See src/tests.cpp for catch 2 testing code.

.RunCode - Runs the Library Management System program within the terminal.

Command for terminal testing compiler : 
g++ testCase.cpp Librarian.o Member.o Person.o Book.o -o tests



# makeFile for Windows:

CXXFLAGS = -Wall -Wextra -Wpedantic

all: RunCode

RunCode: main.o Librarian.o Member.o Person.o Book.o
    g++ main.o Librarian.o Member.o Person.o Book.o -o RunCode

main.o: main.cpp
    g++ $(CXXFLAGS) -c main.cpp -o main.o
   
Librarian.o: Librarian.cpp Librarian.h
    g++ $(CXXFLAGS) -c Librarian.cpp -o Librarian.o

Member.o: Member.cpp Member.h
    g++ $(CXXFLAGS) -c Member.cpp -o Member.o

Person.o: Person.cpp Person.h
    g++ $(CXXFLAGS) -c Person.cpp -o Person.o

Book.o: Book.cpp Book.h
    g++ $(CXXFLAGS) -c Book.cpp -o Book.o

.PHONY: clean
clean:
    $(RM) *.o RunCode



# makefile for macOS:.

CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++11
LDFLAGS = -stdlib=libc++

all: RunCode

RunCode: main.o Librarian.o Member.o Person.o Book.o
    g++ $(LDFLAGS) main.o Librarian.o Member.o Person.o Book.o -o RunCode

main.o: main.cpp
    g++ $(CXXFLAGS) -c main.cpp -o main.o

Librarian.o: Librarian.cpp Librarian.h
    g++ $(CXXFLAGS) -c Librarian.cpp -o Librarian.o

Member.o: Member.cpp Member.h
    g++ $(CXXFLAGS) -c Member.cpp -o Member.o

Person.o: Person.cpp Person.h
    g++ $(CXXFLAGS) -c Person.cpp -o Person.o

Book.o: Book.cpp Book.h
    g++ $(CXXFLAGS) -c Book.cpp -o Book.o

.PHONY: clean
clean:
    $(RM) *.o RunCode




