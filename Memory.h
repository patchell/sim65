#pragma once

class CMemory : public CPeripheral
{
	UCHAR* m_pData;
	UINT m_StartAddress;
	UINT m_Size;
public:
	CMemory();
	virtual ~CMemory();
	BOOL Create(UINT Address, UINT Size);
	UCHAR GetData(UINT Address);
	void SetData(UINT Address, UCHAR Data);
};

