CXX ?= g++
CXXFLAGS ?= -O2 -std=c++17 -pipe -static -s

all: code

code: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f code *.o
