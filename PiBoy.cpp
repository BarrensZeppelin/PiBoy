#include "PiBoy.hpp"
#include "Mode.hpp"
#include "LSDJ_Slave.hpp"

PiBoy::PiBoy() {
	wiringPiSetup();
	
	// test
	modes.push_back(new LSDJ_Slave(serial, gblink, {0, 1, 2}));
}

PiBoy::~PiBoy() {
	for(Mode* mode : modes) {
		mode->stop();
		delete mode;
	}
}

int PiBoy::run() {
	
	while(true) {
		if(serial.dataAvailable()) {
			uint8_t b = serial.readByte();

			if(b & 0x80) {
				for(Mode* mode : modes)
					mode->handleStatusByte(b);
			} else {
				for(Mode* mode : modes)
					mode->handleDataByte(b);
			}
		
			for(Mode* mode : modes)
				mode->tick();
		}
	}
	
	return 0;
}
