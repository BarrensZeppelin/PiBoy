#include "LSDJ_Slave.hpp"
#include <wiringPi.h>
#include <iostream>
#include <string>

#include "GBLink.hpp"

LSDJ_Slave::LSDJ_Slave(SerialMIDI& serial, GBLink& link) : Mode(serial, link) {
	
}

void LSDJ_Slave::handleStatusByte(uint8_t b) {
	
	std::cout << "Received status byte: " << b << std::endl;
	switch(b) {
		case 0xF8: // Clock message
			if(isStarted())
				gblink.sendClock();
			break;

		case 0xFA: // start
		case 0xFB: // continue
			start();
			break;

		case 0xFC: // stop
			stop();
			break;

		default:
			// note on
			break;
	}
}

void LSDJ_Slave::handleDataByte(uint8_t b) {
	std::cout << "Received data byte: " << b << std::endl; 	
}


void LSDJ_Slave::tick() {
	/*std::string s;
	std::cin >> s;

	std::cout << "Sending: " << s << std::endl;
	serial.sendString(s);

	delay(10);

	string r = serial.readString();
	std::cout << "Read: " << r << std::endl;
	*/

	if(serial.dataAvailable()) {
		uint8_t b = serial.readByte();

		if(b & 0x80)
			handleStatusByte(b);
		else
			handleDataByte(b);
	}
}



