clean:
	rm ./pboy

all:
	g++ -std=c++11 -lwiringPi *.cpp -o pboy

run: all
	./pboy
