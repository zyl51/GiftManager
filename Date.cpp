#include "Date.h"
#include <iomanip>

Date::Date()
{//�޲ι���
//Ĭ��ȫ��Ϊ0����������
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::~Date()
{

}

ostream& operator << (ostream& os, const Date& date)
{//�������ڵ����
	os.setf(ios::right);
	os.fill('0');
	os << setw(4) << date.year << "/" << setw(2) << date.month << "/" << setw(2) << date.day;
	os.fill(' ');
	os.unsetf(ios::right);
	return os;
}