#pragma once
#include <string.h>
#include "SingleLinkedList.h"
#define SIZE 1000
class UserData
{
public:
	UserData(const char* pName, int regist)
	{
		strcpy_s(m_Name, pName);
		m_RegisterNum = regist;
	}
	UserData()
	{

	}
	UserData(const UserData& rhs)
	{

	}

	int GetRegister() const 
	{
		return m_RegisterNum;
	}
private:
	char m_Name[100];
	int m_RegisterNum;

};
class Slot
{
private:

	typedef UserData Value;
	typedef int Key;

public:
	Slot(Key key, Value Val)
	{
		
		m_Key = key;
		m_pVal = &Val;

	}
	Slot()
	{

	}

	~Slot()
	{
	

	}

	Key GetKey(void) const
	{
		return m_Key;
	}
	Value* GetValue(void)const
	{
		return m_pVal;
	}

private:
	
	Key m_Key;
	Value* m_pVal;

};
class HashTable
{
public:
	HashTable(int(*Func)(int k))
	{
		m_Func = Func;
	}

	~HashTable()
	{

	}

private:

	typedef UserData Value;
	typedef int Key;
public:
	void insert(Key key, Value &value)
	{
		int HashValue = m_Func(key);

		Slot InsertSlot(key, value);

		m_Pair[HashValue].Push_Front(InsertSlot);
	}
	Value* search(Key key)
	{
		int HashValue = m_Func(key); 
		SingleLinkedList<Slot>::Iterator iter;
		SingleLinkedList<Slot>::Iterator iter_end;

		iter_end = m_Pair[HashValue].end();
		for (iter = m_Pair[HashValue].begin(); iter != iter_end; ++iter)
		{
			if (((*iter).GetKey()) == key)
			{
				return (*iter).GetValue();
			}
				
		}
		return nullptr;

	}
private:
	SingleLinkedList<Slot> m_Pair[SIZE];
	int(*m_Func)(int k);

};

