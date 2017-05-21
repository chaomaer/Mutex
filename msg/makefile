all: receive send
receive: receive.o
	g++ receive.o -o receive
receive.o: msgreceive.cpp
	g++ -c msgreceive.cpp -o receive.o
send: send.o
	g++ send.o -o send
send.o: msgsend.cpp
	g++ -c msgsend.cpp -o send.o

clean:
	rm *.o receive send