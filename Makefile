CC=g++
CFLAGS=-lboost_system -lpthread
CVER=-std=c++1y

main:
	g++ test.cpp $(CVER) $(CFLAGS) -o house20.out
