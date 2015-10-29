#include "PiBoy.hpp"
#include "Mode.hpp"
#include "LSDJ_Slave.hpp"

PiBoy::PiBoy() {
	wiringPiSetup();
	
	mode = new LSDJ_Slave(serial, gblink);
}

PiBoy::~PiBoy() {
	mode->stop();
	delete mode;
}

int PiBoy::run() {
	
	while(mode->isStarted())
		mode->tick();
	
	return 0;
}
