#pragma once
#include "Slave.hpp"

class LEDSyncSlave : public Slave {
	const uint8_t ppqn = 24;
	const uint8_t pCountLow = 10;

	uint8_t pin;
	uint8_t clocks = 0;

public:
	LEDSyncSlave(uint8_t ledPin);

	void handleStatusByte(uint8_t byte) override;
	void handleDataByte(uint8_t byte) override;
};
