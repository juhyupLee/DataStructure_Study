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
	cout << "주민등록번호:" << p->ssn << endl;
	cout << "이름:" << p->name << endl;
	cout << "주소:" << p->addr << endl;
}

Person * MakePersonData(int ssn, const char * name, const char * addr)
{
	Person* newP = new Person;
	newP->ssn = ssn;
	strcpy_s(newP->addr, addr);
	strcpy_s(newP->name, name);

	return newP;

}
