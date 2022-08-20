#include "SaleRecords.h"
#include <iomanip>

SaleRecords::SaleRecords()
{

}

SaleRecords::SaleRecords(string name, string phone, string giftName, 
	string number, double cost, double price, double actualPrice, int amount, Date date)
{
	this->name = name;
	this->phone = phone;
	this->giftName = giftName;
	this->number = number;
	this->cost = cost;
	this->price = price;
	this->actualPrice = actualPrice;
	this->amount = amount;
	this->date = date;
}

SaleRecords::~SaleRecords()
{

}

ostream& operator << (ostream& os, const SaleRecords& t)
{//输出某条销售记录
	os.setf(ios::left);
	os << setw(15) << t.name << setw(15) << t.phone << setw(15) << t.giftName << setw(15) << t.number <<
		setw(15) << setiosflags(ios::fixed) << setprecision(2) << t.cost << setw(15) << t.price << setw(15)
		<< t.actualPrice << setw(15) << t.amount << setw(15) << t.date;
	os.unsetf(ios::left);
	return os;
}

string SaleRecords::getName()
{//获取顾客的姓名
	return name;
}

void SaleRecords::setName(string name)
{
	this->name = name;
}

string SaleRecords::getPhone()
{
	return phone;
}

void SaleRecords::setPhone(string phone)
{
	this->phone = phone;
}

string SaleRecords::getGiftName()
{
	return giftName;
}

string SaleRecords::getNumber()
{
	return number;
}

double SaleRecords::getCost()
{
	return cost;
}

double SaleRecords::getPrice()
{
	return price;
}

double SaleRecords::getActualPrice()
{
	return actualPrice;
}

int SaleRecords::getAmount()
{
	return amount;
}
