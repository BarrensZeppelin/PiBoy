#include "SerialMIDI.hpp"
#include <iostream>

const int SerialMIDI::baudrate = 38400;
const string SerialMIDI::device = "/dev/ttyAMA0";

SerialMIDI::SerialMIDI() {
	if((ser = serialOpen(device.c_str(), baudrate)) == -1)
		std::cerr << "Couldn't open serial port" << std::endl;

	// clear input
	serialFlush(ser);
}

SerialMIDI::~SerialMIDI() {
	serialClose(ser);	
}


bool SerialMIDI::dataAvailable() {
	return (bool)serialDataAvail(ser);
}

void SerialMIDI::sendByte(uint8_t b) {
	serialPutchar(ser, b);
}

void SerialMIDI::sendString(string s) {
	serialPuts(ser, s.c_str());
}


uint8_t SerialMIDI::readByte() {
	return (uint8_t)serialGetchar(ser);
}

string SerialMIDI::readString() {
	string s = "";
	int len = serialDataAvail(ser);
	
	while(!len)
		len = serialDataAvail(ser);


	while(len) {
		while(len--) {
			s += (char)serialGetchar(ser);
		}

		len = serialDataAvail(ser);
	}

	return s;
}
