#pragma once
#include <cstdint>

class Bus;

class cpu65816
{
public:
	cpu65816();
	~cpu65816();

public:
	// 65C816 Flags
	enum cpuFLAGS
	{
		c = (1 << 0),	// Carry : 0 when no arithmetic carry, 1 when result include arithmetic carry
		z = (1 << 1),	// Zero : 0 when result is non-zero, 1 when zero
		i = (1 << 2),	// Interrup Disable : when 0, interrupts enabled, else disabled
		d = (1 << 3),	// Decimal : when 0, ADC and SBC do binary arithmetic, else BCD arithmetic
		b = (1 << 4),	// Break : Only used if in emulation mode
		x = (1 << 4),	// Index Reg Width : same as m flag, except when 1, XH and YH are forced $00
		m = (1 << 5),	// Memory + Acc width : when 0, width is 16 bits, when 1 width is 8 bits
		v = (1 << 6),	// Overflow : 1 when arithmetic overflow occurs
		n = (1 << 7),	// Negative : 0 when the high bit is 0, 1 when high bit is 1
		e = (1 << 0),	// Emulation Mode : Accessed via c flag using XCE instruction; when 1, SH forced $01, m and x flags forced 1
	};

	// Connect to Bus
	void ConnectBus(Bus* n) { bus = n; }

	// Core Registers
	uint16_t A = 0x00;		// Accumulator (B = lower 8 bits, C = upper 8 bits)
	uint8_t DBR = 0x00;		// Data Bank Register
	uint16_t D = 0x00;		// Direct Register (DL = lower 8 bits, DH = upper 8 bits)
	uint8_t K = 0x00;		// Program Bank Register
	uint16_t PC = 0x00;		// Program Counter (PCL = lower 8 bits, PCH = upper 8 bits)
	uint8_t P = 0x00;		// Processer Status
	uint16_t stkp = 0x00;	// Stack pointer (SL = lower 8 bits, SH = upper 8 bits)
	uint16_t X = 0x00;		// X Register (XL = lower 8 bits, YH = upper 8 bits)
	uint16_t Y = 0x00;		// Y Register (YL = lower 8 bits, YH = upper 8 bits)

private:
	Bus* bus = nullptr;
	// Read and Write Functions
	uint16_t read(uint32_t addr);
	void write(uint32_t addr, uint16_t data);

	// Access Status Register
	uint8_t GetFlag(cpuFLAGS f);
	void SetFlag(cpuFLAGS f, bool v);
};