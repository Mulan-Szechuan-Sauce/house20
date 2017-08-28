CC=g++
CFLAGS=-g -Wall
CLINKS=-static-libstdc++ -Wl,-Bstatic -lboost_system -Wl,-Bdynamic -lpthread
CVER=-std=c++1y

main:
	g++ $(CFLAGS) test.cpp $(CVER) $(CLINKS) -o house20.out
