#include "cpu65816.h"
#include "Bus.h"
#include <cstdint>

cpu65816::cpu65816()
{

}

cpu65816::~cpu65816()
{

}

uint16_t cpu65816::read(uint32_t addr)
{
	return bus->cpuRead(addr, false);
}

void cpu65816::write(uint32_t addr, uint16_t data)
{
	bus->cpuWrite(addr, data);
}

uint8_t cpu65816::GetFlag(cpuFLAGS f)
{
	return ((P & f) > 0) ? 1 : 0;
}

void cpu65816::SetFlag(cpuFLAGS f, bool v)
{
	if (v)
		P |= f;
	else
		P &= ~f;
}