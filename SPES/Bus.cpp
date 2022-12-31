#include "Bus.h"

Bus::Bus()
{
	// "Connect" cpu to bus
	cpu.ConnectBus(this);
}

Bus::~Bus()
{

}

uint16_t cpuRead(uint16_t data, bool readOnly = false)
{

}

void cpuWrite(uint32_t addr, uint16_t data)
{

}