#include <wiringPi.h>
#include "SerialMIDI.hpp"
#include "GBLink.hpp"
#include <vector>

class Slave;

class PiBoy {
	private:
		std::vector<Slave*> slaves;
	
		SerialMIDI serial;
		GBLink gblink;

	public:
		PiBoy();
		~PiBoy();

		int run();
};
