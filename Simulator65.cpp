#include "pch.h"

CSimulator65::CSimulator65()
{
}

CSimulator65::~CSimulator65()
{
}

BOOL CSimulator65::Create()
{
	BOOL rV = TRUE;

	rV = CPeripheral::Create(CPeripheral::PeriphType::MOS6502);
	return rV;
}

//-------------------------------------------------
// Addressing Modes
//-------------------------------------------------

USHORT CSimulator65::Addr_ACC()
{
	return 0; // not used
}

USHORT CSimulator65::Addr_IMM()
{
	return m_PC++;
}

USHORT CSimulator65::Addr_ABS()
{
	USHORT addrL;
	USHORT addrH;
	USHORT addr;

	addrL = Read(m_PC++);
	addrH = Read(m_PC++);

	addr = addrL + (addrH << 8);

	return addr;
}

USHORT CSimulator65::Addr_ZER()
{
	return Read(m_PC++);
}

USHORT CSimulator65::Addr_ZEX()
{
	USHORT addr = (Read(m_PC++) + m_X) % 256;
	return addr;
}

USHORT CSimulator65::Addr_ZEY()
{
	USHORT addr = (Read(m_PC++) + m_Y) % 256;
	return addr;
}

USHORT CSimulator65::Addr_ABX()
{
	USHORT addr;
	USHORT addrL;
	USHORT addrH;

	addrL = Read(m_PC++);
	addrH = Read(m_PC++);

	addr = addrL + (addrH << 8) + m_X;
	return addr;
}

USHORT CSimulator65::Addr_ABY()
{
	USHORT addr;
	USHORT addrL;
	USHORT addrH;

	addrL = Read(m_PC++);
	addrH = Read(m_PC++);

	addr = addrL + (addrH << 8) + m_Y;
	return addr;
}

USHORT CSimulator65::Addr_IMP()
{
	return USHORT(0);	//Not Used
}

USHORT CSimulator65::Addr_REL()
{
	USHORT offset;
	USHORT addr;

	offset = (USHORT)Read(m_PC++);
	if (offset & 0x80) offset |= 0xFF00;
	addr = m_PC + (USHORT)offset;
	return addr;
}

USHORT CSimulator65::Addr_INX()
{
	USHORT zeroL;
	USHORT zeroH;
	USHORT addr;

	zeroL = (Read(m_PC++) + m_X) % 256;
	zeroH = (zeroL + 1) % 256;
	addr = Read(zeroL) + (Read(zeroH) << 8);

	return addr;
}

USHORT CSimulator65::Addr_INY()
{
	USHORT zeroL;
	USHORT zeroH;
	USHORT addr;

	zeroL = Read(pc++);
	zeroH = (zeroL + 1) % 256;
	addr = Read(zeroL) + (Read(zeroH) << 8) + m_Y;
	return addr;
}

USHORT CSimulator65::Addr_ABI()
{
	USHORT addrL;
	USHORT addrH;
	USHORT effL;
	USHORT effH;
	USHORT abs;
	USHORT addr;

	addrL = Read(m_PC++);
	addrH = Read(m_PC++);

	abs = (addrH << 8) | addrL;

	effL = Read(abs);

#ifndef CMOS_INDIRECT_JMP_FIX
	effH = Read((abs & 0xFF00) + ((abs + 1) & 0x00FF));
#else
	effH = Read(abs + 1);
#endif

	addr = effL + 0x100 * effH;

	return addr;
}

//-------------------------------------------------
// Opcodes
//-------------------------------------------------
void CSimulator65::Op_ADC(USHORT src)
{
}

void CSimulator65::Op_AND(USHORT src)
{
}

void CSimulator65::Op_ASL(USHORT src)
{
}

void CSimulator65::Op_ASL_ACC(USHORT src)
{
}

void CSimulator65::Op_BCC(USHORT src)
{
}

void CSimulator65::Op_BCS(USHORT src)
{
}

void CSimulator65::Op_BEQ(USHORT src)
{
}

void CSimulator65::Op_BIT(USHORT src)
{
}

void CSimulator65::Op_BMI(USHORT src)
{
}

void CSimulator65::Op_BNE(USHORT src)
{
}

void CSimulator65::Op_BPL(USHORT src)
{
}

void CSimulator65::Op_BRK(USHORT src)
{
}

void CSimulator65::Op_BVC(USHORT src)
{
}

void CSimulator65::Op_BVS(USHORT src)
{
}

void CSimulator65::Op_CLC(USHORT src)
{
}

void CSimulator65::Op_CLD(USHORT src)
{
}

void CSimulator65::Op_CLI(USHORT src)
{
}

void CSimulator65::Op_CLV(USHORT src)
{
}

void CSimulator65::Op_CMP(USHORT src)
{
}

void CSimulator65::Op_CPX(USHORT src)
{
}

void CSimulator65::Op_CPY(USHORT src)
{
}

void CSimulator65::Op_DEC(USHORT src)
{
}

void CSimulator65::Op_DEX(USHORT src)
{
}

void CSimulator65::Op_DEY(USHORT src)
{
}

void CSimulator65::Op_EOR(USHORT src)
{
}

void CSimulator65::Op_INC(USHORT src)
{
}

void CSimulator65::Op_INX(USHORT src)
{
}

void CSimulator65::Op_INY(USHORT src)
{
}

void CSimulator65::Op_JMP(USHORT src)
{
}

void CSimulator65::Op_JSR(USHORT src)
{
}

void CSimulator65::Op_LDA(USHORT src)
{
}

void CSimulator65::Op_LDX(USHORT src)
{
}

void CSimulator65::Op_LDY(USHORT src)
{
}

void CSimulator65::Op_LSR(USHORT src)
{
}

void CSimulator65::Op_LSR_ACC(USHORT src)
{
}

void CSimulator65::Op_NOP(USHORT src)
{
}

void CSimulator65::Op_ORA(USHORT src)
{
}

void CSimulator65::Op_PHA(USHORT src)
{
}

void CSimulator65::Op_PHP(USHORT src)
{
}

void CSimulator65::Op_PLA(USHORT src)
{
}

void CSimulator65::Op_PLP(USHORT src)
{
}

void CSimulator65::Op_ROL(USHORT src)
{
}

void CSimulator65::Op_ROL_ACC(USHORT src)
{
}

void CSimulator65::Op_ROR(USHORT src)
{
}

void CSimulator65::Op_ROR_ACC(USHORT src)
{
}

void CSimulator65::Op_RTI(USHORT src)
{
}

void CSimulator65::Op_RTS(USHORT src)
{
}

void CSimulator65::Op_SBC(USHORT src)
{
}

void CSimulator65::Op_SEC(USHORT src)
{
}

void CSimulator65::Op_SED(USHORT src)
{
}

void CSimulator65::Op_SEI(USHORT src)
{
}

void CSimulator65::Op_STA(USHORT src)
{
}

void CSimulator65::Op_STX(USHORT src)
{
}

void CSimulator65::Op_STY(USHORT src)
{
}

void CSimulator65::Op_TAX(USHORT src)
{
}

void CSimulator65::Op_TAY(USHORT src)
{
}

void CSimulator65::Op_TSX(USHORT src)
{
}

void CSimulator65::Op_TXA(USHORT src)
{
}

void CSimulator65::Op_TXS(USHORT src)
{
}

void CSimulator65::Op_TYA(USHORT src)
{
}

void CSimulator65::Op_ILLEGAL(USHORT src)
{
}
