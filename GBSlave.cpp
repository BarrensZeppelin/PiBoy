#include "GBSlave.hpp"
#include "GBLink.hpp"

GBSlave::GBSlave(GBLink &gb, PinData data) : gblink(gb), pinData(data) {}