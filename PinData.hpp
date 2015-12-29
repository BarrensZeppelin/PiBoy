#pragma once
#include <cstdint>

struct PinData {
	uint8_t write, clock, read;

	PinData(uint8_t w, uint8_t c, uint8_t r);
};