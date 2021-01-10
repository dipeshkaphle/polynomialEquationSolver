all: main

CC=g++
CFLAGS=-std=c++2a -Wall
EXECUTABLE=main
OBJS=Equation.o main.o
HEADERS=Equation.h

$(EXECUTABLE): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean :
	rm *.o
