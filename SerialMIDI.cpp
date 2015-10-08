#include "SerialMIDI.hpp"
#include <iostream>

const int SerialMIDI::baudrate = 38400;
const string SerialMIDI::device = "/dev/ttyAMA0";

SerialMIDI::SerialMIDI() {
	if((ser = serialOpen(device.c_str(), baudrate)) == -1)
		std::cerr << "Couldn't open serial port" << std::endl;
}

SerialMIDI::~SerialMIDI() {
	serialClose(ser);
}

void SerialMIDI::sendByte(uint8_t b) {
	serialPutchar(ser, b);
}