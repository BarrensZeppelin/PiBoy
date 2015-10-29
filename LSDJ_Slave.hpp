#include "Mode.hpp"
#include "SerialMIDI.hpp"

class LSDJ_Slave : public Mode {
	uint8_t data[2];
	bool dataCapture;

	private:
		void handleStatusByte(uint8_t b);
		void handleDataByte(uint8_t b);
	
	public:
		LSDJ_Slave(SerialMIDI& serial, GBLink& gblink);

		void tick();
};
