#include "Person.h"
#include <iostream>
#include <string.h>
using namespace std;

int GetSSN(Person * p)
{
	return p->ssn;
}

void ShowPerInfo(Person * p)
{
	cout << "�ֹε�Ϲ�ȣ:" << p->ssn << endl;
	cout << "�̸�:" << p->name << endl;
	cout << "�ּ�:" << p->addr << endl;
}

Person * MakePersonData(int ssn, const char * name, const char * addr)
{
	Person* newP = new Person;
	newP->ssn = ssn;
	strcpy_s(newP->addr, addr);
	strcpy_s(newP->name, name);

	return newP;

}
