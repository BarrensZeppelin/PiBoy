#pragma once
#include <cstdint>

class Slave {
public:
	virtual void handleStatusByte(uint8_t b) = 0;
	virtual void handleDataByte(uint8_t b) = 0;
	
	virtual void tick() {};
	
	virtual ~Slave() {}
};
