CC = g++
CFLAGS = -std=c++11

all: main.o CmdManager.o Course.o CourseManager.o
	$(CC) $(CFLAGS) main.o CmdManager.o Course.o CourseManager.o -o cmsys
	

main.o: main.cpp
	$(CC) $(CFLAG) -c main.cpp

CmdManager.o: CmdManager.cpp CmdManager.h
	$(CC) $(CFLAG) -c CmdManager.cpp

CourseManager.o: CourseManager.cpp CourseManager.h
	$(CC) $(CFLAG) -c CourseManager.cpp

Course.o: Course.cpp Course.h
	$(CC) $(CFLAG) -c Course.cpp

clean:
	rm *.o cmsys
