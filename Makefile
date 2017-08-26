main:
	g++ -std=c++1y -lboost_system -lpthread test.cpp

info:
	g++ --version
	dpkg -s libboost-all-dev
