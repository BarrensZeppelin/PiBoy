#include "Mode.hpp"
#include "SerialMIDI.hpp"

class LSDJ_Slave : public Mode {
	const uint8_t BEATS_PER_ROW = 16; // assumption

	uint8_t startRow = 0;
	bool dataCapture = false;
	uint8_t midiData = 0;
	
	public:
		LSDJ_Slave(SerialMIDI & serial, GBLink & link, PinData pinData);

		void handleStatusByte(uint8_t b);
		void handleDataByte(uint8_t b);
		void tick();
};
