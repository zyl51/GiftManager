#include "Gift.h"
#include <iomanip>

Gift::Gift()
{
	number = "null";//��Ʒ���
	name = "null";//��Ʒ����
	cost = 0;//���۳ɱ�
	price = 0;//�����۸�
	amount = 0;//��Ʒ����
}

Gift::Gift(string number, string name, double cost, double price, int amount)
{
	this->number = number;
	this->name = name;
	this->cost = cost;
	this->price = price;
	this->amount = amount;
}

Gift::~Gift()
{

}

ostream& operator << (ostream& os, const Gift& gift)
{
	os.setf(ios::left);
	os << setw(15) << gift.number << setw(15) << gift.name << setw(15) << setiosflags(ios::fixed) << setprecision(2)
		<< gift.cost << setw(15) << gift.price << setw(15) << gift.amount;
	os.unsetf(ios::left);
	return os;
}

string Gift::getNumber()
{
	return number;
}

void Gift::setNumber(string number)
{
	this->number = number;
}

string Gift::getName()
{
	return name;
}
void Gift::setName(string name)
{
	this->name = name;
}

double Gift::getCost()
{
	return cost;
}

void Gift::setCost(double cost)
{
	this->cost = cost;
}

double Gift::getPrice()
{
	return price;
}

void Gift::setPrice(double price)
{
	this->price = price;
}

int Gift::getAmount()
{
	return amount;
}

void Gift::setAmount(int amount)
{
	this->amount = amount;
}