//-----------------------------------------------
// Sim65
// Based on the below project
//-----------------------------------------------
//============================================================================
// Name        : mos6502
// Author      : Gianluca Ghettini
// Version     : 1.0
// Copyright   :
// Description : A MOS 6502 CPU emulator written in C++
//============================================================================
#pragma once

typedef void (*BusWrite)(USHORT, uint8_t);
typedef uint8_t(*BusRead)(USHORT);


class CSimulator65: public CPeripheral
{
public:
	enum class SR {
		CARRY  =  0x01,
		ZERO = 0x02,
		INTERRUPT = 0x04,
		DECIMAL = 0x08,
		BREAK = 0x10,
		CONSTANT = 0x20,
		OVERFLOWING = 0x40,
		NEGATIVE = 0x80
	};
private:
	inline static UCHAR m_Rese_A = 0;
	inline static UCHAR m_Reset_X = 0;
	inline static UCHAR m_Reset_Y = 0;
	inline static UCHAR m_Reset_SP = 0xfd;
	inline static UCHAR m_Reset_SR = char(SR::CONSTANT);

	UCHAR m_A;	//accumulator
	UCHAR m_X;	//x index register
	UCHAR m_Y;	//Y index register
	UCHAR m_SP;	//Stack Pointer
	UCHAR m_SR;	// Status Register
	UCHAR m_PC;	// program counter

	BusWrite Write;
	BusRead Read;

	typedef void (CSimulator65::* CodeExec)(USHORT);
	typedef USHORT(CSimulator65::* AddrExec)();

	struct Instruction
	{
		AddrExec Addr;
		CodeExec Code;
		UCHAR Cycles;
		Instruction() {
			Addr = 0;
			Code = 0;
			Cycles = 0;
		}
	};
	inline static Instruction InstructionTable[256];

public:
	CSimulator65();
	virtual ~CSimulator65();
	BOOL Create();
	//------------------------
	// addressing modes
	//------------------------
	USHORT Addr_ACC(); // ACCUMULATOR
	USHORT Addr_IMM(); // IMMEDIATE
	USHORT Addr_ABS(); // ABSOLUTE
	USHORT Addr_ZER(); // ZERO PAGE
	USHORT Addr_ZEX(); // INDEXED-X ZERO PAGE
	USHORT Addr_ZEY(); // INDEXED-Y ZERO PAGE
	USHORT Addr_ABX(); // INDEXED-X ABSOLUTE
	USHORT Addr_ABY(); // INDEXED-Y ABSOLUTE
	USHORT Addr_IMP(); // IMPLIED
	USHORT Addr_REL(); // RELATIVE
	USHORT Addr_INX(); // INDEXED-X INDIRECT
	USHORT Addr_INY(); // INDEXED-Y INDIRECT
	USHORT Addr_ABI(); // ABSOLUTE INDIRECT
	//----------------------------------------
	// opcodes (grouped as per datasheet)
	//----------------------------------------
	void Op_ADC(USHORT src);
	void Op_AND(USHORT src);
	void Op_ASL(USHORT src); 	
	void Op_ASL_ACC(USHORT src);
	void Op_BCC(USHORT src);
	void Op_BCS(USHORT src);

	void Op_BEQ(USHORT src);
	void Op_BIT(USHORT src);
	void Op_BMI(USHORT src);
	void Op_BNE(USHORT src);
	void Op_BPL(USHORT src);

	void Op_BRK(USHORT src);
	void Op_BVC(USHORT src);
	void Op_BVS(USHORT src);
	void Op_CLC(USHORT src);
	void Op_CLD(USHORT src);

	void Op_CLI(USHORT src);
	void Op_CLV(USHORT src);
	void Op_CMP(USHORT src);
	void Op_CPX(USHORT src);
	void Op_CPY(USHORT src);

	void Op_DEC(USHORT src);
	void Op_DEX(USHORT src);
	void Op_DEY(USHORT src);
	void Op_EOR(USHORT src);
	void Op_INC(USHORT src);

	void Op_INX(USHORT src);
	void Op_INY(USHORT src);
	void Op_JMP(USHORT src);
	void Op_JSR(USHORT src);
	void Op_LDA(USHORT src);

	void Op_LDX(USHORT src);
	void Op_LDY(USHORT src);
	void Op_LSR(USHORT src); 	
	void Op_LSR_ACC(USHORT src);
	void Op_NOP(USHORT src);
	void Op_ORA(USHORT src);

	void Op_PHA(USHORT src);
	void Op_PHP(USHORT src);
	void Op_PLA(USHORT src);
	void Op_PLP(USHORT src);
	void Op_ROL(USHORT src); 	
	void Op_ROL_ACC(USHORT src);

	void Op_ROR(USHORT src);	
	void Op_ROR_ACC(USHORT src);
	void Op_RTI(USHORT src);
	void Op_RTS(USHORT src);
	void Op_SBC(USHORT src);
	void Op_SEC(USHORT src);
	void Op_SED(USHORT src);

	void Op_SEI(USHORT src);
	void Op_STA(USHORT src);
	void Op_STX(USHORT src);
	void Op_STY(USHORT src);
	void Op_TAX(USHORT src);

	void Op_TAY(USHORT src);
	void Op_TSX(USHORT src);
	void Op_TXA(USHORT src);
	void Op_TXS(USHORT src);
	void Op_TYA(USHORT src);

	void Op_ILLEGAL(USHORT src);
	//--------------------------------------
	// Little Utility Methods
	//--------------------------------------
	// Status Register Bits
	//--------------------------------------
	void SetNegative(BOOL b) {
		b ? (m_SR |= UCHAR(SR::NEGATIVE)) :( m_SR &= ~UCHAR(SR::NEGATIVE));
	}
	void SetOverflow(BOOL b) {
		b ? (m_SR |= UCHAR(SR::OVERFLOWING)) : (m_SR &= ~UCHAR(SR::OVERFLOWING));
	}
	void SetDecimal(BOOL b) {
		b ? (m_SR |= UCHAR(SR::DECIMAL)) : (m_SR &= ~UCHAR(SR::DECIMAL));
	}
	void SetInterrupt(BOOL b) {
		b ? (m_SR |= UCHAR(SR::DECIMAL)) : (m_SR &= ~UCHAR(SR::DECIMAL));
	}
	void SetZero(BOOL b) {
		b ? (m_SR |= UCHAR(SR::ZERO)) : (m_SR &= ~UCHAR(SR::ZERO));
	}
	void SetCarry(BOOL b) {
		b ? (m_SR |= UCHAR(SR::CARRY)) : (m_SR &= ~UCHAR(SR::CARRY));
	}
	//----------------------------------------------
	// Test Status Regiter Bits
	//----------------------------------------------
	BOOL IsNegative() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::NEGATIVE)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsOverflow() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::OVERFLOWING)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsConstant() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::CONSTANT)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsBreak() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::BREAK)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsDecimal() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::DECIMAL)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsInterrupt() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::INTERRUPT)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsZero() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::ZERO)) ? TRUE : FALSE;
		return rV;
	}
	BOOL IsCarry() {
		BOOL rV;
		rV = (m_SR & UCHAR(SR::CARRY)) ? TRUE : FALSE;
		return rV;
	}
};
