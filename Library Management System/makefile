RunCode: main.o Librarian.o Member.o Person.o Book.o
	g++ main.o Librarian.o Member.o Person.o Book.o -o RunCode

main.o: main.cpp
	g++ -c main.cpp

Librarian.o: Librarian.cpp Librarian.h
	g++ -c Librarian.cpp

Member.o: Member.cpp Member.h
	g++ -c Member.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

clean:
	rm *.o RunCode