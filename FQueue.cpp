#include "FQueue.h"
FQueue::FQueue()
{
	m_pHead = m_pTail = NULL;
}
FQueue::~FQueue()
{
	FQClear();
}
bool FQueue::FQEmpty()
{
	return !m_pHead;
}
void FQueue::FQEnqueue(FQINFO* info)
{
	FQItem* pNew = new FQItem(info);
	if (!pNew) throw FQueueException(FQUEUE_OVERFLOW);
	if ( FQEmpty() ) m_pHead = pNew;
	else m_pTail->pNext = pNew;
	m_pTail = pNew;
}
FQINFO* FQueue::FQDequeue()
{
	if( FQEmpty() ) throw FQueueException(FQUEUE_IS_EMPTY);
	FQINFO* pDelInfo = m_pHead->pInfo;
	FQDel();
	return pDelInfo;
}
void FQueue::FQClear()
{
	while ( !FQEmpty() ) //analogicznie jak w liœcie prostej
	{
		delete ( FQDequeue() );
	}
}
void FQueue::FQPrintQueue() 
{
	FQItem* pCurr = m_pHead;
	while (pCurr != m_pTail)
	{
		cout << *(pCurr->pInfo) << endl;
		pCurr = pCurr->pNext;
	}
	cout << *(m_pTail->pInfo);
}
void FQueue::FQDel() //usuwa element nie zwraca z niego informacji
{
	if ( FQEmpty() ) throw FQueueException(FQUEUE_IS_EMPTY);
	FQItem* pDel = m_pHead;
	m_pHead = m_pHead->pNext;
	delete pDel;
	if ( FQEmpty() ) m_pTail = NULL;
}