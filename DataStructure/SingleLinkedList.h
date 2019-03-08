#pragma once


template <typename T>
class SingleLinkedListNode
{
	template <typename T>
	friend class SingleLinkedList;

	template <typename T>
	friend class SingleLinkedListIterator;

private:
	SingleLinkedListNode()
	{
		m_pNext = nullptr;
	}
	~SingleLinkedListNode()
	{

	}

private:
	T m_Data;
	SingleLinkedListNode<T>*  m_pNext;
};

template <typename T>
class SingleLinkedListIterator
{
	template <typename T>
	friend class SingleLinkedList;

private:
	typedef SingleLinkedListNode<T>*  PNODE;

public:
	SingleLinkedListIterator()
	{
		m_pNode = nullptr;
	}
	~SingleLinkedListIterator()
	{

	}
	void operator++(void)
	{
		m_pNode = m_pNode->m_pNext;
	}
	void operator++(int)
	{
		m_pNode = m_pNode->m_pNext;
	}
	bool operator==(const SingleLinkedListIterator& rhs)const 
	{
		return m_pNode == rhs.m_pNode;
	}
	bool operator !=(const SingleLinkedListIterator& rhs)const 
	{
		return m_pNode != rhs.m_pNode;
	}
	T& operator *(void)
	{
		return m_pNode->m_Data;
	}

	
private:

	PNODE m_pNode;

};
template <typename T>
class SingleLinkedList
{
public:
	SingleLinkedList()
	{
		m_Begin = new NODE;
		m_End = new NODE;

		m_Begin->m_pNext = m_End;
		
	}

	~SingleLinkedList()
	{
		PNODE pDelNode;
		PNODE pCurNode = m_Begin->m_pNext;

		while (pCurNode != m_End)
		{
			pDelNode = pCurNode;
			pCurNode = pCurNode->m_pNext;
			
			delete pDelNode;

		}
		delete m_Begin;
		delete m_End;
	}

	void Push_Front(const T& Data)
	{
		PNODE NewNode = new NODE;
		NewNode->m_Data = Data;

		NewNode->m_pNext = m_Begin->m_pNext;
		m_Begin->m_pNext = NewNode;

		++m_iSize;
	}
	bool IsEmpty(void) const
	{
		return 0 == m_iSize;
	}

	int Size(void)const
	{
		return m_iSize;
	}
public:
	typedef SingleLinkedListIterator<T> Iterator;

	Iterator begin() const
	{
		Iterator RtnIter;
		RtnIter.m_pNode = m_Begin->m_pNext;
		return RtnIter;
	}
	Iterator end() const 
	{
		Iterator RtnIter;
		RtnIter.m_pNode = m_End;
		return RtnIter;
	}

private:
	typedef SingleLinkedListNode<T>* PNODE;
	typedef SingleLinkedListNode<T> NODE;

private:
	PNODE m_Begin;
	PNODE m_End;
	int m_iSize;


};



