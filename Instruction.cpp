#include "pch.h"

CInstruction::CInstruction()
{
	Address = 0;
	Code = 0;
	m_nCycles = 0;
}

BOOL CInstruction::Create(AddrExec Adr, CodeExec Code, UINT Cycles)
{
	this->Address = Adr;
	this->Code = Code;
	this->m_nCycles =  Cycles;
	return 0;
}

