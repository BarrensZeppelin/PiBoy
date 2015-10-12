#include "LSDJ_Slave.hpp"
#include <wiringPi.h>
#include <iostream>
#include <string>

LSDJ_Slave::LSDJ_Slave(SerialMIDI& serial) : Mode(serial) {}

void LSDJ_Slave::tick() {
	std::string s;
	std::cin >> s;

	std::cout << "Sending: " << s << std::endl;
	serial.sendString(s);

	delay(10);

	string r = serial.readString();
	std::cout << "Read: " << r << std::endl;
}
