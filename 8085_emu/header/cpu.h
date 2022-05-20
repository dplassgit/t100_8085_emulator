#pragma once

#include "memory.h"
#include "stack.h"
#include "register.h"

#define SIGN_FLAG 7
#define ZERO_FLAG 6
#define AUX_CARRY_FLAG 4
#define PARITY_FLAG 2
#define CARRY_FLAG 0

#define CLOCKSPEED 1

class CPU
{
private:
	int _HangingCycles;
	bool _Running;

	const double _TimeBetweenClockCycles = 1.0 / CLOCKSPEED;
	std::chrono::steady_clock::time_point _PrevClockTime;

public:
	static CPU* cpu;

	Memory* _Memory;
	Stack* _Stack;

	Register8* A;
	Register8* B;
	Register8* C;
	Register8* D;
	Register8* E;
	Register8* H;
	Register8* L;

	Register8* Flags;

	Register* PC;
	Register* SP;

	CPU();

	void Loop();

	void Clock();
};