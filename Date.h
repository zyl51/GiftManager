#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int year;//年份
	int month;//月份
	int day;//日期

public:
	Date();
	Date(int year, int month, int day);//构造函数
	~Date();

	//重载日期的输出
	friend ostream& operator << (ostream& os, const Date& date);
};