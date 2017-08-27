CC=g++
CFLAGS=-Wl,-Bstatic -lboost_system -Wl,-Bdynamic -lpthread
CVER=-std=c++1y

main:
	g++ test.cpp $(CVER) $(CFLAGS) -o house20.out
