#include "PiBoy.hpp"
#include "Slave.hpp"
#include "LSDJ_Slave.hpp"
#include "DebugSlave.hpp"
#include "LEDSyncSlave.hpp"

PiBoy::PiBoy() {
	wiringPiSetup();
	
	slaves.push_back(new LSDJ_Slave(gblink, {2, 1, 0}));
	
	// test
	slaves.push_back(new DebugSlave());
	slaves.push_back(new LEDSyncSlave(3));
}

PiBoy::~PiBoy() {
	for(Slave* slave : slaves) {
		delete slave;
	}
}

int PiBoy::run() {
	
	while(true) {
		if(serial.dataAvailable()) {
			uint8_t b = serial.readByte();

			if(b & 0x80) {
				for(Slave* slave : slaves)
					slave->handleStatusByte(b);
			} else {
				for(Slave* slave : slaves)
					slave->handleDataByte(b);
			}
		
			for(Slave* slave : slaves)
				slave->tick();
		}
	}
	
	return 0;
}
