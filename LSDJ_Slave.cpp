#include "LSDJ_Slave.hpp"
#include <wiringPi.h>
#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>

#include "GBLink.hpp"
#include "MIDIMessages.hpp"

LSDJ_Slave::LSDJ_Slave(SerialMIDI& serial, GBLink& link, PinData pinData) : Mode(serial, link, pinData) {
	link.initSlave(pinData);
}

void LSDJ_Slave::handleStatusByte(uint8_t b) {
	switch(b) {
		case MIDI::CLOCK: // Clock message
			//cout << "clock" << endl;
			if(isStarted()) {
				gblink.sendClock(pinData);
			}
			break;

		case MIDI::START: // start
		case MIDI::CONTINUE: // continue
			//cout << "start/continue" << endl;
			cout << "StartRow: " << (int)startRow << endl;
			gblink.sendByte(startRow, pinData);
			start();
			break;

		case MIDI::STOP: // stop
			//cout << "stop" << endl;
			stop();
			break;

		case MIDI::SONGPOSPTR: // song position ptr
			dataCapture = true;
			break;

		default:
			{
				/*uint8_t hi = b >> 4;
				uint8_t lo = b % 0x10;
				
				if(hi == 8)
					dataCapture = false;
				else if(hi == 9)
					dataCapture = true, startRow = 0;
				else*/
					cout << "status: " << std::bitset<8>(b) << endl;
			}
			break;
	}
}

void LSDJ_Slave::handleDataByte(uint8_t b) {
	if(dataCapture) {
		if(midiData == 0)
			midiData = b;
		else {
			uint16_t position = (midiData << 8) + b; // combine MSB & LSB
			startRow = position / BEATS_PER_ROW; // assuming LSDJ uses 16 beats/row

			midiData = 0;
			dataCapture = false;
		}
	} else
		std::cout << "data: " << std::bitset<8>(b) << std::endl; 	
}


void LSDJ_Slave::tick() {
	// do nothing
}



