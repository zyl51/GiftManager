#pragma once
#include <iostream>
#include "SaleRecords.h"

using namespace std;

class Gift
{
private:
	string number;//礼品编号
	string name;//礼品名称
	double cost;//进价成本
	double price;//售卖价格
	int amount;//产品数量

public:
	Gift();//无参构造
	//有参构造礼品编号，礼品名称，进价，售价，数量
	Gift(string number, string name, double cost, double price, int amount);
	~Gift();

	//重载礼品的输出
	friend ostream& operator << (ostream& os, const Gift& gift);

	string getNumber();//获取礼品编号
	void setNumber(string number);//修改礼品编号

	string getName();//获取礼品名称
	void setName(string name);//修改礼品名称

	double getCost();//获取礼品进价
	void setCost(double cost);//修改进价成本

	double getPrice();//获取礼品售价
	void setPrice(double price);//修改售卖价格

	int getAmount();//获取礼品数量
	void setAmount(int amount);//修改礼品的数量
};