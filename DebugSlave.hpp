#pragma once
#include "Mode.hpp"
#include <cstdint>

class DebugSlave : public Mode {
	uint8_t data = 0;
    uint8_t remainingData = 0;
    uint8_t status = 0;
    uint8_t channel = 0;

public:
	void handleStatusByte(uint8_t byte) override;
	void handleDataByte(uint8_t byte) override;
};