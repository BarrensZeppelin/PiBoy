#include "DebugSlave.hpp"
#include "MIDIMessages.hpp"

#include <bitset>
#include <iostream>

uint8_t getChannelFromByte(uint8_t byte) {
	return byte & 0xF;
}

void DebugSlave::handleStatusByte(uint8_t byte) {
	if(byte & 0xF0 == 0xF0) { // system message
		// neglect clock
		if(byte == MIDI::CLOCK)
			return;
		
		std::cout << "System: ";

		switch(byte) {
		case MIDI::CONTINUE:
			std::cout << "Continue" << std::endl;
			break;
		
		case MIDI::START:
			std::cout << "Start" << std::endl;
			break;

		case MIDI::STOP:
			std::cout << "Stop" << std::endl;
			break;

		case MIDI::SONGPOSPTR:
			std::cout << "Song position pointer ";
			remainingData = 2;
			break;
		
		default:
			std::cout << "Other status: " << std::bitset<8>(byte) << std::endl;
			break;
		}
	} else { // channel message
		std::cout << "CH " << (int)getChannelFromByte(byte) << " ";

		switch(byte & 0xF0) {
		case MIDI::NOTEON:
			std::cout << "Note on: ";
			remainingData = 2;
			break;

		case MIDI::NOTEOFF:
			std::cout << "Note off: ";
			remainingData = 2;
			break;

		case MIDI::CONTROLCHANGE:
			std::cout << "Control change: ";
			remainingData = 2;
			break;
		}
	}
}

void DebugSlave::handleDataByte(uint8_t byte) {
	if(remainingData == 1) {
		std::cout << (int)byte << std::endl;
	} else if(remainingData > 1) {
		std::cout << (int)byte << " ";
		remainingData--;
	}
}