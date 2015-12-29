#include "LSDJ_Slave.hpp"
#include <wiringPi.h>
#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>

#include "GBLink.hpp"

LSDJ_Slave::LSDJ_Slave(SerialMIDI& serial, GBLink& link, PinData pinData) : Mode(serial, link, pinData) {
	data[0] = 0, data[1] = 0;
	dataCapture = false;
	link.initSlave(pinData);
}

void LSDJ_Slave::handleStatusByte(uint8_t b) {
	switch(b) {
		case 0xF8: // Clock message
			//cout << "clock" << endl;
			if(isStarted())
				gblink.sendClock(pinData);
			break;

		case 0xFA: // start
		case 0xFB: // continue
			//cout << "start/continue" << endl;
			if(data[0] != 0)
				gblink.sendByte(data[0], pinData);
			start();
			break;

		case 0xFC: // stop
			//cout << "stop" << endl;
			stop();
			break;

		default:
			{
				uint8_t hi = b >> 4;
				uint8_t lo = b % 0x10;
				
				if(hi == 8)
					dataCapture = false;
				else if(hi == 9)
					dataCapture = true, data[0] = 0;
				else
					cout << "status: " << std::bitset<8>(b) << endl;
			}
			break;
	}
}

void LSDJ_Slave::handleDataByte(uint8_t b) {
	if(dataCapture) {
		if(data[0] == 0) 
			data[0] = b;
		else {
			data[0] = 0;
		}
	}
	std::cout << "data: " << std::bitset<8>(b) << std::endl; 	
}


void LSDJ_Slave::tick() {
	// do nothing
}



