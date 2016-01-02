#include "LSDJ_Slave.hpp"
#include <iostream>

#include "GBLink.hpp"
#include "MIDIMessages.hpp"

LSDJ_Slave::LSDJ_Slave(GBLink& link, PinData pinData) : GBSlave(link, pinData) {
	link.initSlave(pinData);
}

void LSDJ_Slave::handleStatusByte(uint8_t b) {
	switch(b) {
		case MIDI::CLOCK: // Clock message
			gblink.sendClock(pinData);
			break;

		case MIDI::START: // start
		case MIDI::CONTINUE: // continue
			std::cout << "StartRow: " << (int)startRow << std::endl;
			gblink.sendByte(startRow, pinData);
			break;

		case MIDI::STOP: // stop
			break;

		case MIDI::SONGPOSPTR: // song position ptr
			dataCapture = true;
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
	}
}

