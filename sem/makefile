all: semtest sem

semtest: semtest.o
	g++ semtest.o -o semtest
sem: semaphore.o
	g++ semaphore.o -o sem
semtest.o: semtest.cpp
	g++ -c semtest.cpp
semaphore.o: semaphore.cpp
	g++ -c semaphore.cpp
clean:
	rm *.o sem semtest