#include "PiBoy.hpp"
#include "Mode.hpp"
#include "LSDJ_Slave.hpp"

PiBoy::PiBoy()
: started(false) {
	mode = new LSDJ_Slave();
}

int PiBoy::run() {
	
	while(true)
		mode->tick();
	
	return 0;
}