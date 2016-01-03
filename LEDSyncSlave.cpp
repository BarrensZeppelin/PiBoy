#include "LEDSyncSlave.hpp"
#include <wiringPi.h>
#include "MIDIMessages.hpp"

LEDSyncSlave::LEDSyncSlave(uint8_t ledPin) : pin(ledPin) {
	pinMode(pin, OUTPUT);

	digitalWrite(pin, LOW);
}


void LEDSyncSlave::handleStatusByte(uint8_t byte) {
	switch(byte) {
	case MIDI::STOP:
		clocks = 0;
		digitalWrite(pin, LOW);
		break;

	case MIDI::CLOCK:
		if(clocks == 0)
			digitalWrite(pin, HIGH);
		else if(clocks == pCountLow)
			digitalWrite(pin, LOW);
		
		clocks = (clocks + 1) % ppqn;
		break;
	}
}

void LEDSyncSlave::handleDataByte(uint8_t byte) {}
