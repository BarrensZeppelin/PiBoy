
CXXFLAGS = -std=c++11 -Wall -lwiringPi
CXX = g++

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

EXEC = pboy

all: $(OBJECTS)
	g++ -lwiringPi $^ -o $(EXEC)

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	rm ./pboy

run: all
	./pboy


CC_FLAGS += -MMD
-include $(OBJECTS:.o=.d)
