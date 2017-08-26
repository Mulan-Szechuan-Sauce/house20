main:
	g++ --version
	g++ -std=c++1y -D_GLIBCXX_USE_CXX11_ABI=0 -lboost_system -lpthread test.cpp
