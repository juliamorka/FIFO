#pragma once
#include "global.h"
#define FQUEUE_OVERFLOW 0x01 //pierwszy bit
#define FQUEUE_IS_EMPTY 0x02 //drugi bit
#define OTHER_FQUEUE_ERROR 0x08 //czwarty bit
class FQueue;
class FQueueException
{
public:
	FQueueException(int errCode = OTHER_FQUEUE_ERROR);
	const char* getReason();
private:
	int m_ErrCode;
};
class FQItem
{
	friend class FQueue;
private:
	inline FQItem(FQINFO* info);
	inline virtual ~FQItem();
	FQINFO* pInfo;
	FQItem* pNext;
};

//inline konstr i destr.
inline FQItem::FQItem(FQINFO* info)
{
	pInfo = info;
	pNext = NULL;
}
inline FQItem::~FQItem()
{
	/*delete pInfo;
	if (pNext) delete pNext; */
}

class FQueue
{
public:
	//konstr i destr.
	FQueue();
	~FQueue();
	bool FQEmpty();
	void FQEnqueue(FQINFO* info);
	FQINFO* FQDequeue();
	void FQClear();
	void FQPrintQueue();
private:
	void FQDel();
private:
	//wsk na pierwszy i ostatni m_pHead i m_pTail
	FQItem* m_pHead;
	FQItem* m_pTail;
};
inline FQueueException::FQueueException(int errCode)
{
	m_ErrCode = errCode;
}
inline const char* FQueueException::getReason()
{
	switch (m_ErrCode)
	{
	case FQUEUE_OVERFLOW: return "ERROR: FQueue overflow!";
	case FQUEUE_IS_EMPTY: return "ERROR: FQueue is empty!";
	default: return "ERROR: FQueue error!";
	}
}