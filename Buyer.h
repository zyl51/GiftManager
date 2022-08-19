#pragma once
#include <iostream>
#include "SaleRecords.h"

using namespace std;

const int MEMBER = 2000;//消费超过这个金额可以成为会员

//实现顾客的类定义
class Buyer
{
private:
	string name;//买者的姓名
	string phone;//买者的电话号码
	bool isMember;//是否是会员
	double money;//消费金额,消费金额达到2000成为会员

public:
	Buyer();//无参构造
	Buyer(string name, string phone);//有参构造名字和电话号码
	//有参构造姓名，手机号码，是否会员，消费金额
	Buyer(string name, string phone, bool isMember, double money);
	~Buyer();

	friend ostream& operator << (ostream& os, const Buyer& t);//重载顾客类的输出

	string getName();//获取顾客姓名
	void setName(string name);//修改姓名

	string getPhone();//获取手机号码
	void setPhone(string phone);//修改手机号码

	bool getIsMember();//获取他是不是会员
	void setIsMember(bool sign);//修改会员

	double getMoney();//获得顾客消费金额
	void setMoney(double money);//修改顾客金额
};