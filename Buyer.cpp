#include "Buyer.h"
#include <iomanip>

Buyer::Buyer() 
{//实现顾客的无参构造
	this->name = "null";
	this->phone = "null";
	this->isMember = false;
	this->money = 0;
}

Buyer::Buyer(string name, string phone)
{
	this->name = name;
	this->phone = phone;
	this->isMember = false;
	this->money = 0;
}

Buyer::Buyer(string name, string phone, bool isMember, double money)
{
	this->name = name;
	this->phone = phone;
	this->isMember = isMember;
	this->money = money;
}

Buyer::~Buyer() 
{

}

ostream& operator << (ostream& os, const Buyer& t)
{
	os.setf(ios::left);
	os << setw(15) << t.name << setw(15) << t.phone << setw(15) << (t.isMember ? "是" : "否") 
		<< setw(15) << setiosflags(ios::fixed) << setw(15) << setprecision(2) << t.money;
	os.unsetf(ios::left);
	return os;
}

bool Buyer::getIsMember()
{
	return isMember;
}

string Buyer::getName()
{
	return name;
}

void Buyer::setName(string name)
{
	this->name = name;
}

string Buyer::getPhone()
{
	return phone;
}

void Buyer::setPhone(string phone)
{
	this->phone = phone;
}

void Buyer::setIsMember(bool sign)
{
	this->isMember = sign;
}

double Buyer::getMoney()
{
	return money;
}

void Buyer::setMoney(double money)
{
	if (money >= MEMBER)
		setIsMember(true);
	this->money = money;
}