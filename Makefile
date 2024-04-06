CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -O2

md: md.cpp
	$(CXX) $(CXXFLAGS) -o md md.cpp
clean: md
	rm -f md