CC=g++
CFLAGS=-g -Wall
CLINKS=-static-libstdc++ -Wl,-Bstatic -lboost_system -Wl,-Bdynamic -lpthread
CVER=-std=c++1y

main:
	g++ $(CFLAGS) main.cpp $(CVER) $(CLINKS) -o house20.out
