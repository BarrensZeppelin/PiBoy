all:
	g++ -std=c++11 -lwiringPi *.cpp -o piboy

run: all
	./piboy