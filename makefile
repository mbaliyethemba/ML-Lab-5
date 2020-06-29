CFLAGS = -O
CC = g++

driver: driver.o
	$(CC) $(CFLAGS) -o driver driver.o grid.o state.o --std=c++11

driver.o: grid.o driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

grid.o: state.o grid.h grid.cpp
	$(CC) $(CFLAGS) -c grid.cpp --std=c++11

state.o: state.h state.cpp
	$(CC) $(CFLAGS) -c state.cpp --std=c++11

run:
	./driver

clean:
	rm -f core *.o
