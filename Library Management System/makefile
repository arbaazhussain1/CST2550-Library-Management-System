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
