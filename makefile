# Original template given from lecture notes 


test: main.o Menu.o Database.o Book.o 
	g++ -o test main.o Menu.o Database.o Book.o 

# only need to link if main.cpp has changed (included other files just to be sure)
main: main.cpp 
	g++ -c main.cpp

# only compile if Book.h or Book.cpp has changed since last compile
Book: Book.h Book.cpp
	g++ -c Book.cpp


# only compile if Database.h or Database.cpp has changed since last compile
Database: Database.h Database.cpp
	g++ -c Database.cpp

# only compile if Menu.h or Menu.cpp has changed since last compile
Menu: Menu.h Menu.cpp
	g++ -c Student.cpp



clean:
	rm -f test Main.o Menu.o Database.o Book.o

# Set the C++ compiler options:
#   -std=c++14 compiles using the C++14 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
