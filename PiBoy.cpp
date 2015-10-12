#include "PiBoy.hpp"
#include "Mode.hpp"
#include "LSDJ_Slave.hpp"

PiBoy::PiBoy()
: started(false) {
	wiringPiSetup();
	
	mode = new LSDJ_Slave(serial);
}

int PiBoy::run() {
	
	while(true)
		mode->tick();
	
	return 0;
}
