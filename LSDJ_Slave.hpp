#include "Mode.hpp"
#include "SerialMIDI.hpp"

class LSDJ_Slave : public Mode {
	public:
		LSDJ_Slave(SerialMIDI& serial);

		void tick();
};
