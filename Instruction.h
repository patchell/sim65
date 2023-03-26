#pragma once

class CSimulator;

typedef void (CSimulator::* CodeExec)(USHORT);
typedef USHORT(CSimulator::* AddrExec)();

class CInstruction
{
	AddrExec Address;
	CodeExec Code;
	UINT m_nCycles;
public:
	CInstruction();
	virtual ~CInstruction() {}
	BOOL Create(AddrExec Adress, CodeExec Code, UINT Cycles);
};


struct Instr
{
	AddrExec addr;
	CodeExec code;
	uint8_t cycles;
};
