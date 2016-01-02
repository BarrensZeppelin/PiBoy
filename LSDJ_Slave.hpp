#include "GBSlave.hpp"

class LSDJ_Slave : public GBSlave {
	const uint8_t BEATS_PER_ROW = 16; // assumption

	uint8_t startRow = 0;
	uint8_t dataCapture = 0;
	uint8_t midiData = 0;
	
	public:
		LSDJ_Slave(GBLink & link, PinData pinData);

		void handleStatusByte(uint8_t b) override;
		void handleDataByte(uint8_t b) override;
};
