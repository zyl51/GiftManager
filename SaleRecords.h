#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

class SaleRecords
{
private:
	string name;//人名
	string phone;//电话号码
	string giftName;//礼品名称
	string number;//礼品编号
	double cost;//成本
	double price;//礼品售价
	double actualPrice;//实际售价
	int amount;//销售的数量
	Date date;//出售日期

public:
	SaleRecords();//无参构造
	//有参构造顾客姓名，手机号码，顾客礼品名称，礼品编号，进价，售价，数量和日期
	SaleRecords(string name, string phone, string giftName, string number, double cost,
		double price, double actualPrice, int amount, Date date);//构造函数
	~SaleRecords();//析构

	//重载输出
	friend ostream& operator << (ostream& os, const SaleRecords& t);//重载输出
	
	string getName();//获取顾客姓名
	void setName(string name);//修改顾客姓名，主要用于修改顾客信息时同步修改

	string getPhone();//获取顾客手机号
	void setPhone(string phone);//修改顾客手机号，主要用于修改顾客信息时同步修改

	string getGiftName();//获取礼品的名称
	string getNumber();//获取礼品的编号

	double getCost();//获取成本
	double getPrice();//获取礼品的售价
	double getActualPrice();//获取礼品的实际售价，因为会员会打折
	int getAmount();//获取购买的数量
};